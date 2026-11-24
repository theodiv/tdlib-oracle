# Ported from telegram-bot-api/Client.cpp of the Telegram Bot API server at the commit
# in tdlib_oracle.BOT_API_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The Bot API server's handling of a text before TDLib, its errors, and its entities.

The server checks a text and parses its markup with TDLib's synchronous
`parseTextEntities` request, describes each error for the client, and writes each
entity TDLib gives it as a `MessageEntity` object.
"""

from collections.abc import Callable
from dataclasses import dataclass

from tdlib_oracle.runtime.failure import Failure, decode_quoted
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdutils.misc import to_lower

# Ported from telegram-bot-api/Client.cpp, Client::execute(), the call it makes into
# TDLib, for the one request a text sends.
Execute = Callable[[td_api.ParseTextEntities], td_api.FormattedText | td_api.Error]

# Ported from telegram-bot-api/Client.cpp, Client::get_formatted_text(), the limit it
# puts on a text.
_MAX_TEXT_SIZE = 1 << 15  # 32,768 bytes


# Ported from telegram-bot-api/Client.cpp, Client::get_formatted_text(), for a text
# without entities, in the HTML parse mode or in none.
def get_formatted_text(
    text: bytes, parse_mode: bytes, *, execute: Execute
) -> td_api.FormattedText | Failure:
    """Return the formatted text the Bot API server passes on, or its `Failure`.

    A text over 32,768 bytes is refused. An empty text, or one whose parse mode is empty
    or `none` in any letter case, passes on without entities. In the HTML parse mode,
    `execute`, the call `Client::execute()` makes, asks TDLib to parse the text, and
    TDLib's error refuses it; any other parse mode is refused. The Markdown parse modes
    are left out, so a caller must not pass their names.
    """
    if len(text) > _MAX_TEXT_SIZE:
        return Failure(400, "Text is too long")

    parse_mode = parse_mode.lower()
    if text and parse_mode and parse_mode != b"none":
        if parse_mode != b"html":
            return Failure(400, "Unsupported parse_mode")
        parsed_text = execute(
            td_api.ParseTextEntities(text, td_api.TextParseModeHTML())
        )
        if isinstance(parsed_text, td_api.Error):
            return Failure(parsed_text.code, decode_quoted(parsed_text.message))
        return parsed_text

    return td_api.FormattedText(text, ())


# Ported from telegram-bot-api/Client.cpp, Client::get_input_message_text(td::string
# text, ...), for a text without link preview options or entities, as the formatted
# text of the inputMessageText it makes.
def get_input_message_text(
    text: bytes, parse_mode: bytes, *, execute: Execute
) -> td_api.FormattedText | Failure:
    """Return the formatted text the Bot API server sends TDLib, or its `Failure`.

    An empty text is refused first. Without link preview options, the `inputMessageText`
    the server makes holds nothing else a bot's message depends on, so its formatted
    text alone comes back.
    """
    if not text:
        return Failure(400, "Message text is empty")
    return get_formatted_text(text, parse_mode, execute=execute)


# Ported from telegram-bot-api/Client.cpp,
# Client::fail_query_with_error(PromisedQueryPtr query, int32 error_code, ...), without
# the rate-limit branch and the table of backend errors, which no check of a
# text reaches.
def get_error_description(failure: Failure) -> str:
    """Return the error description the Bot API server gives a client for `failure`."""
    code = failure.code
    message = failure.message
    if code < 400 or code == 404:
        code = 400
    elif code == 403 and all(
        c == "_" or "A" <= c <= "Z" or "0" <= c <= "9" for c in message
    ):
        code = 400

    match code:
        case 400:
            prefix = "Bad Request"
        case 401:
            prefix = "Unauthorized"
        case 403:
            prefix = "Forbidden"
        case 500:
            prefix = "Internal Server Error"
        case _:
            return f"Bad Request: {message}"

    if message.startswith(prefix):
        return message
    if not message:
        return prefix
    if len(message) >= 2 and (message[1] == "_" or "A" <= message[1] <= "Z"):
        return f"{prefix}: {message}"
    return f"{prefix}: {chr(to_lower(ord(message[0])))}{message[1:]}"


# Ported from telegram-bot-api/Client.cpp, Client::get_date_time_format().
def get_date_time_format(
    formatting_type: td_api.DateTimeFormattingType | None,
) -> bytes:
    """Return the Bot API's format of a date shown as `formatting_type` shows it.

    No formatting type gives an empty string, and a relative one gives `r`. An absolute
    one gives `w` when the day of the week shows, then `d` or `D` for a short or a long
    date, then `t` or `T` for a short or a long time.
    """
    if formatting_type is None:
        return b""
    if isinstance(formatting_type, td_api.DateTimeFormattingTypeRelative):
        return b"r"

    # The pinned code reads each precision through a pointer, which TDLib never leaves
    # null in the objects it gives.
    date_time_format = b"w" if formatting_type.show_day_of_week else b""
    match formatting_type.date_precision:
        case td_api.DateTimePartPrecisionShort():
            date_time_format += b"d"
        case td_api.DateTimePartPrecisionLong():
            date_time_format += b"D"
    match formatting_type.time_precision:
        case td_api.DateTimePartPrecisionShort():
            date_time_format += b"t"
        case td_api.DateTimePartPrecisionLong():
            date_time_format += b"T"
    return date_time_format


# Ported from telegram-bot-api/Client.cpp, Client::JsonEntity, without the client,
# which only the details of a mentioned user come from.
@dataclass(frozen=True)
class JsonEntity:
    """An entity as the Bot API server writes it for a client: a `MessageEntity` object.

    Attributes:
        entity: The API object of the entity, as TDLib gives it.
    """

    entity: td_api.TextEntity

    # Ported from telegram-bot-api/Client.cpp, Client::JsonEntity::store(), with the ID
    # of a mentioned user in place of the user's details.
    def store(self) -> tuple[tuple[str, bytes | int], ...]:
        """Return the members of the object, each a name and its value, in their order.

        Each type takes its name in the Bot API, and a type that holds a value adds it.
        A string value is `bytes`, as the server holds it. A mentioned user is the ID
        alone, since the server writes the other details of a user from its own record
        of the users it has met. An entity of a null type or of a media timestamp, which
        the server never writes, gives its offset and length alone.
        """
        entity = self.entity
        members: list[tuple[str, bytes | int]] = [
            ("offset", entity.offset),
            ("length", entity.length),
        ]
        match entity.type:
            case td_api.TextEntityTypeMention():
                members.append(("type", b"mention"))
            case td_api.TextEntityTypeHashtag():
                members.append(("type", b"hashtag"))
            case td_api.TextEntityTypeCashtag():
                members.append(("type", b"cashtag"))
            case td_api.TextEntityTypeBotCommand():
                members.append(("type", b"bot_command"))
            case td_api.TextEntityTypeUrl():
                members.append(("type", b"url"))
            case td_api.TextEntityTypeEmailAddress():
                members.append(("type", b"email"))
            case td_api.TextEntityTypePhoneNumber():
                members.append(("type", b"phone_number"))
            case td_api.TextEntityTypeBankCardNumber():
                members.append(("type", b"bank_card_number"))
            case td_api.TextEntityTypeTonAddress():
                members.append(("type", b"ton_address"))
            case td_api.TextEntityTypeBold():
                members.append(("type", b"bold"))
            case td_api.TextEntityTypeItalic():
                members.append(("type", b"italic"))
            case td_api.TextEntityTypeUnderline():
                members.append(("type", b"underline"))
            case td_api.TextEntityTypeStrikethrough():
                members.append(("type", b"strikethrough"))
            case td_api.TextEntityTypeSpoiler():
                members.append(("type", b"spoiler"))
            case td_api.TextEntityTypeCode():
                members.append(("type", b"code"))
            case td_api.TextEntityTypePre():
                members.append(("type", b"pre"))
            case td_api.TextEntityTypePreCode(language=language):
                members += [("type", b"pre"), ("language", language)]
            case td_api.TextEntityTypeTextUrl(url=url):
                members += [("type", b"text_link"), ("url", url)]
            case td_api.TextEntityTypeMentionName(user_id=user_id):
                members += [("type", b"text_mention"), ("user", user_id)]
            case td_api.TextEntityTypeCustomEmoji(custom_emoji_id=custom_emoji_id):
                members += [
                    ("type", b"custom_emoji"),
                    ("custom_emoji_id", b"%d" % custom_emoji_id),
                ]
            case td_api.TextEntityTypeBlockQuote():
                members.append(("type", b"blockquote"))
            case td_api.TextEntityTypeExpandableBlockQuote():
                members.append(("type", b"expandable_blockquote"))
            case td_api.TextEntityTypeDateTime(
                unix_time=unix_time, formatting_type=formatting_type
            ):
                members += [
                    ("type", b"date_time"),
                    ("unix_time", unix_time),
                    ("date_time_format", get_date_time_format(formatting_type)),
                ]
            case _:
                # The pinned code stops at UNREACHABLE() for a media timestamp, which
                # JsonVectorEntities leaves out, and dereferences a null type.
                pass
        return tuple(members)
