from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    fix_entities,
    fix_formatted_text,
    remove_empty_entities,
)

_NON_EMPTY = Failure(400, "Text must be non-empty")

_LINK = MessageEntity(TYPE.TEXT_URL, 1, 3, b"t.me")
_MENTION = MessageEntity(TYPE.MENTION_NAME, 1, 3, user_id=7)
_BOLD = MessageEntity(TYPE.BOLD, 0, 1)


def _fix(
    text: bytes,
    entities: tuple[MessageEntity, ...] = (),
    *,
    allow_empty: bool = False,
    allow_empty_string: bool = False,
    skip_new_entities: bool = False,
    skip_bot_commands: bool = False,
    skip_trim: bool = False,
) -> FormattedText | Failure:
    return fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty_string,
        skip_new_entities=skip_new_entities,
        skip_bot_commands=skip_bot_commands,
        skip_trim=skip_trim,
    )


def test_refuses_invalid_utf8() -> None:
    assert _fix(b"\xff", allow_empty=True) == Failure(
        400, "Strings must be encoded in UTF-8"
    )


def test_refuses_nothing_but_spaces_and_line_feeds_unless_empty_is_allowed() -> None:
    assert _fix(b" \n ") == _NON_EMPTY
    assert _fix(b" \n ", allow_empty=True) == FormattedText(b"")


def test_refuses_a_text_that_cleaning_empties() -> None:
    assert _fix(b"\r\r") == _NON_EMPTY


def test_trims_spaces_and_line_feeds_at_both_ends() -> None:
    assert _fix(b" \n a b \n ") == FormattedText(b"a b")


def test_keeps_both_ends_when_trimming_is_skipped() -> None:
    assert _fix(b" \n a b \n ", skip_trim=True) == FormattedText(b" \n a b \n ")


def test_keeps_a_multibyte_character_at_the_end_whole() -> None:
    assert _fix("a\U0001f600 ".encode()) == FormattedText("a\U0001f600".encode())


def test_refuses_blank_characters_unless_empty_is_allowed() -> None:
    blank = " \u200b\U000000a0 ".encode()
    assert _fix(blank) == _NON_EMPTY
    assert _fix(blank, allow_empty=True) == FormattedText(b"")
    assert _fix(blank, allow_empty=True, allow_empty_string=True) == FormattedText(
        blank.strip()
    )


@pytest.mark.parametrize("bound", [-1, 1_000_001])
def test_refuses_an_entity_whose_offset_is_out_of_bounds(bound: int) -> None:
    assert _fix(b"abc", (MessageEntity(TYPE.BOLD, bound, 1),)) == Failure(
        400, f"Receive an entity with incorrect offset {bound}"
    )


@pytest.mark.parametrize("bound", [-1, 1_000_001])
def test_refuses_an_entity_whose_length_is_out_of_bounds(bound: int) -> None:
    assert _fix(b"abc", (MessageEntity(TYPE.BOLD, 0, bound),)) == Failure(
        400, f"Receive an entity with incorrect length {bound}"
    )


def test_refuses_invalid_utf8_before_it_checks_the_entities() -> None:
    assert _fix(b"\xff", (MessageEntity(TYPE.BOLD, -1, 1),)) == Failure(
        400, "Strings must be encoded in UTF-8"
    )


def test_refuses_an_entity_that_begins_inside_a_surrogate_pair() -> None:
    assert _fix("\U0001f600".encode(), (MessageEntity(TYPE.BOLD, 1, 1),)) == Failure(
        400, "Entity begins in a middle of a UTF-16 symbol at byte offset 4"
    )


def test_refuses_an_entity_that_ends_inside_a_surrogate_pair() -> None:
    assert _fix("\U0001f600".encode(), (MessageEntity(TYPE.BOLD, 0, 1),)) == Failure(
        400,
        "Entity beginning at UTF-16 offset 0 ends in a middle of a UTF-16 symbol at"
        " byte offset 4",
    )


def test_refuses_an_entity_that_begins_past_the_end() -> None:
    assert _fix(b"ab", (MessageEntity(TYPE.BOLD, 3, 1),)) == Failure(
        400, "Entity begins after the end of the text at UTF-16 offset 3"
    )


def test_refuses_an_entity_that_ends_past_the_end() -> None:
    assert _fix(b"ab", (MessageEntity(TYPE.BOLD, 1, 5),)) == Failure(
        400,
        "Entity beginning at UTF-16 offset 1 ends after the end of the text at UTF-16"
        " offset 6",
    )


