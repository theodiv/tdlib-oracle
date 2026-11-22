from dataclasses import dataclass, field

import pytest

from tdlib_oracle.botapi.client import (
    JsonEntity,
    get_date_time_format,
    get_error_description,
    get_formatted_text,
    get_input_message_text,
)
from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api

_SHORT = td_api.DateTimePartPrecisionShort()
_LONG = td_api.DateTimePartPrecisionLong()
_NONE = td_api.DateTimePartPrecisionNone()

_PARSED = td_api.FormattedText(
    b"x", (td_api.TextEntity(0, 1, td_api.TextEntityTypeBold()),)
)


@dataclass
class _Execute:
    """Answer each request with `answer`, keeping the requests."""

    answer: td_api.FormattedText | td_api.Error = _PARSED
    requests: list[td_api.ParseTextEntities] = field(default_factory=list)

    def __call__(
        self, request: td_api.ParseTextEntities
    ) -> td_api.FormattedText | td_api.Error:
        self.requests.append(request)
        return self.answer


def test_refuses_an_empty_text() -> None:
    execute = _Execute()
    result = get_input_message_text(b"", b"HTML", execute=execute)
    assert result == Failure(400, "Message text is empty")
    assert execute.requests == []


def test_passes_a_text_of_32768_bytes_on_unchanged() -> None:
    # The Bot API server neither cleans nor trims; TDLib does both later.
    text = b" \r\n" * 10922 + b"\r\r"
    assert len(text) == 32768
    result = get_input_message_text(text, b"", execute=_Execute())
    assert result == td_api.FormattedText(text, ())


@pytest.mark.parametrize("parse_mode", [b"", b"HTML", b"Markdown"])
def test_refuses_a_text_of_32769_bytes_before_its_parse_mode(parse_mode: bytes) -> None:
    execute = _Execute()
    result = get_input_message_text(b"a" * 32769, parse_mode, execute=execute)
    assert result == Failure(400, "Text is too long")
    assert execute.requests == []


def test_get_formatted_text_checks_the_size_of_an_empty_text_alone() -> None:
    # An empty text is refused before, by get_input_message_text().
    execute = _Execute()
    assert get_formatted_text(b"", b"HTML", execute=execute) == td_api.FormattedText(
        b"", ()
    )
    assert execute.requests == []


@pytest.mark.parametrize("parse_mode", [b"HTML", b"html", b"hTmL"])
def test_parses_html_in_any_letter_case(parse_mode: bytes) -> None:
    execute = _Execute()
    assert get_input_message_text(b"<b>x</b>", parse_mode, execute=execute) == _PARSED
    assert execute.requests == [
        td_api.ParseTextEntities(b"<b>x</b>", td_api.TextParseModeHTML())
    ]


@pytest.mark.parametrize("parse_mode", [b"", b"none", b"None", b"NONE"])
def test_parses_nothing_without_a_parse_mode(parse_mode: bytes) -> None:
    execute = _Execute()
    result = get_input_message_text(b"<b>x</b>", parse_mode, execute=execute)
    assert result == td_api.FormattedText(b"<b>x</b>", ())
    assert execute.requests == []


@pytest.mark.parametrize(
    "parse_mode", [b"htm", b"html5", b" html", b"BBCode", b"H\xc3\xa4ML"]
)
def test_refuses_any_other_parse_mode(parse_mode: bytes) -> None:
    execute = _Execute()
    result = get_input_message_text(b"x", parse_mode, execute=execute)
    assert result == Failure(400, "Unsupported parse_mode")
    assert execute.requests == []


def test_refuses_the_text_with_the_error_tdlib_answers() -> None:
    error = td_api.Error(400, b'Can\'t parse entities: Unsupported start tag "\xff"')
    result = get_input_message_text(b"x", b"HTML", execute=_Execute(error))
    assert isinstance(result, Failure)
    assert result.code == 400
    assert result.message.encode("utf-8", "surrogateescape") == error.message


@pytest.mark.parametrize(
    ("failure", "description"),
    [
        (Failure(400, "Message text is empty"), "Bad Request: message text is empty"),
        (Failure(400, "MESSAGE_TOO_LONG"), "Bad Request: MESSAGE_TOO_LONG"),
        (Failure(400, "Bad Request: chat not found"), "Bad Request: chat not found"),
        (Failure(400, ""), "Bad Request"),
        (Failure(400, "X"), "Bad Request: x"),
        (
            Failure(400, "\N{LATIN CAPITAL LETTER E WITH ACUTE}lan"),
            "Bad Request: \N{LATIN CAPITAL LETTER E WITH ACUTE}lan",
        ),
        (Failure(200, "Some error"), "Bad Request: some error"),
        (Failure(404, "Not Found"), "Bad Request: not Found"),
        (Failure(403, "CHAT_WRITE_FORBIDDEN"), "Bad Request: CHAT_WRITE_FORBIDDEN"),
        (Failure(403, ""), "Bad Request"),
        (Failure(403, "Bot was blocked"), "Forbidden: bot was blocked"),
        (Failure(401, "Unauthorized"), "Unauthorized"),
        (Failure(500, "Request aborted"), "Internal Server Error: request aborted"),
        (Failure(406, "Some Error"), "Bad Request: Some Error"),
    ],
)
def test_describes_a_failure_as_the_bot_api_server_does(
    failure: Failure, description: str
) -> None:
    assert get_error_description(failure) == description


