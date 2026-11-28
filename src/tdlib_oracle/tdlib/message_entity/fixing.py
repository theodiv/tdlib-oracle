# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's fixing of a formatted text: entities, cleaning, trimming, and emptiness."""

from collections.abc import Iterable, Sequence
from dataclasses import replace

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.custom_emoji_id import is_valid_custom_emoji_id
from tdlib_oracle.tdlib.formatted_date import is_valid_formatted_date
from tdlib_oracle.tdlib.message_entity.entity import (
    _BLOCKQUOTE_ENTITIES_MASK,
    _CONTINUOUS_ENTITIES_MASK,
    _SPLITTABLE_ENTITIES_MASK,
    _SPLITTABLE_ENTITY_TYPE_COUNT,
    TYPE,
    FormattedText,
    MessageEntity,
    _get_entity_type_mask,
    _get_splittable_entity_type_index,
    _is_blockquote_entity,
    _is_continuous_entity,
    _is_pre_entity,
    _is_splittable_entity,
    _remove_intersecting_entities,
    _sort_entities,
    _split_entities,
)
from tdlib_oracle.tdlib.message_entity.finding import find_entities
from tdlib_oracle.tdlib.misc import (
    clean_input_string,
    is_empty_string,
    replace_offending_characters,
)
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tdlib_oracle.tdutils.algorithm import combine
from tdlib_oracle.tdutils.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    utf8_utf16_length,
)

# Ported from td/telegram/MessageEntity.cpp, LENGTH_LIMIT in fix_formatted_text().
_LENGTH_LIMIT = 35000  # server-side limit


# Ported from td/telegram/MessageEntity.cpp, remove_empty_entities(), the lambda that
# picks the entities to remove.
def _is_empty_entity(entity: MessageEntity) -> bool:
    if entity.length <= 0:
        return True
    match entity.type:
        case TYPE.TEXT_URL:
            return not entity.argument
        case TYPE.MENTION_NAME:
            return not is_valid_user_id(entity.user_id)
        case TYPE.CUSTOM_EMOJI:
            return not is_valid_custom_emoji_id(entity.custom_emoji_id)
        case TYPE.FORMATTED_DATE:
            return not is_valid_formatted_date(entity.date)
        case _:
            return False


# Ported from td/telegram/MessageEntity.cpp, remove_empty_entities().
def remove_empty_entities(entities: Iterable[MessageEntity]) -> list[MessageEntity]:
    """Return `entities` in their order, without the empty ones."""
    return [entity for entity in entities if not _is_empty_entity(entity)]


# Ported from td/telegram/MessageEntity.cpp, are_entities_valid().
def _are_entities_valid(entities: Sequence[MessageEntity]) -> bool:
    """Return whether the sorted `entities` already nest and meet as TDLib allows."""
    if not entities:
        return True

    end_pos = [-1] * _SPLITTABLE_ENTITY_TYPE_COUNT
    nested_entities_stack: list[MessageEntity] = []
    nested_entity_type_mask = 0
    for entity in entities:
        while nested_entities_stack and entity.offset >= (
            nested_entities_stack[-1].offset + nested_entities_stack[-1].length
        ):
            nested_entity_type_mask -= _get_entity_type_mask(
                nested_entities_stack[-1].type
            )
            nested_entities_stack.pop()

        if nested_entities_stack:
            parent = nested_entities_stack[-1]
            if entity.offset + entity.length > parent.offset + parent.length:
                return False  # it intersects an earlier entity
            if (nested_entity_type_mask & _get_entity_type_mask(entity.type)) != 0:
                return False  # an entity of its type encloses it
            if _is_pre_entity(parent.type):
                return False  # a pre entity holds no other entity
            if (
                _is_pre_entity(entity.type)
                and (nested_entity_type_mask & ~_BLOCKQUOTE_ENTITIES_MASK) != 0
            ):
                return False  # only a blockquote may hold a pre entity
            if (
                _is_continuous_entity(entity.type) or _is_blockquote_entity(entity.type)
            ) and (nested_entity_type_mask & _CONTINUOUS_ENTITIES_MASK) != 0:
                return False  # a continuous entity holds no continuous or blockquote
            if (
                _is_blockquote_entity(entity.type)
                and (nested_entity_type_mask & _BLOCKQUOTE_ENTITIES_MASK) != 0
            ):
                return False  # blockquotes do not nest
            if (nested_entity_type_mask & _SPLITTABLE_ENTITIES_MASK) != 0:
                return False  # the splittable entity around it may need splitting

        if _is_splittable_entity(entity.type):
            index = _get_splittable_entity_type_index(entity.type)
            if end_pos[index] >= entity.offset:
                return False  # it can merge with the last entity of its type
            end_pos[index] = entity.offset + entity.length
        nested_entities_stack.append(entity)
        nested_entity_type_mask += _get_entity_type_mask(entity.type)
    return True