_EMPTY_ENTITIES = (
    MessageEntity(TYPE.BOLD, 0, 0),
    MessageEntity(TYPE.TEXT_URL, 0, 1),
    MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=0),
    MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=1 << 40),
    MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1),
    MessageEntity(TYPE.FORMATTED_DATE, 0, 1),
)

_VALID_VALUES = (
    MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=(1 << 40) - 1),
    MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1, custom_emoji_id=-1),
    MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1),
)


@pytest.mark.parametrize("entity", _EMPTY_ENTITIES)
def test_drops_an_empty_entity(entity: MessageEntity) -> None:
    assert _fix(b"abc", (entity,)) == FormattedText(b"abc")


@pytest.mark.parametrize("entity", _VALID_VALUES)
def test_keeps_an_entity_whose_value_is_valid(entity: MessageEntity) -> None:
    assert _fix(b"abc", (entity,)) == FormattedText(b"abc", (entity,))


def test_remove_empty_entities_keeps_the_others_in_their_order() -> None:
    entities = (_VALID_VALUES[2], *_EMPTY_ENTITIES, _VALID_VALUES[0], _BOLD)
    assert remove_empty_entities(entities) == [
        _VALID_VALUES[2],
        _VALID_VALUES[0],
        _BOLD,
    ]


def test_moves_entities_over_the_characters_cleaning_drops() -> None:
    entities = (MessageEntity(TYPE.BOLD, 0, 3), MessageEntity(TYPE.ITALIC, 4, 3))
    assert _fix("a\rb\U00002028c\U00000333d".encode(), entities) == FormattedText(
        b"abcd", (MessageEntity(TYPE.BOLD, 0, 2), MessageEntity(TYPE.ITALIC, 2, 2))
    )


def test_cuts_entities_at_the_trimmed_ends() -> None:
    entities = (MessageEntity(TYPE.ITALIC, 2, 4), MessageEntity(TYPE.BOLD, 5, 1))
    assert _fix(b"  ab  ", entities) == FormattedText(
        b"ab", (MessageEntity(TYPE.ITALIC, 0, 2),)
    )


def test_trims_spaces_at_the_start_only_up_to_the_first_entity() -> None:
    entities = (MessageEntity(TYPE.BOLD, 1, 3),)
    assert _fix(b"  ab", entities) == FormattedText(
        b" ab", (MessageEntity(TYPE.BOLD, 0, 3),)
    )


def test_drops_a_continuous_entity_nested_in_another() -> None:
    link = MessageEntity(TYPE.TEXT_URL, 0, 3, b"t.me")
    entities = (link, MessageEntity(TYPE.CUSTOM_EMOJI, 1, 1, custom_emoji_id=5))
    assert _fix(b"abc", entities) == FormattedText(b"abc", (link,))


def test_splits_a_bold_entity_around_a_link() -> None:
    link = MessageEntity(TYPE.TEXT_URL, 1, 1, b"t.me")
    entities = (MessageEntity(TYPE.BOLD, 0, 3), link)
    assert _fix(b"abc", entities) == FormattedText(
        b"abc",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            link,
            MessageEntity(TYPE.BOLD, 1, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
        ),
    )


def test_keeps_the_first_entity_of_a_tie_and_its_tie() -> None:
    link = MessageEntity(TYPE.TEXT_URL, 0, 3, b"t.me")
    mention = MessageEntity(TYPE.MENTION_NAME, 0, 3, user_id=7)
    bold = MessageEntity(TYPE.BOLD, 1, 1)
    assert _fix(b"abc", (bold, link, mention)) == FormattedText(
        b"abc", (replace(link, ties=(link, mention)), bold)
    )


def test_cuts_a_text_over_35000_bytes_and_drops_the_entities_past_the_cut() -> None:
    text = "\N{EURO SIGN}".encode() * 11670
    kept = MessageEntity(TYPE.ITALIC, 0, 11666)
    entities = (MessageEntity(TYPE.BOLD, 0, 11670), kept)
    assert _fix(text, entities) == FormattedText(text[:34998], (kept,))


