import random
from collections.abc import Callable, Sequence

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.entities import MessageEntity
from tdlib_oracle.tdlib.parsing import parse_html
from tests.support.texts import INVALID_UNITS, LINK_UNITS, PLAIN_UNITS

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The tag names parse_html() supports, some in other cases, which it lowercases.
_TAG_NAMES = (
    b"a",
    b"b",
    b"strong",
    b"i",
    b"em",
    b"s",
    b"strike",
    b"del",
    b"u",
    b"ins",
    b"tg-spoiler",
    b"tg-emoji",
    b"tg-time",
    b"span",
    b"pre",
    b"code",
    b"blockquote",
    b"A",
    b"STRONG",
    b"Tg-Emoji",
    b"BlockQuote",
)

# Tag names parse_html() refuses: another tag, an empty one, one that runs into a slash,
# and one outside ASCII.
_REFUSED_TAG_NAMES = (b"abbr", b"", b"b/", "\U000000e9".encode())

# Links for an href, each scheme the link check tells apart; tg://user links to valid
# users, more often, and invalid ones; links it refuses; and references that decode in
# an attribute.
_LINKS = (
    b"https://t.me/x",
    b"HTTP://T.ME",
    b"t.me",
    b"telegram.org/a?b=c#d",
    b"tg://user?id=5",
    b"tg://user?id=5",
    b"tg://user?id=5",
    b"tg://user?id=1099511627776",
    b"tg://user?id=0",
    b"tg:resolve?domain=a",
    b"ton://a",
    b"tonsite://a.ton",
    b"ftp://t.me",
    b"http://a",
    b"",
    b"t.me/&lt;&amp;",
    b"t.me/&#x41;",
    b"t.me/&#xd800;",
    b"a b",
)

# Classes of code: languages to keep, an empty one, one in capitals, and classes that
# name no language.
_LANGUAGES = (
    b"language-python",
    b"language-python",
    b"language-",
    b"language-PY",
    b"lang-x",
    b"Language-x",
    b"",
)

# Classes of a span: the spoiler, mostly, one in capitals, near misses, and none.
_CLASSES = (
    b"tg-spoiler",
    b"tg-spoiler",
    b"tg-spoiler",
    b"TG-spoiler",
    b"tg-spoilers",
    b"tg-",
    b"spoiler",
    b"",
)

# Custom emoji IDs: valid ones, mostly, at the bounds of a 64-bit integer and past them,
# and texts that read as no ID.
_EMOJI_IDS = (
    b"5",
    b"5",
    b"-5",
    b"9223372036854775807",
    b"9223372036854775808",
    b"0",
    b"05",
    b"+5",
    b"x",
    b"",
)

# Unix times on each side of zero and past 32 bits, and texts that read as
# other numbers.
_UNIX_TIMES = (
    b"1700000000",
    b"1700000000",
    b"1",
    b"0",
    b"-1",
    b"2147483648",
    b"4294967297",
    b"12x",
    b"x",
    b"",
)

# Date formats: of each part, of a relative date, empty, and refused.
_FORMATS = (b"r", b"R", b"wDT", b"tttTTdDwW", b"t", b"T", b"", b"rt", b"q")

# The attributes each tag reads, with the values that tell their readings apart.
_ATTRIBUTES: dict[bytes, tuple[tuple[bytes, tuple[bytes, ...]], ...]] = {
    b"a": ((b"href", _LINKS),),
    b"code": ((b"class", _LANGUAGES),),
    b"span": ((b"class", _CLASSES),),
    b"tg-emoji": ((b"emoji-id", _EMOJI_IDS),),
    b"tg-time": ((b"unix", _UNIX_TIMES), (b"format", _FORMATS)),
    b"blockquote": ((b"expandable", (b"", b"false")),),
}

# Attributes no tag reads, among them names that differ from read ones in case only.
_OTHER_ATTRIBUTES = (
    (b"x", (b"1", b"")),
    (b"HREF", _LINKS),
    (b"Class", _LANGUAGES),
    (b"cite", (b"",)),
    (b",", (b"",)),
)

# What separates the parts of a tag: the characters is_space() reads, NUL aside.
_SPACES = (b" ", b" ", b" ", b"  ", b"\t", b"\n", b"\r", b"\x0b")

# How a start tag ends: mostly as it should; with a space, a slash, or nothing before
# the next unit.
_TAG_ENDS = (b">",) * 30 + (b" >", b"/>", b"")

