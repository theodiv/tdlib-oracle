# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's Markdown parsers: the text without its markup, and the entities they give.

Legacy Markdown nests no entity, so it checks each link once. In MarkdownV2, a link
without a URL after its text takes that text as its URL, as in the pinned code, so links
nested that way check the text once per level, in time that grows with the square of the
length of the text; the Bot API's 32,768-byte cap bounds it.
"""

from dataclasses import dataclass

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.custom_emoji_id import is_valid_custom_emoji_id
from tdlib_oracle.tdlib.formatted_date import is_valid_formatted_date
from tdlib_oracle.tdlib.link_manager import (
    get_checked_link,
    get_link_custom_emoji_id,
    get_link_formatted_date,
    get_link_user_id,
)
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    _sort_entities,
    type_name,
)
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tdlib_oracle.tdutils.misc import is_space
from tdlib_oracle.tdutils.utf8 import is_utf8_character_first_code_unit


# Ported from td/telegram/MessageEntity.cpp, parse_markdown().
def parse_markdown(text: bytes) -> FormattedText | Failure:
    """Return the text and entities `text` gives as legacy Markdown, or its `Failure`.

    A backslash keeps a `_`, `*`, backtick, or `[` after it as text, and stays before
    any other byte. Each of those four characters opens an entity, which the next of the
    same character closes, or the next `]` for a `[`, with every byte between kept as
    text: entities never nest, and nothing inside one escapes. Three backticks open a
    code block, which the next three close. The bytes after the opening name its
    language when a space, tab, CR, LF, vertical tab, or NUL ends them before any
    backtick and before the end of the text, and one line break right after the opening
    or the language goes. An entity that nothing closes refuses the text, naming the
    byte offset where it opens.

    A link takes the URL in parentheses after it, up to the next `)` or the end of the
    text. Without one, it takes its text past the first `n` bytes, followed by the
    text's last `n` bytes, where `n` counts the bytes the parser has dropped up to and
    including the `[`; once `n` reaches the text's length, the URL is the text itself.
    The pinned code reads that URL from the string it parses, after writing the kept
    text over its start. A `tg://user?id=` link to a valid user gives a mention of that
    user, and any other link gives a link in the form TDLib's link check keeps, or none
    when the check refuses it. An entity around no text gives none; after such a link,
    the URL in parentheses stays as text. The entities come back in the order of
    the text.
    """
    size = len(text)
    # Past the end, the C++ reads the string terminator.
    data = text + b"\x00"
    # The C++ writes the text it keeps over the string it parses, always behind the byte
    # it reads next, so a new buffer holds the same bytes, which the URL of a link reads
    # back below.
    result = bytearray()

    entities: list[MessageEntity] = []
    utf16_offset = 0
    i = 0
    while i < size:
        c = data[i]
        if c == 0x5C and data[i + 1] in b"_*`[":  # '\\'
            i += 1
            result.append(data[i])
            utf16_offset += 1
            i += 1
            continue
        if c not in b"_*`[":
            if is_utf8_character_first_code_unit(c):
                # A character of 4 bytes takes a surrogate pair, and any byte from 0xf0
                # up counts as leading one.
                utf16_offset += 1 + (c >= 0xF0)
            result.append(c)
            i += 1
            continue

        begin_pos = i
        end_character = 0x5D if c == 0x5B else c  # ']' for '['
        is_pre = False
        i += 1

        language = b""
        if c == 0x60 and data[i] == 0x60 and data[i + 1] == 0x60:  # '`'
            i += 2
            is_pre = True
            # The terminator counts as a space, so the language ends there.
            language_end = i
            while not is_space(data[language_end]) and data[language_end] != 0x60:
                language_end += 1
            if i != language_end and language_end < size and data[language_end] != 0x60:
                language = data[i:language_end]
                i = language_end
            # One line break right after the start or the language goes, whether "\n",
            # "\r", "\r\n", or "\n\r".
            if data[i] in b"\n\r":
                if data[i + 1] in b"\n\r" and data[i] != data[i + 1]:
                    i += 2
                else:
                    i += 1

        entity_offset = utf16_offset
        while i < size and (
            data[i] != end_character
            or (is_pre and not (data[i + 1] == 0x60 and data[i + 2] == 0x60))
        ):
            cur_ch = data[i]
            if is_utf8_character_first_code_unit(cur_ch):
                utf16_offset += 1 + (cur_ch >= 0xF0)
            result.append(cur_ch)
            i += 1
        if i == size:
            return Failure(
                400, f"Can't find end of the entity starting at byte offset {begin_pos}"
            )

        if entity_offset != utf16_offset:
            entity_length = utf16_offset - entity_offset
            match c:
                case 0x5F:  # '_'
                    entities.append(
                        MessageEntity(TYPE.ITALIC, entity_offset, entity_length)
                    )
                case 0x2A:  # '*'
                    entities.append(
                        MessageEntity(TYPE.BOLD, entity_offset, entity_length)
                    )
                case 0x5B:  # '['
                    if data[i + 1] != 0x28:  # '('
                        # The kept text up to its length, then the input past it.
                        kept = len(result)
                        overwritten = bytes(result[begin_pos + 1 : kept])
                        url = overwritten + data[max(begin_pos + 1, kept) : i]
                    else:
                        i += 2
                        url_end = data.find(b")", i, size)
                        if url_end < 0:
                            url_end = size
                        url = data[i:url_end]
                        i = url_end
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
                case _:  # '`'
                    if is_pre:
                        if not language:
                            entities.append(
                                MessageEntity(TYPE.PRE, entity_offset, entity_length)
                            )
                        else:
                            entities.append(
                                MessageEntity(
                                    TYPE.PRE_CODE,
                                    entity_offset,
                                    entity_length,
                                    language,
                                )
                            )
                    else:
                        entities.append(
                            MessageEntity(TYPE.CODE, entity_offset, entity_length)
                        )
        if is_pre:
            i += 2
        i += 1

    return FormattedText(bytes(result), tuple(entities))


# Ported from td/telegram/MessageEntity.cpp, EntityInfo in parse_markdown_v2().
@dataclass(frozen=True)
class _EntityInfo:
    type: int
    argument: bytes
    entity_offset: int
    entity_byte_offset: int
    entity_begin_pos: int


# Ported from td/telegram/MessageEntity.cpp, is_end_of_an_entity in parse_markdown_v2(),
# for a text that ends with the string terminator and an entity of `entity_type` open.
def _is_end_of_an_entity(
    data: bytes, i: int, entity_type: int, *, have_blockquote: bool
) -> bool:
    c = data[i]
    # Past the end, the terminator stands where a `>` would continue the blockquote.
    if have_blockquote and c == 0x0A and data[i + 1] != 0x3E:  # '\n', '>'
        return True
    match entity_type:
        case TYPE.BOLD:
            return c == 0x2A  # '*'
        case TYPE.ITALIC:
            return c == 0x5F and data[i + 1] != 0x5F  # '_'
        case TYPE.CODE:
            return c == 0x60  # '`'
        case TYPE.PRE | TYPE.PRE_CODE:
            return c == 0x60 and data[i + 1] == 0x60 and data[i + 2] == 0x60
        case TYPE.TEXT_URL | TYPE.CUSTOM_EMOJI:
            return c == 0x5D  # ']'
        case TYPE.UNDERLINE:
            return c == 0x5F and data[i + 1] == 0x5F
        case TYPE.STRIKETHROUGH:
            return c == 0x7E  # '~'
        case TYPE.SPOILER:
            return c == 0x7C and data[i + 1] == 0x7C  # '|'
        case _:  # TYPE.BLOCK_QUOTE, the last type an entity opens as
            return False


# Ported from td/telegram/MessageEntity.cpp, parse_markdown_v2(), its loop that reads
# the URL of a link or a custom emoji up to its `)`.
def _read_url(data: bytes, i: int) -> tuple[bytes, int]:
    """Return the URL that starts at `i` of `data`, unescaped, and where it stops.

    `data` ends with the string terminator, and the URL stops at the first `)` that no
    backslash escapes, or at the end of the text.
    """
    size = len(data) - 1
    url = bytearray()
    while i < size and data[i] != 0x29:  # ')'
        if data[i] == 0x5C and 0 < data[i + 1] <= 126:  # '\\'
            url.append(data[i + 1])
            i += 2
            continue
        url.append(data[i])
        i += 1
    return bytes(url), i


# Ported from td/telegram/MessageEntity.cpp, parse_markdown_v2(), its refusal of a
# character it reserves.
def _reserved(c: int) -> Failure:
    return Failure(
        400,
        f"Character '{chr(c)}' is reserved and must be escaped with the preceding '\\'",
    )


# Ported from td/telegram/MessageEntity.cpp, parse_markdown_v2(), its refusal of an
# entity it finds no end of.
def _unclosed(nested: _EntityInfo) -> Failure:
    return Failure(
        400,
        f"Can't find end of {type_name(nested.type)} entity at byte offset"
        f" {nested.entity_byte_offset}",
    )


# Ported from td/telegram/MessageEntity.cpp, parse_markdown_v2().
def parse_markdown_v2(text: bytes) -> FormattedText | Failure:
    """Return the text and entities `text` gives as MarkdownV2, or its `Failure`.

    A backslash keeps the ASCII character after it as text, NUL and DEL aside. Outside
    code, each other character MarkdownV2 reserves, such as `_`, `*`, `[`, or `.`, opens
    or closes an entity or refuses the text; inside code, only a backtick is reserved. A
    link takes the text it holds as its URL when no URL in parentheses follows, in the
    form TDLib's link check keeps, and gives no entity when the check refuses it; a
    `tg://user?id=` link gives a mention of that user instead. A custom emoji gives a
    custom emoji or a date by its `tg://emoji` or `tg://time` URL. A `>` at the start of
    a line opens a blockquote, which goes on while each next line starts with `>` and
    turns expandable when `||` ends it. An entity around no text gives none, though its
    URL is still checked. The entities come back sorted, each tie between entities that
    differ recorded in their `ties`.
    """
    size = len(text)
    # Past the end, the C++ reads the string terminator.
    data = text + b"\x00"
    # The C++ writes the text it keeps over the string it parses, always behind the byte
    # it reads next, so a new buffer holds the same bytes.
    result = bytearray()

    entities: list[MessageEntity] = []
    utf16_offset = 0
    nested_entities: list[_EntityInfo] = []

    have_blockquote = False
    can_start_blockquote = True
    i = 0
    while i < size:
        c = data[i]
        if c == 0x5C and 0 < data[i + 1] <= 126:  # '\\'
            i += 1
            utf16_offset += 1
            result.append(data[i])
            if data[i] != 0x0D:  # '\r'
                can_start_blockquote = data[i] == 0x0A  # '\n'
            i += 1
            continue

        reserved_characters = b"_*[]()~`>#+-=|{}.!\n"
        if nested_entities and nested_entities[-1].type in (
            TYPE.CODE,
            TYPE.PRE,
            TYPE.PRE_CODE,
        ):
            reserved_characters = b"`"

        if c not in reserved_characters:
            if is_utf8_character_first_code_unit(c):
                # A character of 4 bytes takes a surrogate pair, and any byte from 0xf0
                # up counts as leading one.
                utf16_offset += 1 + (c >= 0xF0)
                if c != 0x0D:  # '\r'
                    can_start_blockquote = False
            result.append(c)
            i += 1
            continue

        if not nested_entities or not _is_end_of_an_entity(
            data, i, nested_entities[-1].type, have_blockquote=have_blockquote
        ):
            entity_type: int
            argument = b""
            entity_byte_offset = i
            match c:
                case 0x5F:  # '_'
                    if data[i + 1] == 0x5F:
                        entity_type = TYPE.UNDERLINE
                        i += 1
                    else:
                        entity_type = TYPE.ITALIC
                case 0x2A:  # '*'
                    entity_type = TYPE.BOLD
                case 0x7E:  # '~'
                    entity_type = TYPE.STRIKETHROUGH
                case 0x7C:  # '|'
                    if data[i + 1] != 0x7C:
                        return _reserved(c)
                    i += 1
                    entity_type = TYPE.SPOILER
                case 0x5B:  # '['
                    entity_type = TYPE.TEXT_URL
                case 0x60:  # '`'
                    if data[i + 1] == 0x60 and data[i + 2] == 0x60:
                        i += 3
                        entity_type = TYPE.PRE
                        # The terminator counts as a space, so the language ends there.
                        language_end = i
                        while (
                            not is_space(data[language_end])
                            and data[language_end] != 0x60
                        ):
                            language_end += 1
                        if (
                            i != language_end
                            and language_end < size
                            and data[language_end] != 0x60
                        ):
                            entity_type = TYPE.PRE_CODE
                            argument = data[i:language_end]
                            i = language_end
                        # One line break right after the start or the language goes,
                        # whether "\n", "\r", "\r\n", or "\n\r".
                        if data[i] in b"\n\r":
                            if data[i + 1] in b"\n\r" and data[i] != data[i + 1]:
                                i += 2
                            else:
                                i += 1
                        i -= 1
                    else:
                        entity_type = TYPE.CODE
                case 0x21:  # '!'
                    if data[i + 1] != 0x5B:  # '['
                        return _reserved(c)
                    i += 1
                    entity_type = TYPE.CUSTOM_EMOJI
                case 0x0A:  # '\n'
                    utf16_offset += 1
                    result.append(0x0A)
                    can_start_blockquote = True
                    entity_type = TYPE.SIZE
                case 0x3E:  # '>'
                    if not can_start_blockquote:
                        return _reserved(c)
                    if have_blockquote:
                        entity_type = TYPE.SIZE
                    else:
                        entity_type = TYPE.BLOCK_QUOTE
                        have_blockquote = True
                case _:
                    return _reserved(c)
            # A line break, or a `>` that goes on with the blockquote, opens no entity.
            if entity_type != TYPE.SIZE:
                nested_entities.append(
                    _EntityInfo(
                        entity_type,
                        argument,
                        utf16_offset,
                        entity_byte_offset,
                        len(result),
                    )
                )
            i += 1
            continue

        entity_type = nested_entities[-1].type
        if c == 0x0A and entity_type != TYPE.BLOCK_QUOTE:  # '\n'
            # A line break that ends the blockquote closes only a spoiler that opened
            # right before it, which makes the blockquote expandable.
            spoiler = nested_entities[-1]
            if entity_type != TYPE.SPOILER or not (
                spoiler.entity_byte_offset == i - 2
                or (
                    spoiler.entity_byte_offset == i - 3
                    and result
                    and result[-1] == 0x0D  # '\r'
                )
            ):
                return _unclosed(spoiler)
            nested_entities.pop()
            # The blockquote stays open below the spoiler, which nests in no spoiler.
            if nested_entities[-1].type != TYPE.BLOCK_QUOTE:
                return _unclosed(nested_entities[-1])
            entity_type = TYPE.EXPANDABLE_BLOCK_QUOTE
        nested = nested_entities[-1]
        argument = nested.argument
        user_id = 0
        custom_emoji_id = 0
        date = 0
        date_flags = 0
        skip_entity = utf16_offset == nested.entity_offset
        match entity_type:
            case TYPE.BOLD | TYPE.ITALIC | TYPE.CODE | TYPE.STRIKETHROUGH:
                pass
            case TYPE.UNDERLINE | TYPE.SPOILER:
                i += 1
            case TYPE.PRE | TYPE.PRE_CODE:
                i += 2
            case TYPE.TEXT_URL:
                if data[i + 1] != 0x28:  # '('
                    url = bytes(result[nested.entity_begin_pos :])
                else:
                    url_begin_pos = i + 2
                    url, i = _read_url(data, url_begin_pos)
                    if data[i] != 0x29:  # ')'
                        return Failure(
                            400,
                            f"Can't find end of a URL at byte offset {url_begin_pos}",
                        )
                user_id = get_link_user_id(url)
                if not is_valid_user_id(user_id):
                    url = get_checked_link(url)
                    if url:
                        argument = url
                    else:
                        skip_entity = True
            case TYPE.CUSTOM_EMOJI:
                if data[i + 1] != 0x28:  # '('
                    return Failure(
                        400, "The entity must contain a tg://emoji or tg://time URL"
                    )
                url_begin_pos = i + 2
                url, i = _read_url(data, url_begin_pos)
                if data[i] != 0x29:  # ')'
                    return Failure(
                        400, f"Can't find end of a URL at byte offset {url_begin_pos}"
                    )
                emoji = get_link_custom_emoji_id(url)
                if not isinstance(emoji, Failure):
                    custom_emoji_id = emoji
                else:
                    formatted_date = get_link_formatted_date(url)
                    if isinstance(formatted_date, Failure):
                        return Failure(
                            400, "Invalid tg://emoji or tg://time URL specified"
                        )
                    date, date_flags = formatted_date
                    entity_type = TYPE.FORMATTED_DATE
            case _:  # TYPE.BLOCK_QUOTE or TYPE.EXPANDABLE_BLOCK_QUOTE
                # The line break that ends a blockquote belongs to it.
                have_blockquote = False
                result.append(c)
                can_start_blockquote = True
                utf16_offset += 1
                skip_entity = False

        if not skip_entity:
            entity_offset = nested.entity_offset
            entity_length = utf16_offset - entity_offset
            if is_valid_user_id(user_id):
                entities.append(
                    MessageEntity(
                        TYPE.MENTION_NAME, entity_offset, entity_length, user_id=user_id
                    )
                )
            elif is_valid_custom_emoji_id(custom_emoji_id):
                entities.append(
                    MessageEntity(
                        entity_type,
                        entity_offset,
                        entity_length,
                        custom_emoji_id=custom_emoji_id,
                    )
                )
            elif is_valid_formatted_date(date):
                entities.append(
                    MessageEntity(
                        entity_type,
                        entity_offset,
                        entity_length,
                        date=date,
                        date_flags=date_flags,
                    )
                )
            else:
                entities.append(
                    MessageEntity(entity_type, entity_offset, entity_length, argument)
                )
        nested_entities.pop()
        i += 1

    if have_blockquote:
        # A blockquote still open ends with the text, expandable when `||` ends it.
        entity_type = TYPE.BLOCK_QUOTE
        if (
            nested_entities[-1].type == TYPE.SPOILER
            and nested_entities[-1].entity_byte_offset == size - 2
        ):
            nested_entities.pop()
            entity_type = TYPE.EXPANDABLE_BLOCK_QUOTE
        if nested_entities[-1].type == TYPE.BLOCK_QUOTE:
            entity_offset = nested_entities[-1].entity_offset
            entity_length = utf16_offset - entity_offset
            if entity_length != 0:
                entities.append(
                    MessageEntity(entity_type, entity_offset, entity_length)
                )
            nested_entities.pop()
    if nested_entities:
        return _unclosed(nested_entities[-1])

    return FormattedText(bytes(result), _sort_entities(entities))
