# Ported from test/message_entities.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

import random
from dataclasses import replace

from tdlib_oracle.tdlib.entities import TYPE, FormattedText, MessageEntity
from tdlib_oracle.tdlib.fixing import fix_formatted_text
from tdlib_oracle.text.failure import Failure
from tdlib_oracle.text.utf8 import utf8_utf16_length


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, const td::string &expected_str, ...).
def _check_fix_formatted_text(
    text: bytes,
    entities: tuple[MessageEntity, ...],
    expected_text: bytes,
    expected_entities: tuple[MessageEntity, ...],
    allow_empty: bool = True,
    skip_new_entities: bool = False,
    skip_bot_commands: bool = False,
    skip_trim: bool = True,
) -> None:
    # The port finds no entities on its own, so `skip_new_entities` and
    # `skip_bot_commands` change nothing; they stay so that each call reads as
    # upstream's does.
    result = fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=False,
        skip_trim=skip_trim,
    )
    assert result == FormattedText(expected_text, expected_entities)


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, bool allow_empty, ...).
def _check_fix_formatted_text_fails(
    text: bytes,
    entities: tuple[MessageEntity, ...],
    allow_empty: bool,
    skip_new_entities: bool,
    skip_bot_commands: bool,
    skip_trim: bool,
) -> None:
    result = fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=False,
        skip_trim=skip_trim,
    )
    assert isinstance(result, Failure)


# Ported from test/message_entities.cpp, TEST(MessageEntities, fix_formatted_text), its
# loop over random texts. It stays out of the test's body, since CPython 3.12 traces
# each line in a time that grows with the length of the function holding it.
def _check_fix_formatted_text_on_random_texts() -> None:  # noqa: PLR0912  # mirrors upstream
    # td::Random, seeded so that a failure reproduces.
    rng = random.Random(20261119)
    for test_n in range(100000):
        is_url = rng.random() < 0.5
        if is_url:
            # Upstream builds a text holding "example.com" here, and expects the link
            # TDLib finds in it, which the port leaves out.
            continue
        url_offset = 0
        url_end = 0
        text = b"a" * rng.randint(1, 20)

        n = rng.randint(1, 20)
        entity_list = []
        for _ in range(n):
            entity_type = rng.randint(4, TYPE.SIZE - 1)
            offset = rng.randint(0, len(text) - 1)
            max_length = len(text) - offset
            if (test_n & 1) != 0 and max_length > 4:
                max_length = 4
            length = rng.randint(0, max_length)
            entity_list.append(MessageEntity(entity_type, offset, length))

        def get_type_mask(
            length: int, entities: tuple[MessageEntity, ...]
        ) -> list[int]:
            result = [0] * length
            for entity in entities:
                for pos in range(entity.length):
                    result[entity.offset + pos] |= 1 << entity.type
            return result

        old_type_mask = get_type_mask(len(text), tuple(entity_list))
        result = fix_formatted_text(
            text,
            tuple(entity_list),
            allow_empty=False,
            allow_empty_string=False,
            skip_trim=False,
        )
        case = (test_n, text, entity_list)
        assert not isinstance(result, Failure), case
        text = result.text
        entities = result.entities
        new_type_mask = get_type_mask(len(text), entities)
        splittable_mask = (1 << 5) | (1 << 6) | (1 << 14) | (1 << 15) | (1 << 19)
        pre_mask = (1 << 7) | (1 << 8) | (1 << 9)
        for pos in range(len(text)):
            if (new_type_mask[pos] & pre_mask) != 0:
                assert (new_type_mask[pos] & splittable_mask) == 0, case
            else:
                assert (old_type_mask[pos] & splittable_mask) == (
                    new_type_mask[pos] & splittable_mask
                ), case
        keep_url = is_url
        url_entity = MessageEntity(TYPE.URL, url_offset, url_end - url_offset)
        for entity in entities:
            if entity == url_entity:
                continue
            offset = entity.offset
            end = offset + entity.length

            if (
                keep_url
                and ((1 << entity.type) & splittable_mask) == 0
                and not (end <= url_offset or url_end <= offset)
            ):
                keep_url = (
                    entity.type in (TYPE.BLOCK_QUOTE, TYPE.EXPANDABLE_BLOCK_QUOTE)
                    and offset <= url_offset
                    and url_end <= end
                )
        assert keep_url == (entities.count(url_entity) == 1), case

        for i in range(len(entities)):
            type_mask = 1 << entities[i].type
            for j in range(i + 1, len(entities)):
                # sorted
                assert entities[j].offset > entities[i].offset or (
                    entities[j].offset == entities[i].offset
                    and entities[j].length <= entities[i].length
                ), case

                # not intersecting
                assert (
                    entities[j].offset >= entities[i].offset + entities[i].length
                    or entities[j].offset + entities[j].length
                    <= entities[i].offset + entities[i].length
                ), case

                if entities[j].offset < entities[i].offset + entities[i].length:
                    # types are different
                    assert entities[j].type != entities[i].type, case

                    # pre can't contain other entities
                    assert (type_mask & pre_mask) == 0, case

                    if (type_mask & splittable_mask) == 0 and entities[i].type not in (
                        TYPE.BLOCK_QUOTE,
                        TYPE.EXPANDABLE_BLOCK_QUOTE,
                    ):
                        # continuous entities can contain only splittable entities
                        assert ((1 << entities[j].type) & splittable_mask) != 0, case


