from dataclasses import replace

from tdlib_oracle.tdlib.entities import TYPE, MessageEntity, sort_entities

_LINK = MessageEntity(TYPE.TEXT_URL, 1, 3, b"t.me")
_MENTION = MessageEntity(TYPE.MENTION_NAME, 1, 3, user_id=7)


def test_sorts_by_offset_then_the_longer_entity_first_then_by_type_priority() -> None:
    entities = (
        MessageEntity(TYPE.ITALIC, 2, 1),
        MessageEntity(TYPE.ITALIC, 0, 1),
        MessageEntity(TYPE.BOLD, 0, 1),
        MessageEntity(TYPE.CODE, 0, 3),
    )
    assert sort_entities(entities) == (
        MessageEntity(TYPE.CODE, 0, 3),
        MessageEntity(TYPE.BOLD, 0, 1),
        MessageEntity(TYPE.ITALIC, 0, 1),
        MessageEntity(TYPE.ITALIC, 2, 1),
    )


def test_puts_a_blockquote_before_the_entities_it_starts_with() -> None:
    quote = MessageEntity(TYPE.BLOCK_QUOTE, 0, 2)
    pre = MessageEntity(TYPE.PRE, 0, 2)
    assert sort_entities((pre, quote)) == (quote, pre)


def test_marks_each_entity_of_a_tie_between_entities_that_differ() -> None:
    bold = MessageEntity(TYPE.BOLD, 0, 1)
    tie = (_LINK, _MENTION)
    assert sort_entities((_LINK, _MENTION, bold)) == (
        bold,
        replace(_LINK, ties=tie),
        replace(_MENTION, ties=tie),
    )


def test_keeps_the_input_order_within_a_tie() -> None:
    bold = MessageEntity(TYPE.BOLD, 0, 1)
    tie = (_MENTION, _LINK)
    assert sort_entities((_MENTION, _LINK, bold)) == (
        bold,
        replace(_MENTION, ties=tie),
        replace(_LINK, ties=tie),
    )


def test_marks_a_tie_between_entities_that_differ_in_value_only() -> None:
    other = replace(_LINK, argument=b"a")
    bold = MessageEntity(TYPE.BOLD, 0, 1)
    tie = (_LINK, other)
    assert sort_entities((_LINK, other, bold))[1:] == (
        replace(_LINK, ties=tie),
        replace(other, ties=tie),
    )


def test_lists_each_entity_of_a_tie_once() -> None:
    bold = MessageEntity(TYPE.BOLD, 0, 1)
    tie = (_LINK, _MENTION)
    assert sort_entities((_LINK, _MENTION, _LINK, bold)) == (
        bold,
        replace(_LINK, ties=tie),
        replace(_MENTION, ties=tie),
        replace(_LINK, ties=tie),
    )


def test_leaves_a_tie_of_equal_entities_unmarked() -> None:
    bold = MessageEntity(TYPE.BOLD, 0, 1)
    assert sort_entities((_LINK, _LINK, bold)) == (bold, _LINK, _LINK)


def test_returns_entities_in_order_unchanged_and_unmarked_though_tied() -> None:
    entities = (MessageEntity(TYPE.BOLD, 0, 1), _LINK, _MENTION)
    assert sort_entities(entities) == entities


def test_marks_a_tie_in_order_once_another_entity_is_out_of_order() -> None:
    bold = MessageEntity(TYPE.BOLD, 5, 1)
    italic = MessageEntity(TYPE.ITALIC, 4, 1)
    tie = (_LINK, _MENTION)
    assert sort_entities((_LINK, _MENTION, bold, italic)) == (
        replace(_LINK, ties=tie),
        replace(_MENTION, ties=tie),
        italic,
        bold,
    )


def test_returns_no_entities_for_none() -> None:
    assert sort_entities(()) == ()