# Ported from td/telegram/MessageEntity.cpp, remove_entities_intersecting_blockquote().
def _remove_entities_intersecting_blockquote(
    entities: Sequence[MessageEntity], blockquote_entities: Sequence[MessageEntity]
) -> list[MessageEntity]:
    """Return the `entities` that each lie within a blockquote or outside all of them.

    Both lists must be sorted and free of intersections.
    """
    if not blockquote_entities:
        return list(entities)

    blockquote_it = 0
    kept = []
    for entity in entities:
        while blockquote_it < len(blockquote_entities) and (
            not _is_blockquote_entity(blockquote_entities[blockquote_it].type)
            or blockquote_entities[blockquote_it].offset
            + blockquote_entities[blockquote_it].length
            <= entity.offset
        ):
            blockquote_it += 1
        if blockquote_it < len(blockquote_entities):
            blockquote = blockquote_entities[blockquote_it]
            entity_end = entity.offset + entity.length
            if (
                blockquote.offset + blockquote.length < entity_end
                or entity.offset < blockquote.offset < entity_end
            ):
                continue
        kept.append(entity)
    return kept


# Ported from td/telegram/MessageEntity.cpp, merge_entities().
def _merge_entities(
    old_entities: Sequence[MessageEntity], new_entities: Sequence[MessageEntity]
) -> list[MessageEntity]:
    """Return the sorted lists as one, without new entities that overlap old ones."""
    if not new_entities:
        return list(old_entities)
    if not old_entities:
        return list(new_entities)

    result = []
    new_it = 0
    for old_entity in old_entities:
        while (
            new_it < len(new_entities)
            and new_entities[new_it].offset + new_entities[new_it].length
            <= old_entity.offset
        ):
            result.append(new_entities[new_it])
            new_it += 1
        old_entity_end = old_entity.offset + old_entity.length
        result.append(old_entity)
        while (
            new_it < len(new_entities) and new_entities[new_it].offset < old_entity_end
        ):
            new_it += 1
    result.extend(new_entities[new_it:])
    return result


# Ported from td/telegram/MessageEntity.cpp, resplit_entities().
def _resplit_entities(
    splittable_entities: Sequence[MessageEntity], entities: Sequence[MessageEntity]
) -> tuple[MessageEntity, ...]:
    if splittable_entities:
        split = _split_entities(splittable_entities, entities)
        if not entities:
            return split
        return _sort_entities(combine(entities, split))
    return tuple(entities)


# Ported from td/telegram/MessageEntity.cpp, fix_entities().
def fix_entities(entities: Sequence[MessageEntity]) -> tuple[MessageEntity, ...]:
    """Return `entities` sorted, without those that overlap or nest as TDLib forbids."""
    entities = _sort_entities(entities)
    if _are_entities_valid(entities):
        return entities

    continuous_entities: list[MessageEntity] = []
    blockquote_entities: list[MessageEntity] = []
    splittable_entities: list[MessageEntity] = []
    for entity in entities:
        if _is_splittable_entity(entity.type):
            splittable_entities.append(entity)
        elif _is_blockquote_entity(entity.type):
            blockquote_entities.append(entity)
        else:
            continuous_entities.append(entity)
    continuous_entities = _remove_intersecting_entities(continuous_entities)

    if blockquote_entities:
        blockquote_entities = _remove_intersecting_entities(blockquote_entities)
        continuous_entities = _remove_entities_intersecting_blockquote(
            continuous_entities, blockquote_entities
        )
        continuous_entities = list(
            _sort_entities(combine(continuous_entities, blockquote_entities))
        )

    return _resplit_entities(splittable_entities, continuous_entities)


# Ported from td/telegram/MessageEntity.cpp, merge_new_entities().
def _merge_new_entities(
    entities: Sequence[MessageEntity], new_entities: Sequence[MessageEntity]
) -> tuple[MessageEntity, ...]:
    """Return the sorted `entities` with the `new_entities` found in their text."""
    if not new_entities:
        # fast path
        return tuple(entities)

    continuous_entities: list[MessageEntity] = []
    blockquote_entities: list[MessageEntity] = []
    splittable_entities: list[MessageEntity] = []
    for entity in entities:
        if _is_splittable_entity(entity.type):
            splittable_entities.append(entity)
        elif _is_blockquote_entity(entity.type):
            blockquote_entities.append(entity)
        else:
            continuous_entities.append(entity)

    new_entities = _remove_entities_intersecting_blockquote(
        new_entities, blockquote_entities
    )

    # merge before combining with blockquote entities
    continuous_entities = _merge_entities(continuous_entities, new_entities)

    if blockquote_entities:
        continuous_entities = list(
            _sort_entities(combine(continuous_entities, blockquote_entities))
        )

    # must be called once to not merge some adjacent entities
    return _resplit_entities(splittable_entities, continuous_entities)