# Ported from test/message_entities.cpp, TEST(MessageEntities, fix_formatted_text),
# without the cases whose results hold entities that TDLib finds on its own.
def test_fix_formatted_text() -> None:  # noqa: PLR0912, PLR0915  # mirrors upstream
    text = b""
    fixed_text = b""
    for i in range(33):
        text += bytes([i])
        if i != 13:
            if i != 10:
                fixed_text += b" "
            else:
                fixed_text += text[-1:]

    _check_fix_formatted_text(text, (), b"", (), True, True, True, True)
    _check_fix_formatted_text(text, (), b"", (), True, True, False, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, True, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, False, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, False, False)
    _check_fix_formatted_text_fails(text, (), False, False, False, False)
    _check_fix_formatted_text_fails(text, (), False, False, False, True)

    _check_fix_formatted_text(b"  aba\n ", (), b"  aba\n ", (), True, True, True, True)
    _check_fix_formatted_text(b"  aba\n ", (), b"aba", (), True, True, True, False)
    _check_fix_formatted_text(b"  \n ", (), b"", (), True, True, True, True)
    _check_fix_formatted_text(b"  \n ", (), b"", (), True, True, True, False)
    _check_fix_formatted_text_fails(b"  \n ", (), False, True, True, False)

    text += b"a  \r\n  "
    fixed_text += b"a  \n  "

    for i in range(33, 36):
        entities: tuple[MessageEntity, ...] = (MessageEntity(TYPE.PRE, 0, i),)

        fixed_entities: tuple[MessageEntity, ...] = (MessageEntity(TYPE.PRE, 0, i - 1),)
        _check_fix_formatted_text(
            text, entities, fixed_text, fixed_entities, True, False, False, True
        )

        expected_text = fixed_text[:33]
        fixed_entities = (MessageEntity(TYPE.PRE, 0, 32 if i == 33 else 33),)
        _check_fix_formatted_text(
            text, entities, expected_text, fixed_entities, False, False, False, False
        )

    for i in range(33, 36):
        entities = (MessageEntity(TYPE.BOLD, 0, i),)

        fixed_entities = (MessageEntity(TYPE.BOLD, 0, i - 1),)  # deleted \r
        _check_fix_formatted_text(
            text, entities, fixed_text, fixed_entities, True, False, False, True
        )

        expected_text = fixed_text[:33]
        if i != 33:
            fixed_entities = (MessageEntity(TYPE.BOLD, 0, 33),)
        _check_fix_formatted_text(
            text, entities, expected_text, fixed_entities, False, False, False, False
        )

    text = "\U0001f449 \U0001f449  ".encode()
    for i in range(10):
        entities = (MessageEntity(TYPE.BOLD, i, 1),)
        if i not in (2, 5, 6):
            _check_fix_formatted_text_fails(text, entities, True, True, True, True)
            _check_fix_formatted_text_fails(text, entities, False, False, False, False)
        else:
            _check_fix_formatted_text(
                text,
                entities,
                text,
                (MessageEntity(TYPE.BOLD, i, 1),),
                True,
                True,
                True,
                True,
            )
            if i == 2:
                _check_fix_formatted_text(
                    text,
                    entities,
                    text[:-2],
                    (MessageEntity(TYPE.BOLD, i, 1),),
                    False,
                    False,
                    False,
                    False,
                )
            else:
                _check_fix_formatted_text(
                    text, entities, text[:-2], (), False, False, False, False
                )

    # Upstream also runs these without skipping new entities and expects the entities
    # TDLib finds on its own, which the port leaves out.
    text = b"  /test @abaca #ORD $ABC  telegram.org "
    for skip_trim in (False, True):
        expected_text = text if skip_trim else text[2 : len(text) - 1]
        for skip_bot_commands in (False, True):
            _check_fix_formatted_text(
                text, (), expected_text, (), True, True, skip_bot_commands, skip_trim
            )
            _check_fix_formatted_text(
                text, (), expected_text, (), False, True, skip_bot_commands, skip_trim
            )

    text = b"aba \r\n caba "
    user_id = 1
    for length in range(1, 4):
        for offset in range(len(text) - length + 1):
            for entity_type in (TYPE.BOLD, TYPE.URL, TYPE.TEXT_URL, TYPE.MENTION_NAME):
                for skip_trim in (False, True):
                    fixed_text = b"aba \n caba " if skip_trim else b"aba \n caba"
                    fixed_length = (
                        length - 1 if offset <= 4 and offset + length >= 5 else length
                    )
                    fixed_offset = offset - 1 if offset >= 5 else offset
                    while fixed_offset + fixed_length > len(fixed_text):
                        fixed_length -= 1

                    entity = MessageEntity(entity_type, offset, length)
                    if entity_type == TYPE.TEXT_URL:
                        entity = replace(entity, argument=b"t.me")
                    elif entity_type == TYPE.MENTION_NAME:
                        entity = replace(entity, user_id=user_id)
                    fixed_entities = ()
                    if fixed_length > 0:
                        fixed_entities = (
                            replace(entity, offset=fixed_offset, length=fixed_length),
                        )
                    _check_fix_formatted_text(
                        text,
                        (entity,),
                        fixed_text,
                        fixed_entities,
                        True,
                        False,
                        False,
                        skip_trim,
                    )

    text = b"aba caba"
    for length in range(-10, 11):
        for offset in range(-10, 11):
            entities = (MessageEntity(TYPE.BOLD, offset, length),)
            if length < 0 or offset < 0 or (length > 0 and length + offset > len(text)):
                _check_fix_formatted_text_fails(
                    text, entities, True, False, False, False
                )
                _check_fix_formatted_text_fails(
                    text, entities, False, False, False, True
                )
                continue

            fixed_entities = ()
            if length > 0:
                fixed_entities = (MessageEntity(TYPE.BOLD, offset, length),)

            _check_fix_formatted_text(
                text, entities, text, fixed_entities, True, False, False, False
            )
            _check_fix_formatted_text(
                text, entities, text, fixed_entities, False, False, False, True
            )

    text = b"abadcaba"
    for length in range(1, 8):
        for offset in range(9 - length):
            for length2 in range(1, 8):
                for offset2 in range(9 - length2):
                    if offset != offset2:
                        entities = (
                            MessageEntity(TYPE.TEXT_URL, offset, length, b"t.me"),
                            MessageEntity(TYPE.TEXT_URL, offset2, length2, b"t.me"),
                            MessageEntity(TYPE.TEXT_URL, offset2 + length2, 1),
                        )
                        # std::sort, of two entities that start apart.
                        fixed = sorted(entities[:2], key=lambda entity: entity.offset)
                        if fixed[0].offset + fixed[0].length > fixed[1].offset:
                            fixed.pop()
                        _check_fix_formatted_text(
                            text,
                            entities,
                            text,
                            tuple(fixed),
                            False,
                            False,
                            False,
                            False,
                        )

    for raw in (
        " \n \U000027a1\U0000fe0f \U000027a1\U0000fe0f \U000027a1\U0000fe0f"
        " \U000027a1\U0000fe0f  \n ",
        "\n\n\nab cd ef gh        ",
    ):
        text = raw.encode()
        entity_list = []
        fixed_entity_list = []

        length = utf8_utf16_length(text)
        for i in range(10):
            if (i + 1) * 3 + 2 <= length:
                entity_list.append(MessageEntity(TYPE.BOLD, (i + 1) * 3, 2))
            if (i + 2) * 3 <= length:
                entity_list.append(MessageEntity(TYPE.ITALIC, (i + 1) * 3 + 2, 1))

            if i < 4:
                fixed_entity_list.append(MessageEntity(TYPE.BOLD, i * 3, 2))
            if i < 3:
                fixed_entity_list.append(MessageEntity(TYPE.ITALIC, i * 3 + 2, 1))

        # td::utf8_utf16_substr(str, 3, 11)
        expected_text = raw.encode("utf-16-le")[6:28].decode("utf-16-le").encode()
        _check_fix_formatted_text(
            text,
            tuple(entity_list),
            expected_text,
            tuple(fixed_entity_list),
            False,
            False,
            False,
            False,
        )

    for text in (b"\t", b"\r", b"\n", b"\t ", b"\r ", b"\n "):
        for entity_type in (TYPE.BOLD, TYPE.TEXT_URL):
            _check_fix_formatted_text(
                text,
                (MessageEntity(entity_type, 0, 1, b"http://telegram.org/"),),
                b"",
                (),
                True,
                False,
                False,
                True,
            )
    _check_fix_formatted_text(
        b"\r ",
        (MessageEntity(TYPE.BOLD, 0, 2), MessageEntity(TYPE.UNDERLINE, 0, 1)),
        b"",
        (),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r",
        (MessageEntity(TYPE.BOLD, 0, 3), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a ",
        (MessageEntity(TYPE.BOLD, 0, 2),),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r ",
        (MessageEntity(TYPE.BOLD, 0, 4), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a  ",
        (MessageEntity(TYPE.BOLD, 0, 3),),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r b",
        (MessageEntity(TYPE.BOLD, 0, 5), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a  b",
        (MessageEntity(TYPE.BOLD, 0, 4),),
        True,
        False,
        False,
        True,
    )

    _check_fix_formatted_text(
        b"a\rbc\r",
        (
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 0, 2),
            MessageEntity(TYPE.ITALIC, 3, 2),
            MessageEntity(TYPE.BOLD, 3, 1),
        ),
        b"abc",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
    )
    _check_fix_formatted_text(
        b"a ",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 0, 1)),
        b"a",
        (MessageEntity(TYPE.BOLD, 0, 1), MessageEntity(TYPE.ITALIC, 0, 1)),
        False,
        False,
        False,
        False,
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1), MessageEntity(TYPE.ITALIC, 0, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1), MessageEntity(TYPE.ITALIC, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.ITALIC, 1, 2)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.ITALIC, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.ITALIC, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.ITALIC, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 1, 2)),
        b"abc",
        (
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 1, 2),
            MessageEntity(TYPE.ITALIC, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.BOLD, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.BOLD, 2, 1)),
    )
    # Upstream also checks "@tests @tests" here, whose result holds the mentions TDLib
    # finds on its own, which the port leaves out.

    # __a~b~__
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.STRIKETHROUGH, 1, 1)),
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.STRIKETHROUGH, 0, 2), MessageEntity(TYPE.UNDERLINE, 1, 1)),
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
        ),
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )

    # __||a||b__
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.SPOILER, 0, 1),
        ),
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
    )

    # _*a*_\r_*b*_
    _check_fix_formatted_text(
        b"a\rb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
        b"ab",
        (MessageEntity(TYPE.BOLD, 0, 2), MessageEntity(TYPE.ITALIC, 0, 2)),
    )
    _check_fix_formatted_text(
        b"a\nb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
        b"a\nb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
    )

    # ||`a`||
    _check_fix_formatted_text(
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1), MessageEntity(TYPE.SPOILER, 0, 1)),
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1),),
    )
    _check_fix_formatted_text(
        b"a",
        (MessageEntity(TYPE.SPOILER, 0, 1), MessageEntity(TYPE.PRE, 0, 1)),
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1),),
    )

    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3), MessageEntity(TYPE.STRIKETHROUGH, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 0, 3)),
        b"abc",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.PRE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 2, 1),
        ),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 1, 2)),
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 0, 2)),
        b"abc",
        (MessageEntity(TYPE.STRIKETHROUGH, 0, 1), MessageEntity(TYPE.PRE, 1, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3), MessageEntity(TYPE.BLOCK_QUOTE, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 1, 1),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3), MessageEntity(TYPE.PRE, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3), MessageEntity(TYPE.PRE, 1, 1)),
    )

    # Upstream also checks texts holding "example.com" here, whose results hold the
    # link TDLib finds on its own, which the port leaves out.

    _check_fix_formatted_text_on_random_texts()

    _check_fix_formatted_text(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f a",
        (),
        b"\xe2\x80\x8c\xe2\x80\x8f  \xe2\x80\x8c\xe2\x80\x8c\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8c\xe2\x80\x8e \xe2\x80\x8f a",
        (),
    )
    _check_fix_formatted_text_fails(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f",
        (),
        False,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f",
        (),
        b"",
        (),
    )
