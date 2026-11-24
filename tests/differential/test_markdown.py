import random
import re
from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    FormattedText,
    MessageEntity,
    parse_markdown,
    parse_markdown_v2,
)
from tests.support.texts import INVALID_UNITS, LINK_UNITS, PLAIN_UNITS

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The ends of a link: none, so it takes its text as its URL, and URLs of each scheme the
# link check tells apart, to valid and invalid users, refused, empty, with escapes,
# and unclosed.
_LINK_ENDS = (
    b"]",
    b"]",
    b"](https://t.me/a)",
    b"](t.me)",
    b"](TG://USER?ID=5)",
    b"](tg://user?id=5)",
    b"](tg://user?id=0)",
    b"](tg:resolve?domain=a)",
    b"](ton://a)",
    b"](tonsite://a.ton)",
    b"](ftp://t.me)",
    b"](http://a)",
    b"]()",
    b"](t.me/\\)\\\\a)",
    b"](t.me/\\\x7f)",
    b"](a b)",
    b"](t.me",
)

# The ends of a custom emoji: tg://emoji and tg://time URLs, valid, at their bounds, in
# other cases, and refused; another URL; no URL; and an unclosed one.
_EMOJI_ENDS = (
    b"](tg://emoji?id=5)",
    b"](tg://emoji?id=5)",
    b"](TG://EMOJI/?x=1&id=7#id=8)",
    b"](tg://emoji?id=0)",
    b"](tg://emoji?id=9223372036854775808)",
    b"](tg://emoji?x=1)",
    b"](tg://time?unix=1700000000&format=wDT)",
    b"](tg://time?unix=1700000000)",
    b"](tg:time/?format=r&unix=1)",
    b"](tg://time?unix=0)",
    b"](tg://time?unix=2147483648)",
    b"](tg://time?unix=1&format=q)",
    b"](tg://time?format=t)",
    b"](t.me)",
    b"]",
    b"](tg://emoji?id=5",
)

# Entities by the units that open them and those that may close them: each markup, code
# blocks without and with a language and with the line breaks they drop, links, and
# custom emoji.
_PAIRS: tuple[tuple[bytes, tuple[bytes, ...]], ...] = (
    (b"*", (b"*",)),
    (b"_", (b"_",)),
    (b"__", (b"__",)),
    (b"~", (b"~",)),
    (b"||", (b"||",)),
    (b"`", (b"`",)),
    (b"```", (b"```",)),
    (b"```python ", (b"```",)),
    (b"```python\n", (b"```",)),
    (b"```\n", (b"```",)),
    (b"```\r\n", (b"```",)),
    (b"```\n\n", (b"```",)),
    (b"[", _LINK_ENDS),
    (b"![", _EMOJI_ENDS),
)

# The ends of a blockquote: a line break, with a spoiler mark that makes it expandable,
# or the end of the text.
_BLOCKQUOTE_ENDS = (b"\n", b"\r\n", b"||\n", b"||\r\n", b"||", b"")

# Escapes of each character MarkdownV2 reserves and of others; a backslash before NUL,
# DEL, or a character outside ASCII, which escapes nothing; and a backslash alone, which
# escapes what follows it.
_ESCAPES = (
    *(b"\\" + bytes([c]) for c in b"_*[]()~`>#+-=|{}.!\n\r\\a"),
    b"\\\x00",
    b"\\\x7f",
    "\\\U000000e9".encode(),
    b"\\",
)

# The characters MarkdownV2 reserves, alone, and the line breaks that go on with a
# blockquote or end it.
_MARKUP = (
    *(bytes([c]) for c in b"_*[]()~`>#+-=|{}.!"),
    b"\n>",
    b"\r\n>",
    b"\n\r>",
    b"\n\n",
)

# Links with each character MarkdownV2 reserves escaped, so a link without a URL can
# take them as its URL.
_ESCAPED_LINK_UNITS = tuple(
    re.sub(rb"([_*\[\]()~`>#+\-=|{}.!\\])", rb"\\\1", unit) for unit in LINK_UNITS
)

# The units of the text between entities: characters, links raw and escaped, escapes,
# markup, and byte sequences that UTF-8 refuses.
_CONTENT = tuple(
    dict.fromkeys(
        PLAIN_UNITS
        + LINK_UNITS
        + _ESCAPED_LINK_UNITS
        + _ESCAPES
        + _MARKUP
        + INVALID_UNITS
    )
)

# The bytes that break a text: those that open or close an entity, escape, start a URL,
# or end the string, line breaks, and a letter.
_BREAKS = b"\\_*[]()~`>|!\n\r\x00a"

# Pairs around the same text whose entities tie in a sort: links, a link and a mention,
# custom emoji, and dates.
_TIED_PAIRS = (
    (b"[", b"](t.me/a)"),
    (b"[", b"](t.me/b)"),
    (b"[", b"](tg://user?id=5)"),
    (b"![", b"](tg://emoji?id=1)"),
    (b"![", b"](tg://emoji?id=2)"),
    (b"![", b"](tg://time?unix=1&format=t)"),
    (b"![", b"](tg://time?unix=2)"),
)