def test_splits_a_bold_entity_at_the_bounds_of_a_hashtag_it_finds() -> None:
    entities = (MessageEntity(TYPE.BOLD, 0, 13),)
    assert _fix(b"see #tag here", entities) == FormattedText(
        b"see #tag here",
        (
            MessageEntity(TYPE.BOLD, 0, 4),
            MessageEntity(TYPE.HASHTAG, 4, 4),
            MessageEntity(TYPE.BOLD, 4, 4),
            MessageEntity(TYPE.BOLD, 8, 5),
        ),
    )


def test_finds_no_entities_when_skip_new_entities_is_set() -> None:
    entities = (MessageEntity(TYPE.BOLD, 0, 13),)
    assert _fix(b"see #tag here", entities, skip_new_entities=True) == FormattedText(
        b"see #tag here", entities
    )


def test_finds_bot_commands_unless_skip_bot_commands_is_set() -> None:
    command = MessageEntity(TYPE.BOT_COMMAND, 0, 6)
    assert _fix(b"/start") == FormattedText(b"/start", (command,))
    assert _fix(b"/start", skip_bot_commands=True) == FormattedText(b"/start")


def test_finds_entities_in_the_trimmed_text() -> None:
    assert _fix(b"  #tag  ") == FormattedText(
        b"#tag", (MessageEntity(TYPE.HASHTAG, 0, 4),)
    )


def test_drops_a_found_entity_that_meets_a_continuous_entity() -> None:
    link = MessageEntity(TYPE.TEXT_URL, 0, 6, b"t.me")
    assert _fix(b"see #tag", (link,)) == FormattedText(b"see #tag", (link,))


def test_drops_a_found_entity_that_crosses_a_blockquote() -> None:
    quote = MessageEntity(TYPE.BLOCK_QUOTE, 0, 6)
    assert _fix(b"see #tag", (quote,)) == FormattedText(b"see #tag", (quote,))


def test_keeps_a_found_entity_within_a_blockquote() -> None:
    quote = MessageEntity(TYPE.BLOCK_QUOTE, 0, 8)
    assert _fix(b"see #tag", (quote,)) == FormattedText(
        b"see #tag", (quote, MessageEntity(TYPE.HASHTAG, 4, 4))
    )


def test_fix_entities_returns_valid_entities_in_order() -> None:
    quote = MessageEntity(TYPE.BLOCK_QUOTE, 0, 3)
    pre = MessageEntity(TYPE.PRE, 0, 2)
    code = MessageEntity(TYPE.CODE, 4, 1)
    assert fix_entities((code, pre, quote)) == (quote, pre, code)


def test_fix_entities_returns_no_entities_for_none() -> None:
    assert fix_entities(()) == ()


def test_fix_entities_keeps_the_first_entity_of_a_tie_marked_with_the_tie() -> None:
    assert fix_entities((_LINK, _MENTION, _BOLD)) == (
        _BOLD,
        replace(_LINK, ties=(_LINK, _MENTION)),
    )


def test_fix_entities_keeps_the_input_order_within_a_tie() -> None:
    assert fix_entities((_MENTION, _LINK, _BOLD)) == (
        _BOLD,
        replace(_MENTION, ties=(_MENTION, _LINK)),
    )


def test_fix_entities_marks_a_tie_between_entities_that_differ_in_value_only() -> None:
    other = replace(_LINK, argument=b"a")
    assert fix_entities((_LINK, other, _BOLD)) == (
        _BOLD,
        replace(_LINK, ties=(_LINK, other)),
    )


def test_fix_entities_lists_each_entity_of_a_tie_once() -> None:
    assert fix_entities((_LINK, _MENTION, _LINK, _BOLD)) == (
        _BOLD,
        replace(_LINK, ties=(_LINK, _MENTION)),
    )


def test_fix_entities_leaves_a_tie_of_equal_entities_unmarked() -> None:
    assert fix_entities((_LINK, _LINK, _BOLD)) == (_BOLD, _LINK)


def test_fix_entities_leaves_a_tie_already_in_order_unmarked() -> None:
    assert fix_entities((_BOLD, _LINK, _MENTION)) == (_BOLD, _LINK)


def test_fix_entities_marks_a_tie_in_order_once_another_is_out_of_order() -> None:
    bold = MessageEntity(TYPE.BOLD, 5, 1)
    italic = MessageEntity(TYPE.ITALIC, 4, 1)
    assert fix_entities((_LINK, _MENTION, bold, italic)) == (
        replace(_LINK, ties=(_LINK, _MENTION)),
        italic,
        bold,
    )
