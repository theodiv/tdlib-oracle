import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.synchronous_requests import run_request
from tests.support.texts import INVALID_UNITS, PLAIN_UNITS

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Pairs of tags, each with the values its attributes tell apart: every tag the parser
# supports, links to keep, to drop, and to valid and invalid users, custom emoji IDs
# valid and not, and dates of each format, valid and not.
_TAGS = (
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

# Texts that reach what generated texts may miss: an empty one, one of every tag,
# entities that tie in the sort, and texts at and past the 65,536 code points the
# request takes, in characters of one byte and of two.
_FIXED_TEXTS = (
    (b"",),
    tuple(unit for start, end in _TAGS for unit in (start, b"x", end)),
    (b"<i>y", *(b'<a href="t.me/a"><a href="t.me/b">x</a></a>',) * 8, b"</i>"),
    (b"a" * 65_536,),
    (b"a" * 65_537,),
    ("\U000000e9".encode() * 65_536,),
    ("\U000000e9".encode() * 65_537,),
)


def _draw_markup(rng: random.Random, depth: int) -> list[bytes]:
    """Return the units of up to four parts, each text or a pair of tags around more."""
    units: list[bytes] = []
    for _ in range(rng.randint(0, 4)):
        if depth < 4 and rng.random() < 0.4:
            start, end = rng.choice(_TAGS)
            units += [start, *_draw_markup(rng, depth + 1), end]
        else:
            units.append(rng.choice(_CONTENT))
    return units


def _draw_html(seed: int, count: int) -> list[tuple[bytes, ...]]:
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


def _run_request(
    text: bytes, args: tuple[int, ...], entities: tuple[object, ...]
) -> tuple[tuple[bytes, ...], tuple[td_api.TextEntity | None, ...]]:
    parse_mode = td_api.TextParseModeHTML() if args[0] else None
    result = run_request(td_api.ParseTextEntities(text, parse_mode))
    if isinstance(result, td_api.Error):
        return (str(result.code).encode(), result.message, b""), ()
    return (b"0", b"", result.text), result.entities


def test_run_request_gives_the_pinned_answer_to_parse_text_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (1,), ()) for text in _draw_html(seed, count)]
        compare_entities(
            "run_request", _run_request, cases, seed=seed, by_bytes=False, answers="api"
        )


def test_run_request_gives_the_pinned_answer_on_the_fixed_texts(
    compare_entities: Compare,
) -> None:
    cases = [
        (text, (parse_mode,), ()) for text in _FIXED_TEXTS for parse_mode in (1, 0)
    ]
    compare_entities(
        "run_request", _run_request, cases, seed=None, by_bytes=False, answers="api"
    )
