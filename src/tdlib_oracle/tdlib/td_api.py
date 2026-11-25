# Ported from td/generate/scheme/td_api.tl of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's API objects that the ports exchange: formatted texts, requests, and errors.

Each class stands for the constructor of its name, first letter aside, and each union
for an abstract type, of the constructors ported. A `string` is `bytes`, as TDLib takes
it, and a field that holds an object may also hold `None`, as a null pointer.
"""

from dataclasses import dataclass


# Ported from td/generate/scheme/td_api.tl, dateTimePartPrecisionNone.
@dataclass(frozen=True)
class DateTimePartPrecisionNone:
    """A date or time left out."""


# Ported from td/generate/scheme/td_api.tl, dateTimePartPrecisionShort.
@dataclass(frozen=True)
class DateTimePartPrecisionShort:
    """A date or time shown in short, such as 17.03.22 or 22:45."""


# Ported from td/generate/scheme/td_api.tl, dateTimePartPrecisionLong.
@dataclass(frozen=True)
class DateTimePartPrecisionLong:
    """A date or time shown in full, such as March 17, 2022 or 22:45:00."""


# Ported from td/generate/scheme/td_api.tl, DateTimePartPrecision.
DateTimePartPrecision = (
    DateTimePartPrecisionNone | DateTimePartPrecisionShort | DateTimePartPrecisionLong
)


# Ported from td/generate/scheme/td_api.tl, dateTimeFormattingTypeRelative.
@dataclass(frozen=True)
class DateTimeFormattingTypeRelative:
    """A date and time shown relative to the present, such as in 5 minutes."""


# Ported from td/generate/scheme/td_api.tl, dateTimeFormattingTypeAbsolute.
@dataclass(frozen=True)
class DateTimeFormattingTypeAbsolute:
    """A date and time shown as they are, each part with its precision.

    Attributes:
        time_precision: How the time of day shows, or `None`.
        date_precision: How the date shows, or `None`.
        show_day_of_week: Whether the day of the week shows.
    """

    time_precision: DateTimePartPrecision | None
    date_precision: DateTimePartPrecision | None
    show_day_of_week: bool


# Ported from td/generate/scheme/td_api.tl, DateTimeFormattingType.
DateTimeFormattingType = DateTimeFormattingTypeRelative | DateTimeFormattingTypeAbsolute


# Ported from td/generate/scheme/td_api.tl, textEntityTypeMention.
@dataclass(frozen=True)
class TextEntityTypeMention:
    """A mention of a user, a supergroup, or a channel by its username."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeHashtag.
@dataclass(frozen=True)
class TextEntityTypeHashtag:
    """A hashtag."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeCashtag.
@dataclass(frozen=True)
class TextEntityTypeCashtag:
    """A cashtag, such as $USD."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeBotCommand.
@dataclass(frozen=True)
class TextEntityTypeBotCommand:
    """A bot command."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeUrl.
@dataclass(frozen=True)
class TextEntityTypeUrl:
    """A link written out in the text."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeEmailAddress.
@dataclass(frozen=True)
class TextEntityTypeEmailAddress:
    """An email address."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypePhoneNumber.
@dataclass(frozen=True)
class TextEntityTypePhoneNumber:
    """A phone number."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeBankCardNumber.
@dataclass(frozen=True)
class TextEntityTypeBankCardNumber:
    """A bank card number."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeTonAddress.
@dataclass(frozen=True)
class TextEntityTypeTonAddress:
    """An address in the TON blockchain."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeBold.
@dataclass(frozen=True)
class TextEntityTypeBold:
    """A bold text."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeItalic.
@dataclass(frozen=True)
class TextEntityTypeItalic:
    """An italic text."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeUnderline.
@dataclass(frozen=True)
class TextEntityTypeUnderline:
    """An underlined text."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeStrikethrough.
@dataclass(frozen=True)
class TextEntityTypeStrikethrough:
    """A struck-through text."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeSpoiler.
@dataclass(frozen=True)
class TextEntityTypeSpoiler:
    """A spoiler."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeCode.
@dataclass(frozen=True)
class TextEntityTypeCode:
    """An inline piece of code."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypePre.
@dataclass(frozen=True)
class TextEntityTypePre:
    """A preformatted block."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypePreCode.
@dataclass(frozen=True)
class TextEntityTypePreCode:
    """A block of code in a programming language.

    Attributes:
        language: The programming language, as the sender names it.
    """

    language: bytes


# Ported from td/generate/scheme/td_api.tl, textEntityTypeBlockQuote.
@dataclass(frozen=True)
class TextEntityTypeBlockQuote:
    """A blockquote."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeExpandableBlockQuote.
@dataclass(frozen=True)
class TextEntityTypeExpandableBlockQuote:
    """A blockquote shown collapsed to three lines until expanded."""


# Ported from td/generate/scheme/td_api.tl, textEntityTypeTextUrl.
@dataclass(frozen=True)
class TextEntityTypeTextUrl:
    """A text that opens a link.

    Attributes:
        url: The link it opens.
    """

    url: bytes


