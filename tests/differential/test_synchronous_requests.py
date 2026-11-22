from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.synchronous_requests import run_request
from tests.support.markup import TAGS, draw_html

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Texts that reach what generated texts may miss: an empty one, one of every tag,
# entities that tie in the sort, and texts at and past the 65,536 code points the
# request takes, in characters of one byte and of two.
_FIXED_TEXTS = (
    (b"",),
    tuple(unit for start, end in TAGS for unit in (start, b"x", end)),
    (b"<i>y", *(b'<a href="t.me/a"><a href="t.me/b">x</a></a>',) * 8, b"</i>"),
    (b"a" * 65_536,),
    (b"a" * 65_537,),
    ("\U000000e9".encode() * 65_536,),
    ("\U000000e9".encode() * 65_537,),
)


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
        cases = [(text, (1,), ()) for text in draw_html(seed, count)]
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
