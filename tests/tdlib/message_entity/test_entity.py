from tdlib_oracle.tdlib.message_entity import TYPE, MessageEntity, order


def test_orders_by_offset_then_the_longer_entity_first_then_by_type_priority() -> None:
    entities = (
        MessageEntity(TYPE.ITALIC, 2, 1),
        MessageEntity(TYPE.ITALIC, 0, 1),
        MessageEntity(TYPE.BOLD, 0, 1),
        MessageEntity(TYPE.CODE, 0, 3),
    )
    assert sorted(entities, key=order) == [
        MessageEntity(TYPE.CODE, 0, 3),
        MessageEntity(TYPE.BOLD, 0, 1),
        MessageEntity(TYPE.ITALIC, 0, 1),
        MessageEntity(TYPE.ITALIC, 2, 1),
    ]


def test_puts_a_blockquote_before_the_entities_it_starts_with() -> None:
    quote = MessageEntity(TYPE.BLOCK_QUOTE, 0, 2)
    pre = MessageEntity(TYPE.PRE, 0, 2)
    assert sorted((pre, quote), key=order) == [quote, pre]


def test_ties_a_link_and_a_mention_of_the_same_text() -> None:
    link = MessageEntity(TYPE.TEXT_URL, 1, 3, b"t.me")
    mention = MessageEntity(TYPE.MENTION_NAME, 1, 3, user_id=7)
    assert order(link) == order(mention)
