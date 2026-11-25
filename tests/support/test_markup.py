from tests.support.markup import TAGS, draw_html, draw_markdown


def test_a_seed_draws_the_same_texts_each_time() -> None:
    assert draw_html(7, 50) == draw_html(7, 50)
    assert draw_html(7, 50) != draw_html(8, 50)


def test_draws_count_texts_that_nest_tags_around_text() -> None:
    texts = draw_html(7, 200)
    starts = {start for start, _ in TAGS}
    assert len(texts) == 200
    assert any(unit in starts for text in texts for unit in text)
    assert any(unit not in starts for text in texts for unit in text)


def test_leaves_most_texts_with_their_tags_balanced() -> None:
    pairs = dict(TAGS)
    texts = draw_html(7, 1000)

    def balanced(text: tuple[bytes, ...]) -> bool:
        open_tags: list[bytes] = []
        for unit in text:
            if unit in pairs:
                open_tags.append(pairs[unit])
            elif open_tags and unit == open_tags[-1]:
                open_tags.pop()
            elif unit in pairs.values():
                return False
        return not open_tags

    unbalanced = sum(not balanced(text) for text in texts)
    assert 0 < unbalanced < 100


def test_a_seed_draws_the_same_markdown_texts_each_time() -> None:
    assert draw_markdown(7, 50) == draw_markdown(7, 50)
    assert draw_markdown(7, 50) != draw_markdown(8, 50)
    assert draw_markdown(7, 50, legacy=True) == draw_markdown(7, 50, legacy=True)
    assert draw_markdown(7, 50, legacy=True) != draw_markdown(7, 50)


def test_draws_count_markdown_v2_texts_with_entities_and_blockquotes() -> None:
    texts = draw_markdown(7, 200)
    units = {unit for text in texts for unit in text}
    assert len(texts) == 200
    assert {b"*", b"__", b"||", b"[", b"![", b">", b"\n>"} <= units


def test_draws_legacy_markdown_without_the_markup_only_markdown_v2_reads() -> None:
    texts = draw_markdown(7, 1000, legacy=True)
    units = {unit for text in texts for unit in text}
    assert len(texts) == 1000
    assert {b"*", b"_", b"`", b"```", b"["} <= units
    assert not units & {b"||", b"![", b"\n>"}