# Legacy Markdown entities by the units that open them and those that may close them:
# each markup, code blocks without and with a language and with the line breaks they
# drop, and links, with the ends of MarkdownV2's, whose escapes legacy Markdown keeps.
_LEGACY_PAIRS: tuple[tuple[bytes, tuple[bytes, ...]], ...] = (
    (b"*", (b"*",)),
    (b"_", (b"_",)),
    (b"`", (b"`",)),
    (b"```", (b"```",)),
    (b"```python ", (b"```",)),
    (b"```python\n", (b"```",)),
    (b"```\n", (b"```",)),
    (b"```\r\n", (b"```",)),
    (b"```\n\n", (b"```",)),
    (b"[", _LINK_ENDS),
)

# The characters legacy Markdown reads as markup, alone, with the parentheses of a URL,
# and entities around no text, which drop bytes before a link without a URL.
_LEGACY_MARKUP = (*(bytes([c]) for c in b"_*`[]()"), b"**", b"__", b"``")

# The units of a legacy Markdown text between entities: characters, links, escapes,
# markup, and byte sequences that UTF-8 refuses.
_LEGACY_CONTENT = tuple(
    dict.fromkeys(PLAIN_UNITS + LINK_UNITS + _ESCAPES + _LEGACY_MARKUP + INVALID_UNITS)
)

# The bytes that break a legacy Markdown text: those that open or close an entity,
# escape, start or end a URL, or end the string, line breaks, and a letter.
_LEGACY_BREAKS = b"\\_*[]()`\n\r\x00a"

# The examples of the Markdown style in the Bot API's formatting options, and of its
# notes on escaping.
_MARKDOWN_STYLE_EXAMPLES = (
    b"*bold text*",
    b"_italic text_",
    b"[inline URL](http://www.example.com/)",
    b"[inline mention of a user](tg://user?id=123456789)",
    b"`inline fixed-width code`",
    b"```\npre-formatted fixed-width code block\n```",
    b"```python\npre-formatted fixed-width code block written in the Python programming"
    b" language\n```",
)
_MARKDOWN_STYLE_NOTE_EXAMPLES = (b"_snake_\\__case_", b"*2*\\**2=4*")

# Legacy Markdown texts that reach what generated texts may miss: links without a URL
# after no dropped byte, after escapes, after an entity and a link, after more dropped
# bytes than their text holds, and in a row, one naming a user; an empty link; an
# unclosed URL; an escape inside an entity; brackets that open one link; code blocks
# with NUL and backticks; and the Bot API's examples, alone and as the one block the
# page shows them in.
_LEGACY_FIXED_TEXTS = (
    b"",
    b"\\",
    b"`",
    b"```",
    b"[abc]",
    b"[telegram.org]",
    b"x[telegram.org]",
    b"\\_\\_\\_[telegram.org]",
    b"*a*[b](c)[telegram.org]",
    b"****[t.me]",
    b"[t.me]" * 3,
    b"[ttg://user?id=55]",
    b"[](t.me)",
    b"[a](t.me",
    b"_a\\_b_",
    b"[" * 40 + b"t.me" + b"]" * 40,
    b"```\x00a```",
    b"```a\x00b```",
    b"```a``b```",
    b"```a`b`c```",
    *_MARKDOWN_STYLE_EXAMPLES,
    b"\n".join(_MARKDOWN_STYLE_EXAMPLES),
    *_MARKDOWN_STYLE_NOTE_EXAMPLES,
)

# Texts that reach what generated texts may miss.
_FIXED_TEXTS = (
    b"",
    b"\\",
    b"`",
    b"```",
    b"```\x00a```",
    b"```a\x00b```",
    b"```a``b```",
    b"```a`b`c```",
    b">||>\n",
    b"[" * 40 + b"t\\.me" + b"]" * 40,
    b"_y" + b"[[x](t.me/a)](t.me/b)" * 8 + b"_",
)


