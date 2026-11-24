from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.message_entity import TYPE, type_name

pytestmark = pytest.mark.differential

Compare = Callable[..., None]


def _type_name(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (type_name(args[0]).encode(),)


def test_type_name_gives_the_pinned_name_of_each_type(compare: Compare) -> None:
    cases = [((), (entity_type,)) for entity_type in range(TYPE.SIZE)]
    compare(
        "operator<<(MessageEntity::Type)",
        _type_name,
        cases,
        seed=None,
        by_bytes=False,
    )
