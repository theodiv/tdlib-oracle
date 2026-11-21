import dataclasses

import pytest

from tdlib_oracle.tdlib import td_api


def test_text_entity_carries_no_tie_unless_given_one() -> None:
    assert td_api.TextEntity(0, 1, td_api.TextEntityTypeBold()).ties == ()


def test_objects_equal_by_constructor_and_values() -> None:
    types: list[td_api.TextEntityType] = [
        td_api.TextEntityTypeBold(),
        td_api.TextEntityTypeBold(),
        td_api.TextEntityTypeItalic(),
        td_api.TextEntityTypeTextUrl(b"a"),
        td_api.TextEntityTypeTextUrl(b"b"),
    ]
    assert types[0] == types[1]
    assert len(set(types)) == 4


def test_objects_are_frozen_and_hash_by_their_values() -> None:
    entity = td_api.TextEntity(0, 1, td_api.TextEntityTypePreCode(b"python"))
    with pytest.raises(dataclasses.FrozenInstanceError):
        entity.offset = 2  # type: ignore[misc]  # a frozen object refuses it
    copy = td_api.TextEntity(0, 1, td_api.TextEntityTypePreCode(b"python"))
    assert len({entity, copy}) == 1
