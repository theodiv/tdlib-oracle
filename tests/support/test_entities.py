import random
from itertools import combinations

from tdlib_oracle.tdlib.message_entity import TYPE, MessageEntity
from tests.support.entities import draw_entities


def _draw(seed: int, count: int, utf16_length: int) -> list[tuple[MessageEntity, ...]]:
    rng = random.Random(seed)
    return [draw_entities(rng, utf16_length) for _ in range(count)]


def test_a_seed_draws_the_same_entities_each_time() -> None:
    assert _draw(7, 50, 10) == _draw(7, 50, 10)
    assert _draw(7, 50, 10) != _draw(8, 50, 10)


def test_drawn_entities_have_known_types_and_no_more_than_the_given_count() -> None:
    rng = random.Random(7)
    lists = [draw_entities(rng, 10, max_count=20) for _ in range(500)]
    assert all(len(entities) <= 20 for entities in lists)
    assert all(
        0 <= entity.type < TYPE.SIZE for entities in lists for entity in entities
    )


def test_some_lists_are_long_enough_for_std_sort_to_reorder_ties() -> None:
    assert any(len(entities) > 16 for entities in _draw(7, 100, 10))


def test_some_lists_hold_a_tie_between_entities_that_differ() -> None:
    def has_tie(entities: tuple[MessageEntity, ...]) -> bool:
        return any(
            (first.offset, first.length, first.type)
            == (second.offset, second.length, second.type)
            and first != second
            for first, second in combinations(entities, 2)
        )

    assert any(has_tie(entities) for entities in _draw(7, 100, 10))


def test_most_lists_keep_every_entity_within_the_text() -> None:
    lists = _draw(7, 500, 10)
    within = [
        entities
        for entities in lists
        if all(
            0 <= entity.offset and entity.offset + entity.length <= 10
            for entity in entities
        )
    ]
    assert len(within) > 0.6 * len(lists)


def test_some_entities_start_or_end_just_past_the_end_of_the_text() -> None:
    entities = [entity for entities in _draw(7, 500, 10) for entity in entities]
    assert any(entity.offset == 11 for entity in entities)
    assert any(
        entity.offset <= 10 < entity.offset + entity.length <= 12 for entity in entities
    )


def test_some_bounds_fall_far_outside_any_text() -> None:
    entities = [entity for entities in _draw(7, 500, 10) for entity in entities]
    assert any(entity.offset > 1_000_000 or entity.offset < 0 for entity in entities)


def test_every_number_fits_in_the_fields_the_harness_reads() -> None:
    entities = [entity for entities in _draw(7, 500, 10) for entity in entities]
    for entity in entities:
        assert -(1 << 31) <= entity.offset < 1 << 31
        assert -(1 << 31) <= entity.length < 1 << 31
        assert -(1 << 31) <= entity.date < 1 << 31
        assert -(1 << 31) <= entity.date_flags < 1 << 31
        assert abs(entity.user_id) < 10**18
        assert abs(entity.custom_emoji_id) < 10**18