@pytest.mark.parametrize(
    ("formatting_type", "date_time_format"),
    [
        (None, b""),
        (td_api.DateTimeFormattingTypeRelative(), b"r"),
        (td_api.DateTimeFormattingTypeAbsolute(_NONE, _NONE, False), b""),
        (td_api.DateTimeFormattingTypeAbsolute(_NONE, _NONE, True), b"w"),
        (td_api.DateTimeFormattingTypeAbsolute(_SHORT, _NONE, False), b"t"),
        (td_api.DateTimeFormattingTypeAbsolute(_LONG, _NONE, False), b"T"),
        (td_api.DateTimeFormattingTypeAbsolute(_NONE, _SHORT, False), b"d"),
        (td_api.DateTimeFormattingTypeAbsolute(_NONE, _LONG, False), b"D"),
        (td_api.DateTimeFormattingTypeAbsolute(_SHORT, _LONG, True), b"wDt"),
        (td_api.DateTimeFormattingTypeAbsolute(None, None, False), b""),
    ],
)
def test_get_date_time_format_writes_each_part_in_its_place(
    formatting_type: td_api.DateTimeFormattingType | None, date_time_format: bytes
) -> None:
    assert get_date_time_format(formatting_type) == date_time_format


@pytest.mark.parametrize(
    ("entity_type", "members"),
    [
        (td_api.TextEntityTypeMention(), (("type", b"mention"),)),
        (td_api.TextEntityTypeHashtag(), (("type", b"hashtag"),)),
        (td_api.TextEntityTypeCashtag(), (("type", b"cashtag"),)),
        (td_api.TextEntityTypeBotCommand(), (("type", b"bot_command"),)),
        (td_api.TextEntityTypeUrl(), (("type", b"url"),)),
        (td_api.TextEntityTypeEmailAddress(), (("type", b"email"),)),
        (td_api.TextEntityTypePhoneNumber(), (("type", b"phone_number"),)),
        (td_api.TextEntityTypeBankCardNumber(), (("type", b"bank_card_number"),)),
        (td_api.TextEntityTypeTonAddress(), (("type", b"ton_address"),)),
        (td_api.TextEntityTypeBold(), (("type", b"bold"),)),
        (td_api.TextEntityTypeItalic(), (("type", b"italic"),)),
        (td_api.TextEntityTypeUnderline(), (("type", b"underline"),)),
        (td_api.TextEntityTypeStrikethrough(), (("type", b"strikethrough"),)),
        (td_api.TextEntityTypeSpoiler(), (("type", b"spoiler"),)),
        (td_api.TextEntityTypeCode(), (("type", b"code"),)),
        (td_api.TextEntityTypePre(), (("type", b"pre"),)),
        (
            td_api.TextEntityTypePreCode(b"python"),
            (("type", b"pre"), ("language", b"python")),
        ),
        (
            td_api.TextEntityTypeTextUrl(b"http://t.me/"),
            (("type", b"text_link"), ("url", b"http://t.me/")),
        ),
        (
            td_api.TextEntityTypeMentionName(5),
            (("type", b"text_mention"), ("user", 5)),
        ),
        (
            td_api.TextEntityTypeCustomEmoji(5368324170671202286),
            (("type", b"custom_emoji"), ("custom_emoji_id", b"5368324170671202286")),
        ),
        (td_api.TextEntityTypeBlockQuote(), (("type", b"blockquote"),)),
        (
            td_api.TextEntityTypeExpandableBlockQuote(),
            (("type", b"expandable_blockquote"),),
        ),
        (
            td_api.TextEntityTypeDateTime(
                1700000000, td_api.DateTimeFormattingTypeAbsolute(_LONG, _SHORT, True)
            ),
            (
                ("type", b"date_time"),
                ("unix_time", 1700000000),
                ("date_time_format", b"wdT"),
            ),
        ),
        (
            td_api.TextEntityTypeDateTime(9, None),
            (("type", b"date_time"), ("unix_time", 9), ("date_time_format", b"")),
        ),
        (td_api.TextEntityTypeMediaTimestamp(5), ()),
        (None, ()),
    ],
)
def test_json_entity_stores_the_members_the_bot_api_server_writes(
    entity_type: td_api.TextEntityType | None,
    members: tuple[tuple[str, bytes | int], ...],
) -> None:
    entity = td_api.TextEntity(3, 4, entity_type)
    assert JsonEntity(entity).store() == (("offset", 3), ("length", 4), *members)