def _answer(
    result: FormattedText | Failure,
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    if isinstance(result, Failure):
        return (str(result.code).encode(), result.message.encode(), b""), ()
    return (b"0", b"", result.text), result.entities


def _parse_markdown(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return _answer(parse_markdown(text))


def _parse_markdown_v2(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return _answer(parse_markdown_v2(text))


def _draw_markdown(
    seed: int, count: int, *, legacy: bool = False
) -> list[tuple[bytes, ...]]:
    """Return `count` Markdown texts drawn from `seed`, each split into units.

    Each text opens entities and closes the innermost one between units of text from a
    few of `_CONTENT`, opens a blockquote now and then, and closes the entities left
    open at its end, mostly. Half the texts hold eight units or fewer. The texts are
    MarkdownV2, or with `legacy`, legacy Markdown of `_LEGACY_PAIRS` and
    `_LEGACY_CONTENT`, without blockquotes.
    """
    rng = random.Random(f"{seed} {'legacy ' if legacy else ''}markdown")
    pairs, content = (_LEGACY_PAIRS, _LEGACY_CONTENT) if legacy else (_PAIRS, _CONTENT)
    texts = []
    for _ in range(count):
        palette = rng.sample(content, rng.randint(1, 6))
        units: list[bytes] = []
        open_ends: list[tuple[bytes, ...]] = []
        for _ in range(rng.randint(0, 40 if rng.random() < 0.5 else 8)):
            roll = rng.random()
            if roll < 0.27:
                start, ends = rng.choice(pairs)
                units.append(start)
                open_ends.append(ends)
            elif not legacy and roll < 0.3:
                units.append(b"\n>" if units else b">")
                open_ends.append(_BLOCKQUOTE_ENDS)
            elif roll < 0.55 and open_ends:
                units.append(rng.choice(open_ends.pop()))
            else:
                units.append(rng.choice(palette))
        while open_ends and rng.random() < 0.95:
            units.append(rng.choice(open_ends.pop()))
        texts.append(tuple(unit for unit in units if unit))
    return texts


def _draw_broken_markdown(
    seed: int, count: int, *, legacy: bool = False
) -> list[tuple[bytes, ...]]:
    """Return `count` Markdown texts drawn from `seed`, with up to three bytes broken.

    A text of `_draw_markdown` loses a byte, gains one of `_BREAKS`, or has one replaced
    by one, up to three times, so its entities and escapes break at any byte. The bytes
    come back one per unit. With `legacy`, the texts are legacy Markdown, broken
    with `_LEGACY_BREAKS`.
    """
    rng = random.Random(f"{seed} broken {'legacy ' if legacy else ''}markdown")
    breaks = _LEGACY_BREAKS if legacy else _BREAKS
    texts = []
    for units in _draw_markdown(seed, count, legacy=legacy):
        text = bytearray(b"".join(units))
        for _ in range(rng.randint(1, 3)):
            pos = rng.randint(0, len(text))
            match rng.randrange(3):
                case 0:
                    del text[pos : pos + 1]
                case 1:
                    text.insert(pos, rng.choice(breaks))
                case _:
                    text[pos : pos + 1] = bytes([rng.choice(breaks)])
        texts.append(tuple(bytes([c]) for c in text))
    return texts


def _draw_ties(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` texts drawn from `seed` whose entities tie in the sort.

    An italic opens before the first tied pair, so the entities come out of order, and
    up to 14 pairs of entities nest around a character each: up to 29 entities, past the
    16 above which libstdc++'s sort may reorder ties.
    """
    rng = random.Random(f"{seed} markdown ties")
    texts = []
    for _ in range(count):
        units = [b"_", b"y"]
        for _ in range(rng.randint(1, 14)):
            outer = rng.choice(_TIED_PAIRS)
            inner = rng.choice(_TIED_PAIRS)
            units += [outer[0], inner[0], b"x", inner[1], outer[1]]
        units.append(b"_")
        texts.append(tuple(units))
    return texts


def test_parse_markdown_gives_the_pinned_result(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_markdown(seed, count, legacy=True)]
        compare_entities(
            "parse_markdown", _parse_markdown, cases, seed=seed, by_bytes=True
        )


def test_parse_markdown_gives_the_pinned_result_on_broken_markdown(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [
            (text, (), ()) for text in _draw_broken_markdown(seed, count, legacy=True)
        ]
        compare_entities(
            "parse_markdown", _parse_markdown, cases, seed=seed, by_bytes=True
        )


def test_parse_markdown_gives_the_pinned_result_on_the_fixed_texts(
    compare_entities: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in text), (), ()) for text in _LEGACY_FIXED_TEXTS]
    compare_entities("parse_markdown", _parse_markdown, cases, seed=None, by_bytes=True)


def test_parse_markdown_v2_gives_the_pinned_result(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_markdown(seed, count)]
        compare_entities(
            "parse_markdown_v2", _parse_markdown_v2, cases, seed=seed, by_bytes=True
        )


def test_parse_markdown_v2_gives_the_pinned_result_on_broken_markdown(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_broken_markdown(seed, count)]
        compare_entities(
            "parse_markdown_v2", _parse_markdown_v2, cases, seed=seed, by_bytes=True
        )


def test_parse_markdown_v2_gives_the_pinned_result_for_tied_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_ties(seed, count)]
        compare_entities(
            "parse_markdown_v2", _parse_markdown_v2, cases, seed=seed, by_bytes=False
        )


def test_parse_markdown_v2_gives_the_pinned_result_on_the_fixed_texts(
    compare_entities: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in text), (), ()) for text in _FIXED_TEXTS]
    compare_entities(
        "parse_markdown_v2", _parse_markdown_v2, cases, seed=None, by_bytes=True
    )
