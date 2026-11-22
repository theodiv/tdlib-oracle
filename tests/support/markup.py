"""HTML texts for the differential tests: tags with values, drawn from a seed.

A text is a tuple of units, each a whole tag or a unit of the text between tags, so a
differing text shrinks by whole tags before it shrinks by bytes.
"""

import random

from tests.support.texts import INVALID_UNITS, PLAIN_UNITS

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
_CONTENT = (*PLAIN_UNITS, b"&lt;", b"&amp;", b"&#x1f600;", b"&#xd800;", *INVALID_UNITS)


def _draw_markup(rng: random.Random, depth: int) -> list[bytes]:
    """Return the units of up to four parts, each text or a pair of tags around more."""
    units: list[bytes] = []
    for _ in range(rng.randint(0, 4)):
        if depth < 4 and rng.random() < 0.4:
            start, end = rng.choice(TAGS)
            units += [start, *_draw_markup(rng, depth + 1), end]
        else:
            units.append(rng.choice(_CONTENT))
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
