# Ported from td/generate/scheme/telegram_api.tl of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Telegram's API objects for the entities TDLib sends with a text and reads back.

A `string` is `bytes`, as TDLib takes it, a field that holds an object may also hold
`None`, as a null pointer, and a `flags:#` field is the `int` the C++ holds, `0` in each
object TDLib builds, since writing the object adds the bit of each flag that is set. An
entity's `offset` and `length` count UTF-16 code units, and its last field, `ties`, is
the port's own: the objects the tie of the entity it was made from converts to, each
once, any of which the pinned code may hold in its place, or empty when they are fewer
than two, so that a tie survives the conversions to these objects and back.
"""

from dataclasses import dataclass


# Ported from td/generate/scheme/telegram_api.tl, inputUser.
@dataclass(frozen=True)
class InputUser:
    """A user, by ID and the access hash that lets a client name the user."""

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
    """A preformatted block, of code in a programming language when it names one."""

    offset: int
    length: int
    language: bytes
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityTextUrl.
@dataclass(frozen=True)
class MessageEntityTextUrl:
    """A text that opens a link."""

    offset: int
    length: int
    url: bytes
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityMentionName.
@dataclass(frozen=True)
class MessageEntityMentionName:
    """A text that mentions a user by ID, as Telegram returns it."""

    offset: int
    length: int
    user_id: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, inputMessageEntityMentionName.
@dataclass(frozen=True)
class InputMessageEntityMentionName:
    """A text that mentions a user, as a client sends it."""

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
    """A custom emoji shown in place of the emoji it covers."""

    offset: int
    length: int
    document_id: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityBlockquote.
@dataclass(frozen=True)
class MessageEntityBlockquote:
    """A blockquote, which a collapsed one shows in three lines until expanded."""

    flags: int
    collapsed: bool
    offset: int
    length: int
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/generate/scheme/telegram_api.tl, messageEntityFormattedDate.
@dataclass(frozen=True)
class MessageEntityFormattedDate:
    """A date and time shown in the reader's own form, in the parts its flags name."""

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
