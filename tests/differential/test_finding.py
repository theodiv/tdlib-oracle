from collections.abc import Callable, Sequence

import pytest

from tdlib_oracle.tdlib.finding import (
    Span,
    find_bank_card_numbers,
    find_bot_commands,
    find_cashtags,
    find_hashtags,
    find_mentions,
    find_tg_urls,
    find_ton_addresses,
    find_urls,
    is_email_address,
)
from tests.support.texts import (
    CARD_UNITS,
    FINDING_UNITS,
    LINK_UNITS,
    TAG_UNITS,
    TON_UNITS,
    draw_texts,
)

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

Find = Callable[[bytes], tuple[Span, ...]]

# Each search that gives spans, and the units its texts draw from first.
_FINDERS: tuple[tuple[str, Find, tuple[bytes, ...]], ...] = (
    ("find_mentions", find_mentions, TAG_UNITS),
    ("find_bot_commands", find_bot_commands, TAG_UNITS),
    ("find_hashtags", find_hashtags, TAG_UNITS),
    ("find_cashtags", find_cashtags, TAG_UNITS),
    ("find_bank_card_numbers", find_bank_card_numbers, CARD_UNITS),
    ("find_ton_addresses", find_ton_addresses, TON_UNITS),
    ("find_tg_urls", find_tg_urls, LINK_UNITS),
)


# Texts that reach what generated texts may leave out: cashtags and bot commands with a
# username too short, long enough, and too long; schemes that start as tonsite does; a
# UnionPay number of prefix 81; IPv4 addresses with a part from 200 to 300; email
# domains with a label that starts or ends off a letter or digit; and email addresses
# after mailto:.
_FIXED_TEXTS = (
    b"$ABC@bot $ABC@ab $ABC@" + b"u" * 33 + b" $ABC@",
    b"/a@bot /a@ab /a@" + b"u" * 33,
    b"tonsXte://a tonsiXe://a tonsitX://a tonsite://a",
    b"8100000000000002 810000000000000",
    b"240.1.1.1 250.1.1.1 255.1.1.1 256.1.1.1 260.1.1.1 300.1.1.1",
    b"a@_b.cd a@-b.cd a@b_.cd a@b-.cd",
    b"mailto:a@b.com mailto:a@b.c",
)

# Email addresses whose domain label starts or ends off a letter or digit, and one that
# is valid.
_FIXED_EMAILS = (b"a@_b.cd", b"a@-b.cd", b"a@b_.cd", b"a@b-.cd", b"a@b.cd")


def _spans(spans: Sequence[Span]) -> tuple[bytes, ...]:
    return tuple(str(bound).encode() for span in spans for bound in span)


def _urls(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    fields: list[bytes] = []
    for span, is_email in find_urls(text):
        fields.extend((*_spans((span,)), b"1" if is_email else b"0"))
    return tuple(fields)


def _cases(
    seed: int, count: int, units: tuple[bytes, ...]
) -> list[tuple[tuple[bytes, ...], tuple[int, ...]]]:
    """Return `count` texts from `units` and as many from every finder's units."""
    texts = draw_texts(seed, count, units)
    texts += draw_texts(seed + 1, count, FINDING_UNITS)
    return [(text, ()) for text in texts]


def _fixed_cases(
    texts: Sequence[bytes],
) -> list[tuple[tuple[bytes, ...], tuple[int, ...]]]:
    """Return `texts` split into bytes, which the shrinking removes one by one."""
    return [(tuple(bytes([c]) for c in text), ()) for text in texts]


@pytest.mark.parametrize(
    ("function", "find", "units"), _FINDERS, ids=[name for name, _, _ in _FINDERS]
)
def test_finder_gives_the_pinned_spans(
    compare: Compare,
    seeds: tuple[int, ...],
    count: int,
    function: str,
    find: Find,
    units: tuple[bytes, ...],
) -> None:
    for seed in seeds:
        compare(
            function,
            lambda text, args: _spans(find(text)),
            _cases(seed, count, units),
            seed=seed,
            by_bytes=False,
        )


def test_find_urls_gives_the_pinned_links_and_email_addresses(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        compare(
            "find_urls",
            _urls,
            _cases(seed, count, LINK_UNITS),
            seed=seed,
            by_bytes=False,
        )


def test_is_email_address_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        compare(
            "is_email_address",
            lambda text, args: (b"1" if is_email_address(text) else b"0",),
            _cases(seed, count, LINK_UNITS),
            seed=seed,
            by_bytes=False,
        )


@pytest.mark.parametrize(
    ("function", "find", "units"), _FINDERS, ids=[name for name, _, _ in _FINDERS]
)
def test_finder_gives_the_pinned_spans_for_the_fixed_texts(
    compare: Compare, function: str, find: Find, units: tuple[bytes, ...]
) -> None:
    compare(
        function,
        lambda text, args: _spans(find(text)),
        _fixed_cases(_FIXED_TEXTS),
        seed=None,
        by_bytes=False,
    )


def test_find_urls_gives_the_pinned_links_for_the_fixed_texts(
    compare: Compare,
) -> None:
    compare("find_urls", _urls, _fixed_cases(_FIXED_TEXTS), seed=None, by_bytes=False)


def test_is_email_address_gives_the_pinned_result_for_the_fixed_addresses(
    compare: Compare,
) -> None:
    compare(
        "is_email_address",
        lambda text, args: (b"1" if is_email_address(text) else b"0",),
        _fixed_cases(_FIXED_EMAILS),
        seed=None,
        by_bytes=False,
    )