# References: the four named ones, with and without a semicolon; named ones in other
# cases or unsupported; numeric ones in each base, at and past the last code point, at 9
# and 10 characters, to a surrogate, and to nothing; and an ampersand alone.
_REFERENCES = (
    b"&lt;",
    b"&gt;",
    b"&amp;",
    b"&quot;",
    b"&lt",
    b"&quot",
    b"&LT;",
    b"&nbsp;",
    b"&ltx;",
    b"&#65;",
    b"&#x41;",
    b"&#X41;",
    b"&#65",
    b"&#x1f600;",
    b"&#128512;",
    b"&#1114110;",
    b"&#1114111;",
    b"&#x10fffe;",
    b"&#x10FFFF;",
    b"&#0000065;",
    b"&#00000065;",
    b"&#x000041;",
    b"&#x0000041;",
    b"&#4294967361;",
    b"&#xd83d;",
    b"&#xDE00;",
    b"&#0;",
    b"&#x;",
    b"&#;",
    b"&",
)

# Characters that the parser reads outside tags, a tag's opening among them.
_MARKUP = (b">", b"=", b'"', b"'", b"/", b"&", b"#", b";", b"<")

# The units of the text between tags: characters, links for an <a> without href,
# references, markup, and byte sequences that UTF-8 refuses.
_CONTENT = tuple(
    dict.fromkeys(PLAIN_UNITS + LINK_UNITS + _REFERENCES + _MARKUP + INVALID_UNITS)
)

# The bytes that break a text: those that open, end, or separate the parts of a tag,
# begin or end a reference, or end the string, and a letter.
_BREAKS = b"<>/=\"' \n\x00&#;a"

# Pairs of tags around the same text whose entities tie in a sort: links, a link and a
# mention, custom emoji, dates, and blockquotes.
_TIED_TAGS = (
    (b'<a href="t.me/a">', b"</a>"),
    (b'<a href="t.me/b">', b"</a>"),
    (b'<a href="tg://user?id=5">', b"</a>"),
    (b'<tg-emoji emoji-id="1">', b"</tg-emoji>"),
    (b'<tg-emoji emoji-id="2">', b"</tg-emoji>"),
    (b'<tg-time unix="1" format="t">', b"</tg-time>"),
    (b'<tg-time unix="2">', b"</tg-time>"),
    (b"<blockquote>", b"</blockquote>"),
    (b"<blockquote expandable>", b"</blockquote>"),
)

# Texts that reach what generated texts may miss.
_FIXED_TEXTS = (
    b"",
    b"<",
    b"&",
    b"</",
    b"<i>y" + b'<a href="t.me/a"><a href="t.me/b">x</a></a>' * 8 + b"</i>",
)


