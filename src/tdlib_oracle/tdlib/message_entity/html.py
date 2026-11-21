# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's HTML parser: the text without its tags, and the entities the tags give.

An `<a>` without `href` takes the text it holds as its link, as in the pinned code, so
links nested that way check that text once per level, in time that grows with the square
of the length of the text; the Bot API's 32,768-byte cap bounds it.
"""

from dataclasses import dataclass, replace

from tdlib_oracle.runtime.failure import Failure, decode_quoted
from tdlib_oracle.tdlib.formatted_date import get_date_flags
from tdlib_oracle.tdlib.link_manager import get_checked_link, get_link_user_id
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    _sort_entities,
)
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tdlib_oracle.tdutils.misc import (
    hex_to_int,
    is_alnum,
    is_alpha,
    is_digit,
    is_hex_digit,
    is_space,
    to_integer,
    to_integer_safe,
)
from tdlib_oracle.tdutils.utf8 import (
    append_utf8_character,
    check_utf8,
    is_utf8_character_first_code_unit,
)

# The characters is_space() accepts, for the tests of a byte against them all at once.
_SPACES = bytes(c for c in range(256) if is_space(c))

# Ported from td/telegram/MessageEntity.cpp, the characters besides spaces that end an
# attribute name in parse_html().
_ATTRIBUTE_NAME_ENDS = _SPACES + b"=>/\"'"

# Ported from td/telegram/MessageEntity.cpp, the tag names parse_html() supports.
_TAG_NAMES = frozenset(
    (
        b"a",
        b"b",
        b"strong",
        b"i",
        b"em",
        b"s",
        b"strike",
        b"del",
        b"u",
        b"ins",
        b"tg-spoiler",
        b"tg-emoji",
        b"tg-time",
        b"span",
        b"pre",
        b"code",
        b"blockquote",
    )
)


# Ported from td/telegram/MessageEntity.cpp, decode_html_entity().
def _decode_html_entity(text: bytes, pos: int) -> tuple[int, int]:  # noqa: PLR0912  # mirrors upstream
    """Return the code point of the reference at `pos` of `text`, and where it ends.

    `text` ends with the string terminator, and `pos` holds an `&`. A reference that
    decodes to no character gives 0, and `pos` as its end.
    """
    end_pos = pos + 1
    res = 0
    if text[pos + 1] == 0x23:  # '#'
        end_pos += 1
        # Either base reads its digits into a 32-bit unsigned integer, which
        # wraps around.
        if text[pos + 2] in b"xX":
            end_pos += 1
            while is_hex_digit(text[end_pos]):
                res = (res * 16 + hex_to_int(text[end_pos])) & 0xFFFFFFFF
                end_pos += 1
        else:
            while is_digit(text[end_pos]):
                res = (res * 10 + text[end_pos] - 0x30) & 0xFFFFFFFF
                end_pos += 1
        if res == 0 or res >= 0x10FFFF or end_pos - pos >= 10:
            return 0, pos
    else:
        while is_alpha(text[end_pos]):
            end_pos += 1
        match text[pos + 1 : end_pos]:
            case b"lt":
                res = 0x3C  # '<'
            case b"gt":
                res = 0x3E  # '>'
            case b"amp":
                res = 0x26  # '&'
            case b"quot":
                res = 0x22  # '"'
            case _:
                return 0, pos

    if text[end_pos] == 0x3B:  # ';'
        return res, end_pos + 1
    return res, end_pos


# Ported from td/telegram/MessageEntity.cpp, EntityInfo in parse_html().
@dataclass(frozen=True)
class _EntityInfo:
    tag_name: bytes
    argument: bytes
    date: int
    entity_offset: int
    entity_begin_pos: int


# Ported from td/telegram/MessageEntity.cpp, parse_html().
def parse_html(text: bytes) -> FormattedText | Failure:  # noqa: PLR0911, PLR0912, PLR0915  # mirrors upstream
    """Return the text and entities `text` gives as HTML, or the `Failure` refusing it.

    The tags are removed, and the references `&lt;`, `&gt;`, `&amp;`, and `&quot;` and
    numeric character references are decoded; any other `&` stays. An element that holds
    text gives the entity of its tag, and one that holds none gives none and is not
    checked. An `<a>` gives a link to its `href`, or to the text it holds without one,
    in the form TDLib's link check keeps, or no entity when the check refuses it; a
    `tg://user?id=` link gives a mention of that user instead. A `<code>` with a
    language right inside or around a `<pre>` of the same text gives a code block. A
    numeric reference to a surrogate refuses the text, except in an attribute. The
    entities come back sorted, each tie between entities that differ recorded in their
    `ties`.

    A message quotes a tag name decoded with `surrogateescape`, since only a text that
    is not UTF-8, which TDLib refuses before parsing, gives one that UTF-8 does
    not decode.
    """
    str_size = len(text)
    # Past the end, the C++ reads the string terminator.
    data = text + b"\x00"
    # The C++ writes the text it keeps, and each attribute value it decodes, over the
    # string it parses, always behind the byte it reads next, so new buffers hold the
    # same bytes.
    result = bytearray()

    entities: list[MessageEntity] = []
    utf16_offset = 0
    need_recheck_utf8 = False
    nested_entities: list[_EntityInfo] = []

    i = 0
    while i < str_size:
        c = data[i]
        if c == 0x26:  # '&'
            code, end_pos = _decode_html_entity(data, i)
            if code != 0:
                utf16_offset += 1 + (code > 0xFFFF)
                if 0xD800 <= code <= 0xDFFF:
                    need_recheck_utf8 = True
                append_utf8_character(result, code)
                i = end_pos
                continue
        if c != 0x3C:  # '<'
            if is_utf8_character_first_code_unit(c):
                # A character of 4 bytes takes a surrogate pair, and any byte from 0xf0
                # up counts as leading one.
                utf16_offset += 1 + (c >= 0xF0)
            result.append(c)
            i += 1
            continue

        begin_pos = i
        i += 1
        if data[i] != 0x2F:  # '/'
            while data[i] not in _SPACES and data[i] != 0x3E:  # '>'
                i += 1
            if data[i] == 0:
                return Failure(400, f"Unclosed start tag at byte offset {begin_pos}")

            tag_name = data[begin_pos + 1 : i].lower()
            if tag_name not in _TAG_NAMES:
                return Failure(
                    400,
                    f'Unsupported start tag "{decode_quoted(tag_name)}" at byte offset'
                    f" {begin_pos}",
                )

            argument = b""
            date = 0
            while data[i] != 0x3E:  # '>'
                while data[i] != 0 and data[i] in _SPACES:
                    i += 1
                if data[i] == 0x3E:  # '>'
                    break
                attribute_begin_pos = i
                while data[i] not in _ATTRIBUTE_NAME_ENDS:
                    i += 1
                attribute_name = data[attribute_begin_pos:i]
                if not attribute_name:
                    return Failure(
                        400,
                        "Empty attribute name in the tag"
                        f' "{decode_quoted(tag_name)}" at byte offset {begin_pos}',
                    )
                while data[i] != 0 and data[i] in _SPACES:
                    i += 1
                if data[i] != 0x3D:  # '='
                    if data[i] == 0:
                        return Failure(
                            400,
                            f'Unclosed start tag "{decode_quoted(tag_name)}" at byte'
                            f" offset {begin_pos}",
                        )
                    if tag_name == b"blockquote" and attribute_name == b"expandable":
                        argument = b"1"
                    continue
                i += 1
                while data[i] != 0 and data[i] in _SPACES:
                    i += 1
                if data[i] == 0:
                    return Failure(
                        400,
                        f'Unclosed start tag "{decode_quoted(tag_name)}" at byte offset'
                        f" {begin_pos}",
                    )

                if data[i] not in b"'\"":
                    # A name token, of letters, digits, periods, and hyphens, which is
                    # not case-sensitive.
                    token_begin_pos = i
                    while is_alnum(data[i]) or data[i] in b".-":
                        i += 1
                    attribute_value = data[token_begin_pos:i].lower()

                    if data[i] not in _SPACES and data[i] != 0x3E:  # '>'
                        return Failure(
                            400,
                            "Unexpected end of name token at byte offset"
                            f" {token_begin_pos}",
                        )
                else:
                    end_character = data[i]
                    i += 1
                    value = bytearray()
                    while data[i] != end_character and data[i] != 0:
                        if data[i] == 0x26:  # '&'
                            code, end_pos = _decode_html_entity(data, i)
                            if code != 0:
                                append_utf8_character(value, code)
                                i = end_pos
                                continue
                        value.append(data[i])
                        i += 1
                    if data[i] == end_character:
                        i += 1
                    attribute_value = bytes(value)
                if data[i] == 0:
                    return Failure(
                        400, f"Unclosed start tag at byte offset {begin_pos}"
                    )

                if tag_name == b"a" and attribute_name == b"href":
                    argument = attribute_value
                elif (
                    tag_name == b"code"
                    and attribute_name == b"class"
                    and attribute_value.startswith(b"language-")
                ):
                    argument = attribute_value[9:]
                elif (
                    tag_name == b"span"
                    and attribute_name == b"class"
                    and attribute_value.startswith(b"tg-")
                ):
                    argument = attribute_value[3:]
                elif tag_name == b"tg-emoji" and attribute_name == b"emoji-id":
                    argument = attribute_value
                elif tag_name == b"blockquote" and attribute_name == b"expandable":
                    argument = b"1"
                elif tag_name == b"tg-time" and attribute_name == b"unix":
                    date = to_integer(attribute_value, 32)
                elif tag_name == b"tg-time" and attribute_name == b"format":
                    argument = attribute_value

            if tag_name == b"span" and argument != b"spoiler":
                return Failure(
                    400,
                    'Tag "span" must have class "tg-spoiler" at byte offset'
                    f" {begin_pos}",
                )

            nested_entities.append(
                _EntityInfo(tag_name, argument, date, utf16_offset, len(result))
            )
        else:
            if not nested_entities:
                return Failure(400, f"Unexpected end tag at byte offset {begin_pos}")

            while data[i] not in _SPACES and data[i] != 0x3E:  # '>'
                i += 1
            end_tag_name = data[begin_pos + 2 : i].lower()
            while data[i] in _SPACES and data[i] != 0:
                i += 1
            if data[i] != 0x3E:  # '>'
                return Failure(400, f"Unclosed end tag at byte offset {begin_pos}")

            nested = nested_entities[-1]
            tag_name = nested.tag_name
            if end_tag_name and end_tag_name != tag_name:
                return Failure(
                    400,
                    f"Unmatched end tag at byte offset {begin_pos}, expected"
                    f' "</{decode_quoted(tag_name)}>", found'
                    f' "</{decode_quoted(end_tag_name)}>"',
                )

            if utf16_offset > nested.entity_offset:
                entity_offset = nested.entity_offset
                entity_length = utf16_offset - entity_offset
                match tag_name:
                    case b"i" | b"em":
                        entities.append(
                            MessageEntity(TYPE.ITALIC, entity_offset, entity_length)
                        )
                    case b"b" | b"strong":
                        entities.append(
                            MessageEntity(TYPE.BOLD, entity_offset, entity_length)
                        )
                    case b"s" | b"strike" | b"del":
                        entities.append(
                            MessageEntity(
                                TYPE.STRIKETHROUGH, entity_offset, entity_length
                            )
                        )
                    case b"u" | b"ins":
                        entities.append(
                            MessageEntity(TYPE.UNDERLINE, entity_offset, entity_length)
                        )
                    case b"tg-spoiler" | b"span":
                        # A span opens only with the class tg-spoiler.
                        entities.append(
                            MessageEntity(TYPE.SPOILER, entity_offset, entity_length)
                        )
                    case b"tg-emoji":
                        document_id = to_integer_safe(nested.argument, 64)
                        if document_id is None or document_id == 0:
                            return Failure(
                                400, "Invalid custom emoji identifier specified"
                            )
                        entities.append(
                            MessageEntity(
                                TYPE.CUSTOM_EMOJI,
                                entity_offset,
                                entity_length,
                                custom_emoji_id=document_id,
                            )
                        )
                    case b"tg-time":
                        # FormattedDate::get_formatted_date() keeps the date with the
                        # flags of its format.
                        date_flags = get_date_flags(nested.argument)
                        if isinstance(date_flags, Failure):
                            return date_flags
                        if nested.date > 0:
                            entities.append(
                                MessageEntity(
                                    TYPE.FORMATTED_DATE,
                                    entity_offset,
                                    entity_length,
                                    date=nested.date,
                                    date_flags=date_flags,
                                )
                            )
                    case b"a":
                        url = nested.argument
                        if not url:
                            url = bytes(result[nested.entity_begin_pos :])
                        user_id = get_link_user_id(url)
                        if is_valid_user_id(user_id):
                            entities.append(
                                MessageEntity(
                                    TYPE.MENTION_NAME,
                                    entity_offset,
                                    entity_length,
                                    user_id=user_id,
                                )
                            )
                        else:
                            url = get_checked_link(url)
                            if url:
                                entities.append(
                                    MessageEntity(
                                        TYPE.TEXT_URL, entity_offset, entity_length, url
                                    )
                                )
                    case b"pre":
                        if (
                            entities
                            and entities[-1].type == TYPE.CODE
                            and entities[-1].offset == entity_offset
                            and entities[-1].length == entity_length
                            and entities[-1].argument
                        ):
                            entities[-1] = replace(entities[-1], type=TYPE.PRE_CODE)
                        else:
                            entities.append(
                                MessageEntity(TYPE.PRE, entity_offset, entity_length)
                            )
                    case b"code":
                        if (
                            entities
                            and entities[-1].type == TYPE.PRE
                            and entities[-1].offset == entity_offset
                            and entities[-1].length == entity_length
                            and nested.argument
                        ):
                            entities[-1] = replace(
                                entities[-1],
                                type=TYPE.PRE_CODE,
                                argument=nested.argument,
                            )
                        else:
                            entities.append(
                                MessageEntity(
                                    TYPE.CODE,
                                    entity_offset,
                                    entity_length,
                                    nested.argument,
                                )
                            )
                    case _:  # b"blockquote", the last tag name left
                        if nested.argument:
                            entity_type = TYPE.EXPANDABLE_BLOCK_QUOTE
                        else:
                            entity_type = TYPE.BLOCK_QUOTE
                        entities.append(
                            MessageEntity(entity_type, entity_offset, entity_length)
                        )
            nested_entities.pop()
        i += 1

    if nested_entities:
        return Failure(
            400,
            "Can't find end tag corresponding to start tag"
            f' "{decode_quoted(nested_entities[-1].tag_name)}"',
        )

    # A code entity keeps its language only once it makes a code block with a pre.
    entities = [
        replace(entity, argument=b"")
        if entity.type == TYPE.CODE and entity.argument
        else entity
        for entity in entities
    ]

    sorted_entities = _sort_entities(entities)

    kept = bytes(result)
    if need_recheck_utf8 and not check_utf8(kept):
        return Failure(
            400,
            "Text contains invalid Unicode characters after decoding HTML entities,"
            " check for unmatched surrogate code units",
        )
    return FormattedText(kept, sorted_entities)
