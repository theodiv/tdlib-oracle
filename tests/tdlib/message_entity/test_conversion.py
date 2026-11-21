from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    MessageEntity,
    get_formatted_text,
    get_input_message_entities,
    get_message_entities,
    get_text_entities_object,
    get_text_entity_object,
    get_text_entity_type_object,
)

_NON_EMPTY = Failure(400, "Text must be non-empty")

_SHORT = td_api.DateTimePartPrecisionShort()
_NONE = td_api.DateTimePartPrecisionNone()

# More entities than TDLib sends besides custom emoji, the 100 of its limit and one.
_CAP = 101


# Each type a user can set, as an entity and as the API object of its type.
_USER_TYPES = (
    (MessageEntity(TYPE.BOLD, 0, 1), td_api.TextEntityTypeBold()),
    (MessageEntity(TYPE.ITALIC, 0, 1), td_api.TextEntityTypeItalic()),
    (MessageEntity(TYPE.UNDERLINE, 0, 1), td_api.TextEntityTypeUnderline()),
    (MessageEntity(TYPE.STRIKETHROUGH, 0, 1), td_api.TextEntityTypeStrikethrough()),
    (MessageEntity(TYPE.SPOILER, 0, 1), td_api.TextEntityTypeSpoiler()),
    (MessageEntity(TYPE.BLOCK_QUOTE, 0, 1), td_api.TextEntityTypeBlockQuote()),
    (
        MessageEntity(TYPE.EXPANDABLE_BLOCK_QUOTE, 0, 1),
        td_api.TextEntityTypeExpandableBlockQuote(),
    ),
    (MessageEntity(TYPE.CODE, 0, 1), td_api.TextEntityTypeCode()),
    (MessageEntity(TYPE.PRE, 0, 1), td_api.TextEntityTypePre()),
    (
        MessageEntity(TYPE.PRE_CODE, 0, 1, b"python"),
        td_api.TextEntityTypePreCode(b"python"),
    ),
    (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/"),
        td_api.TextEntityTypeTextUrl(b"http://t.me/"),
    ),
    (
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=5),
        td_api.TextEntityTypeMentionName(5),
    ),
    (
        MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1, custom_emoji_id=7),
        td_api.TextEntityTypeCustomEmoji(7),
    ),
    (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=9, date_flags=2 | 32),
        td_api.TextEntityTypeDateTime(
            9, td_api.DateTimeFormattingTypeAbsolute(_SHORT, _NONE, True)
        ),
    ),
)

# Each type a user cannot set, as an entity and as the API object of its type. The
# port's entities carry no media timestamp, which shows as -1.
_OTHER_TYPES = (
    (MessageEntity(TYPE.MENTION, 0, 1), td_api.TextEntityTypeMention()),
    (MessageEntity(TYPE.HASHTAG, 0, 1), td_api.TextEntityTypeHashtag()),
    (MessageEntity(TYPE.BOT_COMMAND, 0, 1), td_api.TextEntityTypeBotCommand()),
    (MessageEntity(TYPE.URL, 0, 1), td_api.TextEntityTypeUrl()),
    (MessageEntity(TYPE.EMAIL_ADDRESS, 0, 1), td_api.TextEntityTypeEmailAddress()),
    (MessageEntity(TYPE.CASHTAG, 0, 1), td_api.TextEntityTypeCashtag()),
    (MessageEntity(TYPE.PHONE_NUMBER, 0, 1), td_api.TextEntityTypePhoneNumber()),
    (
        MessageEntity(TYPE.BANK_CARD_NUMBER, 0, 1),
        td_api.TextEntityTypeBankCardNumber(),
    ),
    (
        MessageEntity(TYPE.MEDIA_TIMESTAMP, 0, 1),
        td_api.TextEntityTypeMediaTimestamp(-1),
    ),
    (MessageEntity(TYPE.TON_ADDRESS, 0, 1), td_api.TextEntityTypeTonAddress()),
)


def _object(entity_type: td_api.TextEntityType) -> td_api.TextEntity:
    return td_api.TextEntity(0, 1, entity_type)


def test_get_formatted_text_keeps_blanks_only_when_empty_is_allowed() -> None:
    blank = "\u200b".encode()
    assert get_formatted_text(blank, allow_empty=True, skip_trim=False) == blank
    assert get_formatted_text(blank, allow_empty=False, skip_trim=False) == _NON_EMPTY


@pytest.mark.parametrize(("entity", "entity_type"), [*_USER_TYPES, *_OTHER_TYPES])
def test_get_text_entity_type_object_gives_each_type_with_its_value(
    entity: MessageEntity, entity_type: td_api.TextEntityType
) -> None:
    assert get_text_entity_type_object(entity) == entity_type