def _parse_html(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    result = parse_html(text)
    if isinstance(result, Failure):
        message = result.message.encode("utf-8", "surrogateescape")
        return (str(result.code).encode(), message, b""), ()
    return (b"0", b"", result.text), result.entities


def _attribute(rng: random.Random, name: bytes, value: bytes) -> bytes:
    """Return an attribute of `name` and `value`, quoted, unquoted, or without value."""
    roll = rng.random()
    if roll < 0.05:
        return name
    equals = rng.choice((b"=", b"=", b"=", b" =", b"= ", b" = ", b"\n=\n"))
    if roll < 0.75:
        return name + equals + b'"' + value + b'"'
    if roll < 0.9:
        return name + equals + b"'" + value + b"'"
    return name + equals + value


def _start_tag(rng: random.Random, name: bytes) -> bytes:
    """Return a start tag of `name`, with attributes drawn for it."""
    attributes = [
        attribute
        for attribute in _ATTRIBUTES.get(name.lower(), ())
        if rng.random() < 0.8
    ]
    if rng.random() < 0.15:
        attributes.append(rng.choice(_OTHER_ATTRIBUTES))
    rng.shuffle(attributes)

    parts = [b"<", name]
    for attribute_name, values in attributes:
        parts.append(rng.choice(_SPACES))
        parts.append(_attribute(rng, attribute_name, rng.choice(values)))
    if rng.random() < 0.1:
        parts.append(rng.choice(_SPACES))
    parts.append(rng.choice(_TAG_ENDS))
    return b"".join(parts)


def _end_tag(rng: random.Random, name: bytes) -> bytes:
    """Return an end tag for `name`: its own mostly, empty, or another."""
    roll = rng.random()
    if roll < 0.8:
        return b"</" + name + b">"
    if roll < 0.9:
        return b"</>"
    if roll < 0.94:
        return b"</" + name.upper() + rng.choice(_SPACES) + b">"
    if roll < 0.97:
        return b"</" + rng.choice(_TAG_NAMES) + b">"
    return b"</ " + name + b">"


def _code_block(rng: random.Random, palette: Sequence[bytes]) -> list[bytes]:
    """Return the units of a pre and a code around the same text, in either order."""
    outer, inner = (b"pre", b"code") if rng.random() < 0.5 else (b"code", b"pre")
    text = [rng.choice(palette) for _ in range(rng.randint(1, 3))]
    return [
        _start_tag(rng, outer),
        _start_tag(rng, inner),
        *text,
        b"</" + inner + b">",
        b"</" + outer + b">",
    ]


def _draw_html(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` HTML texts drawn from `seed`, each split into tags and text.

    Each text opens tags and closes the innermost one, mostly by its own name, between
    units of text from a few of `_CONTENT` and now and then a code block, and closes the
    tags left open at its end, mostly. Half the texts hold eight units or fewer.
    """
    rng = random.Random(f"{seed} html")
    texts = []
    for _ in range(count):
        palette = rng.sample(_CONTENT, rng.randint(1, 6))
        units: list[bytes] = []
        open_tags: list[bytes] = []
        for _ in range(rng.randint(0, 40 if rng.random() < 0.5 else 8)):
            roll = rng.random()
            if roll < 0.27:
                if rng.random() < 0.97:
                    name = rng.choice(_TAG_NAMES)
                else:
                    name = rng.choice(_REFUSED_TAG_NAMES)
                units.append(_start_tag(rng, name))
                open_tags.append(name)
            elif roll < 0.3:
                units += _code_block(rng, palette)
            elif roll < 0.55 and open_tags:
                units.append(_end_tag(rng, open_tags.pop()))
            else:
                units.append(rng.choice(palette))
        while open_tags and rng.random() < 0.95:
            units.append(_end_tag(rng, open_tags.pop()))
        texts.append(tuple(units))
    return texts


def _draw_broken_html(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` HTML texts drawn from `seed`, each with up to three bytes broken.

    A text of `_draw_html` loses a byte, gains one of `_BREAKS`, or has one replaced by
    one, up to three times, so its tags and references break at any byte. The bytes come
    back one per unit.
    """
    rng = random.Random(f"{seed} broken html")
    texts = []
    for units in _draw_html(seed, count):
        text = bytearray(b"".join(units))
        for _ in range(rng.randint(1, 3)):
            pos = rng.randint(0, len(text))
            match rng.randrange(3):
                case 0:
                    del text[pos : pos + 1]
                case 1:
                    text.insert(pos, rng.choice(_BREAKS))
                case _:
                    text[pos : pos + 1] = bytes([rng.choice(_BREAKS)])
        texts.append(tuple(bytes([c]) for c in text))
    return texts


def _draw_ties(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` texts drawn from `seed` whose entities tie in the sort.

    An italic opens before the first tied pair, so the entities come out of order, and
    up to 14 pairs of tags nest around a character each: up to 29 entities, past the 16
    above which libstdc++'s sort may reorder ties.
    """
    rng = random.Random(f"{seed} ties")
    texts = []
    for _ in range(count):
        units = [b"<i>", b"y"]
        for _ in range(rng.randint(1, 14)):
            outer = rng.choice(_TIED_TAGS)
            inner = rng.choice(_TIED_TAGS)
            units += [outer[0], inner[0], b"x", inner[1], outer[1]]
        units.append(b"</i>")
        texts.append(tuple(units))
    return texts


def test_parse_html_gives_the_pinned_result(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_html(seed, count)]
        compare_entities("parse_html", _parse_html, cases, seed=seed, by_bytes=True)


def test_parse_html_gives_the_pinned_result_on_broken_html(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_broken_html(seed, count)]
        compare_entities("parse_html", _parse_html, cases, seed=seed, by_bytes=True)


def test_parse_html_gives_the_pinned_result_for_tied_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (), ()) for text in _draw_ties(seed, count)]
        compare_entities("parse_html", _parse_html, cases, seed=seed, by_bytes=False)


def test_parse_html_gives_the_pinned_result_on_the_fixed_texts(
    compare_entities: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in text), (), ()) for text in _FIXED_TEXTS]
    compare_entities("parse_html", _parse_html, cases, seed=None, by_bytes=True)