# Ported from td/generate/scheme/td_api.tl, textEntityTypeMentionName.
@dataclass(frozen=True)
class TextEntityTypeMentionName:
    """A text that mentions a user by ID.

    Attributes:
        user_id: The user it mentions.
    """

    user_id: int


# Ported from td/generate/scheme/td_api.tl, textEntityTypeCustomEmoji.
@dataclass(frozen=True)
class TextEntityTypeCustomEmoji:
    """A custom emoji shown in place of the emoji it covers.

    Attributes:
        custom_emoji_id: The custom emoji it shows.
    """

    custom_emoji_id: int


# Ported from td/generate/scheme/td_api.tl, textEntityTypeMediaTimestamp.
@dataclass(frozen=True)
class TextEntityTypeMediaTimestamp:
    """A point of a video or audio to play from.

    Attributes:
        media_timestamp: The point to play from, in seconds.
    """

    media_timestamp: int


# Ported from td/generate/scheme/td_api.tl, textEntityTypeDateTime.
@dataclass(frozen=True)
class TextEntityTypeDateTime:
    """A date and time shown in the reader's own form.

    Attributes:
        unix_time: The date and time, as a Unix time.
        formatting_type: How the date and time show, or `None` to leave the text as
            it is.
    """

    unix_time: int
    formatting_type: DateTimeFormattingType | None


# Ported from td/generate/scheme/td_api.tl, TextEntityType.
TextEntityType = (
    TextEntityTypeMention
    | TextEntityTypeHashtag
    | TextEntityTypeCashtag
    | TextEntityTypeBotCommand
    | TextEntityTypeUrl
    | TextEntityTypeEmailAddress
    | TextEntityTypePhoneNumber
    | TextEntityTypeBankCardNumber
    | TextEntityTypeTonAddress
    | TextEntityTypeBold
    | TextEntityTypeItalic
    | TextEntityTypeUnderline
    | TextEntityTypeStrikethrough
    | TextEntityTypeSpoiler
    | TextEntityTypeCode
    | TextEntityTypePre
    | TextEntityTypePreCode
    | TextEntityTypeBlockQuote
    | TextEntityTypeExpandableBlockQuote
    | TextEntityTypeTextUrl
    | TextEntityTypeMentionName
    | TextEntityTypeCustomEmoji
    | TextEntityTypeMediaTimestamp
    | TextEntityTypeDateTime
)


# Ported from td/generate/scheme/td_api.tl, textEntity.
@dataclass(frozen=True)
class TextEntity:
    """A part of a text formatted in some way.

    `ties` is the port's own: it carries the tie of the entity the object was made from,
    as `MessageEntity.ties` does, so that a tie survives the conversion to TDLib's API
    objects and back.

    Attributes:
        offset: Where the entity starts, in UTF-16 code units.
        length: The length of the entity, in UTF-16 code units.
        type: The type of the entity, or `None`.
        ties: When the entity was made from one in a tie with entities that differ from
            it, the objects of that tie, each once; the pinned code may hold any of them
            in this object's place. Empty otherwise.
    """

    offset: int
    length: int
    type: TextEntityType | None
    ties: tuple["TextEntity", ...] = ()


# Ported from td/generate/scheme/td_api.tl, formattedText.
@dataclass(frozen=True)
class FormattedText:
    """A text and its formatting entities.

    Attributes:
        text: The text, in UTF-8.
        entities: The formatting entities of `text`, each of which may be `None`.
    """

    text: bytes
    entities: tuple[TextEntity | None, ...]


# Ported from td/generate/scheme/td_api.tl, textParseModeMarkdown.
@dataclass(frozen=True)
class TextParseModeMarkdown:
    """The Bot API's Markdown parse modes, by the version of the parser.

    Attributes:
        version: The version of the parser: 0 or 1 for the Bot API's `Markdown` parse
            mode, and 2 for `MarkdownV2`.
    """

    version: int


# Ported from td/generate/scheme/td_api.tl, textParseModeHTML.
@dataclass(frozen=True)
class TextParseModeHTML:
    """The Bot API's HTML parse mode."""


# Ported from td/generate/scheme/td_api.tl, TextParseMode.
TextParseMode = TextParseModeMarkdown | TextParseModeHTML


# Ported from td/generate/scheme/td_api.tl, parseTextEntities.
@dataclass(frozen=True)
class ParseTextEntities:
    """A request for the entities that the markup of a text gives.

    Attributes:
        text: The marked-up text.
        parse_mode: The markup the text is written in, or `None`.
    """

    text: bytes
    parse_mode: TextParseMode | None


# Ported from td/generate/scheme/td_api.tl, error.
@dataclass(frozen=True)
class Error:
    """The error TDLib answers a request with.

    Attributes:
        code: The error code, such as `400`.
        message: The error message.
    """

    code: int
    message: bytes
