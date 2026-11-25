import dataclasses

import pytest

from tdlib_oracle.tdlib import telegram_api


def test_an_entity_carries_no_tie_unless_given_one() -> None:
    assert telegram_api.MessageEntityBold(0, 1).ties == ()


def test_objects_equal_by_constructor_and_values() -> None:
    objects: list[telegram_api.MessageEntity] = [
        telegram_api.MessageEntityPre(0, 1, b""),
        telegram_api.MessageEntityPre(0, 1, b""),
        telegram_api.MessageEntityCode(0, 1),
        telegram_api.MessageEntityTextUrl(0, 1, b"a"),
        telegram_api.MessageEntityTextUrl(0, 1, b"b"),
    ]
    assert objects[0] == objects[1]
    assert len(set(objects)) == 4


def test_objects_are_frozen_and_hash_by_their_values() -> None:
    user = telegram_api.InputUser(5, 0)
    mention = telegram_api.InputMessageEntityMentionName(0, 1, user)
    with pytest.raises(dataclasses.FrozenInstanceError):
        mention.offset = 2  # type: ignore[misc]  # a frozen object refuses it
    same_user = telegram_api.InputUser(5, 0)
    copy = telegram_api.InputMessageEntityMentionName(0, 1, same_user)
    assert len({mention, copy}) == 1
