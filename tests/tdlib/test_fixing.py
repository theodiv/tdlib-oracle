from dataclasses import replace

import pytest

from tdlib_oracle.tdlib.entities import TYPE, FormattedText, MessageEntity
from tdlib_oracle.tdlib.fixing import fix_formatted_text, get_formatted_text
from tdlib_oracle.text.failure import Failure

_NON_EMPTY = Failure(400, "Text must be non-empty")


def _fix(
    text: bytes,
    entities: tuple[MessageEntity, ...] = (),
    *,
    allow_empty: bool = False,
    allow_empty_string: bool = False,
    skip_trim: bool = False,
) -> FormattedText | Failure:
    return fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty_string,
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


@pytest.mark.parametrize(
    "entity",
    [
        MessageEntity(TYPE.BOLD, 0, 0),
        MessageEntity(TYPE.TEXT_URL, 0, 1),
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=0),
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=1 << 40),
        MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1),
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1),
    ],
)
def test_drops_an_empty_entity(entity: MessageEntity) -> None:
    assert _fix(b"abc", (entity,)) == FormattedText(b"abc")


@pytest.mark.parametrize(
    "entity",
    [
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=(1 << 40) - 1),
        MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1, custom_emoji_id=-1),
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1),
    ],
)
def test_keeps_an_entity_whose_value_is_valid(entity: MessageEntity) -> None:
    assert _fix(b"abc", (entity,)) == FormattedText(b"abc", (entity,))


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


def test_get_formatted_text_keeps_blanks_only_when_empty_is_allowed() -> None:
    blank = "\u200b".encode()
    assert get_formatted_text(blank, allow_empty=True, skip_trim=False) == blank
    assert get_formatted_text(blank, allow_empty=False, skip_trim=False) == _NON_EMPTY