# Ported from td/telegram/MessageEntity.cpp, clean_input_string_with_entities().
def _clean_input_string_with_entities(
    text: bytes, entities: Sequence[MessageEntity]
) -> tuple[bytes, list[MessageEntity]] | Failure:
    """Return `text` cleaned as `clean_input_string` cleans it, with `entities` moved.

    The text is not cut. The entities must be sorted, and may nest but not intersect.
    """
    fixed = list(entities)
    # The entities open at the current position, by index, each with the UTF-16 code
    # units dropped before it.
    nested_entities_stack: list[tuple[int, int]] = []
    current_entity = 0

    utf16_offset = 0
    utf16_skipped = 0

    text_size = len(text)

    result = bytearray()
    pos = 0
    while pos <= text_size:
        # At the end, the C++ reads the string terminator.
        c = text[pos] if pos < text_size else 0
        is_utf8_character_begin = is_utf8_character_first_code_unit(c)
        if is_utf8_character_begin:
            while nested_entities_stack:
                index, skipped_before_current_entity = nested_entities_stack[-1]
                entity = fixed[index]
                entity_end = entity.offset + entity.length
                if utf16_offset < entity_end:
                    break

                if utf16_offset != entity_end:
                    return Failure(
                        400,
                        f"Entity beginning at UTF-16 offset {entity.offset} ends in a"
                        f" middle of a UTF-16 symbol at byte offset {pos}",
                    )

                fixed[index] = replace(
                    entity,
                    offset=entity.offset - skipped_before_current_entity,
                    length=entity.length
                    - (utf16_skipped - skipped_before_current_entity),
                )
                nested_entities_stack.pop()
            while (
                current_entity < len(fixed)
                and utf16_offset >= fixed[current_entity].offset
            ):
                if utf16_offset != fixed[current_entity].offset:
                    return Failure(
                        400,
                        "Entity begins in a middle of a UTF-16 symbol at byte offset"
                        f" {pos}",
                    )
                nested_entities_stack.append((current_entity, utf16_skipped))
                current_entity += 1
        if pos == text_size:
            break

        if c <= 0x20 and c not in (0x0A, 0x0D):
            # A control character becomes a space; a line feed stays.
            result.append(0x20)
            utf16_offset += 1
        elif c == 0x0D:
            utf16_offset += 1
            utf16_skipped += 1
        else:
            if is_utf8_character_begin:
                # A character of 4 bytes takes a surrogate pair.
                utf16_offset += 1 + (c >= 0xF0)
            if (
                c == 0xE2
                and pos + 2 < text_size
                and text[pos + 1] == 0x80
                and 0xA8 <= text[pos + 2] <= 0xAE
            ):
                pos += 2
                utf16_skipped += 1
            elif (
                c == 0xCC
                and pos + 1 < text_size
                and text[pos + 1] in (0xB3, 0xBF, 0x8A)
            ):
                pos += 1
                utf16_skipped += 1
            else:
                result.append(c)
        pos += 1

    if current_entity != len(fixed):
        return Failure(
            400,
            "Entity begins after the end of the text at UTF-16 offset"
            f" {fixed[current_entity].offset}",
        )
    if nested_entities_stack:
        entity = fixed[nested_entities_stack[-1][0]]
        return Failure(
            400,
            f"Entity beginning at UTF-16 offset {entity.offset} ends after the end of"
            f" the text at UTF-16 offset {entity.offset + entity.length}",
        )

    return replace_offending_characters(bytes(result)), fixed


# Ported from td/telegram/MessageEntity.cpp, remove_invalid_entities().
def _remove_invalid_entities(
    text: bytes, entities: Sequence[MessageEntity]
) -> tuple[int, int, list[MessageEntity]]:
    """Return where the text ends once trimmed at its end, and the nonempty entities.

    The end comes as the offset of the last byte that is not a space or a line feed,
    with the UTF-16 offset of the code unit that byte ends, or as the length of `text`
    and `-1` when every byte is one of them. Without entities, the UTF-16 offset is `0`,
    which nothing reads then.
    """
    if not entities:
        # fast path
        for pos in range(len(text)):
            back_pos = len(text) - pos - 1
            if text[back_pos] not in (0x0A, 0x20):
                return back_pos, 0, []
        return len(text), -1, []

    last_non_whitespace_pos = len(text)

    utf16_offset = 0
    last_non_whitespace_utf16_offset = -1

    kept = remove_empty_entities(entities)

    pos = 0
    while pos < len(text):
        c = text[pos]
        if c not in (0x0A, 0x20):
            # Past the end, the C++ reads the string terminator, which starts a
            # character.
            while pos + 1 < len(text) and not is_utf8_character_first_code_unit(
                text[pos + 1]
            ):
                pos += 1
            utf16_offset += c >= 0xF0  # a character of 4 bytes takes a surrogate pair
            last_non_whitespace_pos = pos
            last_non_whitespace_utf16_offset = utf16_offset
        utf16_offset += 1
        pos += 1
    return last_non_whitespace_pos, last_non_whitespace_utf16_offset, kept


