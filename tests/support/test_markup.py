from tests.support.markup import TAGS, draw_html


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
