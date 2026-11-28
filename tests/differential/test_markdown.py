import random
from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    FormattedText,
    MessageEntity,
    parse_markdown,
    parse_markdown_v2,
)
from tests.support.markup import draw_markdown

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

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


def _draw_broken_markdown(
    seed: int, count: int, *, legacy: bool = False
) -> list[tuple[bytes, ...]]:
    """Return `count` Markdown texts from `seed`, with up to three bytes broken."""
    rng = random.Random(f"{seed} broken {'legacy ' if legacy else ''}markdown")
    breaks = _LEGACY_BREAKS if legacy else _BREAKS
    texts = []
    for units in draw_markdown(seed, count, legacy=legacy):
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
        cases = [(text, (), ()) for text in draw_markdown(seed, count, legacy=True)]
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
        cases = [(text, (), ()) for text in draw_markdown(seed, count)]
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
