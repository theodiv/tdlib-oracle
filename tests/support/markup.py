"""Marked-up texts for the differential tests: HTML and Markdown, drawn from a seed.

A text is a tuple of units, each a whole tag, a whole piece of markup, or a unit of the
text between them, so a differing text shrinks by whole tags and markup before it
shrinks by bytes.
"""

import random
import re

from tests.support.texts import INVALID_UNITS, LINK_UNITS, PLAIN_UNITS

# Pairs of tags, each with the values its attributes tell apart: every tag the parser
# supports, links to keep, to drop, and to valid and invalid users, custom emoji IDs
# valid and not, and dates of each format, valid and not.
TAGS = (
    (b"<b>", b"</b>"),
    (b"<i>", b"</i>"),
    (b"<u>", b"</u>"),
    (b"<s>", b"</s>"),
    (b"<tg-spoiler>", b"</tg-spoiler>"),
    (b'<span class="tg-spoiler">', b"</span>"),
    (b"<code>", b"</code>"),
    (b'<code class="language-python">', b"</code>"),
    (b"<pre>", b"</pre>"),
    (b'<pre><code class="language-python">', b"</code></pre>"),
    (b'<a href="https://t.me/a">', b"</a>"),
    (b'<a href="t.me/b">', b"</a>"),
    (b'<a href="tg://user?id=5">', b"</a>"),
    (b'<a href="tg://user?id=0">', b"</a>"),
    (b'<a href="ftp://t.me">', b"</a>"),
    (b"<a>", b"</a>"),
    (b'<tg-emoji emoji-id="5">', b"</tg-emoji>"),
    (b'<tg-emoji emoji-id="0">', b"</tg-emoji>"),
    (b'<tg-time unix="1700000000" format="tT">', b"</tg-time>"),
    (b'<tg-time unix="1700000000" format="r">', b"</tg-time>"),
    (b'<tg-time unix="1" format="wDd">', b"</tg-time>"),
    (b'<tg-time unix="2">', b"</tg-time>"),
    (b'<tg-time unix="0" format="t">', b"</tg-time>"),
    (b'<tg-time unix="1" format="q">', b"</tg-time>"),
    (b"<blockquote>", b"</blockquote>"),
    (b"<blockquote expandable>", b"</blockquote>"),
)

# The units of the text between tags: characters, references, and byte sequences that
# UTF-8 refuses.
_HTML_CONTENT = (
    *PLAIN_UNITS,
    b"&lt;",
    b"&amp;",
    b"&#x1f600;",
    b"&#xd800;",
    *INVALID_UNITS,
)

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

# MarkdownV2 entities by the units that open them and those that may close them: each
# markup, code blocks without and with a language and with the line breaks they drop,
# links, and custom emoji.
_V2_PAIRS: tuple[tuple[bytes, tuple[bytes, ...]], ...] = (
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
_V2_MARKUP = (
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

# The units of a MarkdownV2 text between entities: characters, links raw and escaped,
# escapes, markup, and byte sequences that UTF-8 refuses.
_V2_CONTENT = tuple(
    dict.fromkeys(
        PLAIN_UNITS
        + LINK_UNITS
        + _ESCAPED_LINK_UNITS
        + _ESCAPES
        + _V2_MARKUP
        + INVALID_UNITS
    )
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


def _draw_markup(rng: random.Random, depth: int) -> list[bytes]:
    """Return the units of up to four parts, each text or a pair of tags around more."""
    units: list[bytes] = []
    for _ in range(rng.randint(0, 4)):
        if depth < 4 and rng.random() < 0.4:
            start, end = rng.choice(TAGS)
            units += [start, *_draw_markup(rng, depth + 1), end]
        else:
            units.append(rng.choice(_HTML_CONTENT))
    return units


def draw_html(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` HTML texts drawn from `seed`, each split into tags and text.

    Tags nest up to four deep around text, and one text in twenty loses a unit, which
    leaves a tag unclosed or unopened as often as not.
    """
    rng = random.Random(f"{seed} html requests")
    texts = []
    for _ in range(count):
        units = _draw_markup(rng, 0)
        if units and rng.random() < 0.05:
            del units[rng.randrange(len(units))]
        texts.append(tuple(units))
    return texts


def draw_markdown(
    seed: int, count: int, *, legacy: bool = False
) -> list[tuple[bytes, ...]]:
    """Return `count` MarkdownV2 texts drawn from `seed`, each split into units.

    Each text opens entities and closes the innermost one between units of text from a
    few of its content units, opens a blockquote now and then, and closes the entities
    left open at its end, mostly. Half the texts hold eight units or fewer. With
    `legacy`, the texts are legacy Markdown, of its own entities and content units,
    without blockquotes.
    """
    rng = random.Random(f"{seed} {'legacy ' if legacy else ''}markdown")
    pairs, content = (
        (_LEGACY_PAIRS, _LEGACY_CONTENT) if legacy else (_V2_PAIRS, _V2_CONTENT)
    )
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
