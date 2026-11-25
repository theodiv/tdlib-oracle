# Ported from td/generate/scheme/telegram_api.tl of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Telegram's API objects for the entities TDLib sends with a text and reads back.

Each class stands for the constructor of its name, first letter aside, and the union for
an abstract type, of the constructors ported; `InputUser`, whose one ported constructor
shares its name, stands for its type too. A `string` is `bytes`, as TDLib takes it, a
`flags:#` field is the `int` the C++ holds, and a field that holds an object may also
hold `None`, as a null pointer. An entity's `offset` and `length` count UTF-16 code
units. Its last field, `ties`, is the port's own: when the entity was made from one in a
tie with entities that differ from it, the objects of that tie, each once, any of which
the pinned code may hold in its place, and empty otherwise. It carries the tie as
`MessageEntity.ties` does, so that a tie survives the conversions to these objects
and back.
"""

from dataclasses import dataclass


# Ported from td/generate/scheme/telegram_api.tl, inputUser.
@dataclass(frozen=True)
class InputUser:
    """A user, by ID and the access hash that lets a client name the user.

    Attributes:
        user_id: The user.
        access_hash: The access hash Telegram gave the client for the user, or `0`.
    """

    user_id: int
    access_hash: int


# Ported from td/generate/scheme/telegram_api.tl, messageEntityBold.
@dataclass(frozen=True)
class MessageEntityBold:
    """Bold text."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityItalic.
@dataclass(frozen=True)
class MessageEntityItalic:
    """Italic text."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityCode.
@dataclass(frozen=True)
class MessageEntityCode:
    """An inline piece of code."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityPre.
@dataclass(frozen=True)
class MessageEntityPre:
    """A preformatted block, of code in a programming language when it names one.

    Attributes:
        language: The programming language, or empty for none.
    """

    offset: int
    length: int
    language: bytes
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityTextUrl.
@dataclass(frozen=True)
class MessageEntityTextUrl:
    """A text that opens a link.

    Attributes:
        url: The link it opens.
    """

    offset: int
    length: int
    url: bytes
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityMentionName.
@dataclass(frozen=True)
class MessageEntityMentionName:
    """A text that mentions a user by ID, as Telegram returns it.

    Attributes:
        user_id: The user it mentions.
    """

    offset: int
    length: int
    user_id: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, inputMessageEntityMentionName.
@dataclass(frozen=True)
class InputMessageEntityMentionName:
    """A text that mentions a user, as a client sends it.

    Attributes:
        user_id: The user it mentions, or `None`.
    """

    offset: int
    length: int
    user_id: InputUser | None
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityUnderline.
@dataclass(frozen=True)
class MessageEntityUnderline:
    """Underlined text."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityStrike.
@dataclass(frozen=True)
class MessageEntityStrike:
    """Struck-through text."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntitySpoiler.
@dataclass(frozen=True)
class MessageEntitySpoiler:
    """A spoiler, hidden until the reader reveals it."""

    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityCustomEmoji.
@dataclass(frozen=True)
class MessageEntityCustomEmoji:
    """A custom emoji shown in place of the emoji it covers.

    Attributes:
        document_id: The custom emoji it shows.
    """

    offset: int
    length: int
    document_id: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityBlockquote.
@dataclass(frozen=True)
class MessageEntityBlockquote:
    """A blockquote, which a collapsed one shows in three lines until expanded.

    Attributes:
        flags: The `flags:#` field as the object holds it, `0` in each one TDLib builds;
            writing the object adds the bit of `collapsed`.
        collapsed: Whether the blockquote shows collapsed.
    """

    flags: int
    collapsed: bool
    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityFormattedDate.
@dataclass(frozen=True)
class MessageEntityFormattedDate:
    """A date and time shown in the reader's own form, in the parts its flags name.

    Attributes:
        flags: The `flags:#` field as the object holds it, `0` in each one TDLib builds;
            writing the object adds the bit of each part it shows.
        relative: Whether the date shows relative to the present.
        short_time: Whether the time shows in short.
        long_time: Whether the time shows in full.
        short_date: Whether the date shows in short.
        long_date: Whether the date shows in full.
        day_of_week: Whether the day of the week shows.
        date: The date and time, as a Unix time.
    """

    flags: int
    relative: bool
    short_time: bool
    long_time: bool
    short_date: bool
    long_date: bool
    day_of_week: bool
    offset: int
    length: int
    date: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, MessageEntity.
MessageEntity = (
    MessageEntityBold
    | MessageEntityItalic
    | MessageEntityCode
    | MessageEntityPre
    | MessageEntityTextUrl
    | MessageEntityMentionName
    | InputMessageEntityMentionName
    | MessageEntityUnderline
    | MessageEntityStrike
    | MessageEntitySpoiler
    | MessageEntityCustomEmoji
    | MessageEntityBlockquote
    | MessageEntityFormattedDate
)