def test_get_text_entity_type_object_shows_a_short_time_over_a_long_one() -> None:
    entity = MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=9, date_flags=2 | 4)
    absolute = td_api.DateTimeFormattingTypeAbsolute(_SHORT, _NONE, False)
    assert get_text_entity_type_object(entity) == (
        td_api.TextEntityTypeDateTime(9, absolute)
    )


def test_get_text_entity_object_converts_the_tie_of_the_entity() -> None:
    first = MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://a/")
    second = MessageEntity(TYPE.MENTION_NAME, 1, 1, user_id=5)
    entity = MessageEntity(TYPE.TEXT_URL, 3, 1, b"http://a/", ties=(first, second))
    assert get_text_entity_object(entity) == td_api.TextEntity(
        3,
        1,
        td_api.TextEntityTypeTextUrl(b"http://a/"),
        ties=(
            td_api.TextEntity(1, 1, td_api.TextEntityTypeTextUrl(b"http://a/")),
            td_api.TextEntity(1, 1, td_api.TextEntityTypeMentionName(5)),
        ),
    )


def test_get_text_entity_object_ends_a_tie_whose_entities_become_one_object() -> None:
    # A short and a long time show as the short one alone.
    first = MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1, date_flags=2)
    second = MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1, date_flags=2 | 4)
    entity = replace(first, ties=(first, second))
    assert get_text_entity_object(entity).ties == ()


def test_get_text_entities_object_keeps_every_entity_in_its_order() -> None:
    entities = (
        MessageEntity(TYPE.ITALIC, 0, 3),
        MessageEntity(TYPE.BOT_COMMAND, 0, 2),
        MessageEntity(TYPE.HASHTAG, 2, 1),
    )
    assert get_text_entities_object(entities) == (
        td_api.TextEntity(0, 3, td_api.TextEntityTypeItalic()),
        td_api.TextEntity(0, 2, td_api.TextEntityTypeBotCommand()),
        td_api.TextEntity(2, 1, td_api.TextEntityTypeHashtag()),
    )


@pytest.mark.parametrize(("entity", "entity_type"), _USER_TYPES)
def test_get_message_entities_gives_each_type_a_user_can_set(
    entity: MessageEntity, entity_type: td_api.TextEntityType
) -> None:
    assert get_message_entities((_object(entity_type),)) == (entity,)


@pytest.mark.parametrize(
    "entity_type",
    [
        *(entity_type for _, entity_type in _OTHER_TYPES[:-2]),
        td_api.TextEntityTypeMediaTimestamp(0),
        td_api.TextEntityTypeTonAddress(),
    ],
)
def test_get_message_entities_drops_each_type_a_user_cannot_set(
    entity_type: td_api.TextEntityType,
) -> None:
    assert get_message_entities((_object(entity_type),)) == ()


def test_get_message_entities_keeps_the_types_a_user_can_set() -> None:
    objects = (
        td_api.TextEntity(0, 3, td_api.TextEntityTypeBold()),
        td_api.TextEntity(0, 2, td_api.TextEntityTypeHashtag()),
        td_api.TextEntity(1, 1, td_api.TextEntityTypeMediaTimestamp(5)),
        td_api.TextEntity(2, 1, td_api.TextEntityTypeCustomEmoji(7)),
    )
    assert get_message_entities(objects) == (
        MessageEntity(TYPE.BOLD, 0, 3),
        MessageEntity(TYPE.CUSTOM_EMOJI, 2, 1, custom_emoji_id=7),
    )


def test_get_message_entities_skips_a_null_object_and_a_null_type() -> None:
    assert get_message_entities((None, td_api.TextEntity(0, 1, None))) == ()


def test_get_message_entities_cleans_a_language_and_a_link() -> None:
    objects = (
        _object(td_api.TextEntityTypePreCode(b"py\rthon")),
        _object(td_api.TextEntityTypeTextUrl(b"t.me/\ra")),
    )
    assert get_message_entities(objects) == (
        MessageEntity(TYPE.PRE_CODE, 0, 1, b"python"),
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/a"),
    )


def test_get_message_entities_turns_a_link_to_a_valid_user_into_a_mention() -> None:
    objects = (
        _object(td_api.TextEntityTypeTextUrl(b"tg://user?id=5")),
        _object(td_api.TextEntityTypeTextUrl(b"tg://user?id=0")),
    )
    assert get_message_entities(objects) == (
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=5),
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"tg://user?id=0"),
    )


def test_get_message_entities_refuses_a_link_to_a_user_the_user_check_refuses(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    # A bot's check refuses only invalid users, which a link to a valid user never
    # names, so the check is replaced to show that its refusal goes through.
    refusal = Failure(400, "Have no access to the user")
    monkeypatch.setattr(
        "tdlib_oracle.tdlib.message_entity.conversion.get_input_user",
        lambda user_id: refusal,
    )
    objects = (_object(td_api.TextEntityTypeTextUrl(b"tg://user?id=5")),)
    assert get_message_entities(objects) == refusal


def test_get_message_entities_reads_the_format_of_a_date() -> None:
    relative = td_api.DateTimeFormattingTypeRelative()
    objects = (_object(td_api.TextEntityTypeDateTime(9, relative)),)
    assert get_message_entities(objects) == (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=9, date_flags=1),
    )


