from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.synchronous_requests import run_request
from tests.support.markup import TAGS, draw_html, draw_markdown

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The parse modes of a request, each as its kind and its version of Markdown: none,
# HTML, and Markdown of each version TDLib takes and of one it refuses.
_PARSE_MODES = ((0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (2, 3))

# Texts that reach what generated texts may miss: an empty one, one of every tag,
# entities that tie in the sort, in HTML and in MarkdownV2, and texts at and past the
# 65,536 code points the request takes, in characters of one byte and of two.
_FIXED_TEXTS = (
    (b"",),
    tuple(unit for start, end in TAGS for unit in (start, b"x", end)),
    (b"<i>y", *(b'<a href="t.me/a"><a href="t.me/b">x</a></a>',) * 8, b"</i>"),
    (b"_y", *(b"[[x](t.me/a)](t.me/b)",) * 8, b"_"),
    (b"a" * 65_536,),
    (b"a" * 65_537,),
    ("\U000000e9".encode() * 65_536,),
    ("\U000000e9".encode() * 65_537,),
)


def _parse_mode(kind: int, version: int) -> td_api.TextParseMode | None:
    """Return the parse mode of `kind`: none, HTML, or Markdown of `version`."""
    match kind:
        case 0:
            return None
        case 1:
            return td_api.TextParseModeHTML()
        case _:
            return td_api.TextParseModeMarkdown(version)


def _run_request(
    text: bytes, args: tuple[int, ...], entities: tuple[object, ...]
) -> tuple[tuple[bytes, ...], tuple[td_api.TextEntity | None, ...]]:
    request = td_api.ParseTextEntities(text, _parse_mode(args[0], args[1]))
    result = run_request(request)
    if isinstance(result, td_api.Error):
        return (str(result.code).encode(), result.message, b""), ()
    return (b"0", b"", result.text), result.entities


def test_run_request_gives_the_pinned_answer_to_html_texts(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, (1, 0), ()) for text in draw_html(seed, count)]
        compare_entities(
            "run_request", _run_request, cases, seed=seed, by_bytes=False, answers="api"
        )


@pytest.mark.parametrize("version", [1, 2])
def test_run_request_gives_the_pinned_answer_to_markdown_texts(
    compare_entities: Compare, seeds: tuple[int, ...], count: int, version: int
) -> None:
    for seed in seeds:
        texts = draw_markdown(seed, count, legacy=version == 1)
        cases = [(text, (2, version), ()) for text in texts]
        compare_entities(
            "run_request", _run_request, cases, seed=seed, by_bytes=True, answers="api"
        )


def test_run_request_gives_the_pinned_answer_on_the_fixed_texts(
    compare_entities: Compare,
) -> None:
    cases = [(text, mode, ()) for text in _FIXED_TEXTS for mode in _PARSE_MODES]
    compare_entities(
        "run_request", _run_request, cases, seed=None, by_bytes=False, answers="api"
    )