# Ported from td/telegram/MessageEntity.cpp, fix_formatted_text(), for
# skip_media_timestamps set, without ltrim_count.
def fix_formatted_text(
    text: bytes,
    entities: Sequence[MessageEntity],
    *,
    allow_empty: bool,
    allow_empty_string: bool,
    skip_new_entities: bool,
    skip_bot_commands: bool,
    skip_trim: bool,
) -> FormattedText | Failure:
    """Return `text` and `entities` as TDLib fixes them, or its `Failure`."""
    if not entities:
        # fast path
        cleaned = clean_input_string(text)
        if cleaned is None:
            return Failure(400, "Strings must be encoded in UTF-8")
        result = cleaned
        fixed: list[MessageEntity] = []
    else:
        if not check_utf8(text):
            return Failure(400, "Strings must be encoded in UTF-8")

        for entity in entities:
            if entity.offset < 0 or entity.offset > 1000000:
                return Failure(
                    400, f"Receive an entity with incorrect offset {entity.offset}"
                )
            if entity.length < 0 or entity.length > 1000000:
                return Failure(
                    400, f"Receive an entity with incorrect length {entity.length}"
                )

        cleaned_with_entities = _clean_input_string_with_entities(
            text, fix_entities(remove_empty_entities(entities))
        )
        if isinstance(cleaned_with_entities, Failure):
            return cleaned_with_entities
        result, fixed = cleaned_with_entities

    # The entities are still sorted by offset and length, but not by type, since
    # dropped characters can bring the ends of entities together.
    last_non_whitespace_pos, last_non_whitespace_utf16_offset, fixed = (
        _remove_invalid_entities(result, fixed)
    )
    if last_non_whitespace_utf16_offset == -1:
        if allow_empty:
            return FormattedText(b"")
        return Failure(400, "Text must be non-empty")

    # Dropped characters can also leave splittable entities to merge.
    fixed = list(fix_entities(fixed))

    if skip_trim:
        fixed_text = result
    else:
        result = result[: last_non_whitespace_pos + 1]
        while fixed and fixed[-1].offset > last_non_whitespace_utf16_offset:
            fixed.pop()
        need_sort = False
        for index, entity in enumerate(fixed):
            if entity.offset + entity.length > last_non_whitespace_utf16_offset + 1:
                fixed[index] = replace(
                    entity, length=last_non_whitespace_utf16_offset + 1 - entity.offset
                )
                need_sort = True
        if need_sort:
            fixed = list(_sort_entities(fixed))

        # Trimming at the start stops at the first entity. Its UTF-16 offset is compared
        # with a byte position, and the two agree over the spaces and line feeds passed.
        first_non_whitespaces_pos = 0
        first_entity_begin_pos = fixed[0].offset if fixed else len(result)
        while first_non_whitespaces_pos < first_entity_begin_pos and result[
            first_non_whitespaces_pos
        ] in (0x0A, 0x20):
            first_non_whitespaces_pos += 1
        if first_non_whitespaces_pos > 0:
            fixed_text = result[first_non_whitespaces_pos:]
            fixed = [
                replace(entity, offset=entity.offset - first_non_whitespaces_pos)
                for entity in fixed
            ]
        else:
            fixed_text = result

    if is_empty_string(fixed_text):
        if not allow_empty:
            return Failure(400, "Text must be non-empty")
        if not allow_empty_string:
            fixed_text = b""
            fixed = []

    if len(fixed_text) > _LENGTH_LIMIT:
        new_size = _LENGTH_LIMIT
        while not is_utf8_character_first_code_unit(fixed_text[new_size]):
            new_size -= 1
        fixed_text = fixed_text[:new_size]

        text_utf16_length = utf8_utf16_length(fixed_text)
        fixed = [
            entity
            for entity in fixed
            if entity.offset + entity.length <= text_utf16_length
        ]

    if not skip_new_entities:
        new_entities = find_entities(fixed_text, skip_bot_commands=skip_bot_commands)
        return FormattedText(fixed_text, _merge_new_entities(fixed, new_entities))
    return FormattedText(fixed_text, tuple(fixed))