@pytest.mark.parametrize(
    ("entity_type", "message"),
    [
        (
            td_api.TextEntityTypePreCode(b"\xff"),
            "MessageEntityPreCode.language must be encoded in UTF-8",
        ),
        (
            td_api.TextEntityTypeTextUrl(b"\xff"),
            "MessageEntityTextUrl.url must be encoded in UTF-8",
        ),
        (
            td_api.TextEntityTypeTextUrl(b"ftp://t.me"),
            "Entity URL 'ftp://t.me' is invalid: Unsupported URL protocol",
        ),
        (td_api.TextEntityTypeMentionName(0), "User not found"),
        (td_api.TextEntityTypeMediaTimestamp(-1), "Invalid media timestamp specified"),
        (
            td_api.TextEntityTypeCustomEmoji(0),
            "Invalid custom emoji identifier specified",
        ),
        (td_api.TextEntityTypeDateTime(0, None), "Invalid date specified"),
    ],
)
def test_get_message_entities_refuses_a_wrong_value(
    entity_type: td_api.TextEntityType, message: str
) -> None:
    objects = (_object(td_api.TextEntityTypeBold()), _object(entity_type))
    assert get_message_entities(objects) == Failure(400, message)


def test_get_message_entities_refuses_with_the_first_wrong_value() -> None:
    objects = (
        _object(td_api.TextEntityTypeCustomEmoji(0)),
        _object(td_api.TextEntityTypeDateTime(0, None)),
    )
    expected = Failure(400, "Invalid custom emoji identifier specified")
    assert get_message_entities(objects) == expected


def test_get_message_entities_converts_the_tie_of_an_object() -> None:
    link = td_api.TextEntity(1, 1, td_api.TextEntityTypeTextUrl(b"t.me/a"))
    mention = td_api.TextEntity(1, 1, td_api.TextEntityTypeMentionName(5))
    tied = td_api.TextEntity(1, 1, link.type, ties=(link, mention))
    assert get_message_entities((tied,)) == (
        MessageEntity(
            TYPE.TEXT_URL,
            1,
            1,
            b"http://t.me/a",
            ties=(
                MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://t.me/a"),
                MessageEntity(TYPE.MENTION_NAME, 1, 1, user_id=5),
            ),
        ),
    )


def test_get_message_entities_ends_a_tie_whose_objects_become_one_entity() -> None:
    first = td_api.TextEntity(0, 1, td_api.TextEntityTypeTextUrl(b"t.me/a"))
    second = td_api.TextEntity(0, 1, td_api.TextEntityTypeTextUrl(b"http://t.me/a"))
    tied = td_api.TextEntity(0, 1, first.type, ties=(first, second))
    assert get_message_entities((tied,)) == (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/a"),
    )


def test_get_input_message_entities_sends_the_types_a_user_can_set() -> None:
    entities = (
        MessageEntity(TYPE.HASHTAG, 0, 2),
        MessageEntity(TYPE.TEXT_URL, 0, 2, b"http://t.me/"),
        MessageEntity(TYPE.BOT_COMMAND, 3, 2),
    )
    assert get_input_message_entities(entities) == entities[1:2]


def test_get_input_message_entities_sends_splittable_ones_last_and_merged() -> None:
    entities = (
        MessageEntity(TYPE.BOLD, 0, 3),
        MessageEntity(TYPE.CODE, 1, 1),
        MessageEntity(TYPE.BOLD, 3, 2),
    )
    assert get_input_message_entities(entities) == (
        MessageEntity(TYPE.CODE, 1, 1),
        MessageEntity(TYPE.BOLD, 0, 5),
    )


def test_get_input_message_entities_sends_up_to_100_besides_custom_emoji() -> None:
    codes = tuple(MessageEntity(TYPE.CODE, 2 * index, 1) for index in range(_CAP))
    custom_emoji = MessageEntity(TYPE.CUSTOM_EMOJI, 2 * _CAP, 1, custom_emoji_id=7)
    bold = MessageEntity(TYPE.BOLD, 2 * _CAP + 1, 1)
    assert get_input_message_entities((*codes, custom_emoji, bold)) == (
        *codes[:100],
        custom_emoji,
    )
    assert get_input_message_entities((*codes[:99], bold)) == (*codes[:99], bold)


def test_get_input_message_entities_sends_an_entity_with_its_tie() -> None:
    tie = (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://a/"),
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=5),
    )
    entity = MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://a/", ties=tie)
    assert get_input_message_entities((entity,)) == (entity,)
