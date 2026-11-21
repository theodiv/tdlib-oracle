from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.synchronous_requests import run_request

_HTML = td_api.TextParseModeHTML()


def test_run_request_answers_with_the_text_and_its_entities() -> None:
    result = run_request(td_api.ParseTextEntities(b"<b>a</b> <i>b</i>", _HTML))
    assert result == td_api.FormattedText(
        b"a b",
        (
            td_api.TextEntity(0, 1, td_api.TextEntityTypeBold()),
            td_api.TextEntity(2, 1, td_api.TextEntityTypeItalic()),
        ),
    )


def test_run_request_carries_each_tie_of_the_sort() -> None:
    text = b'<i>y<a href="t.me/a"><a href="t.me/b">x</a></a></i>'
    result = run_request(td_api.ParseTextEntities(text, _HTML))
    assert isinstance(result, td_api.FormattedText)
    italic, *links = result.entities
    tie = {
        td_api.TextEntity(1, 1, td_api.TextEntityTypeTextUrl(b"http://t.me/a")),
        td_api.TextEntity(1, 1, td_api.TextEntityTypeTextUrl(b"http://t.me/b")),
    }
    assert italic == td_api.TextEntity(0, 2, td_api.TextEntityTypeItalic())
    assert [set(link.ties) for link in links if link is not None] == [tie, tie]


def test_run_request_refuses_a_text_that_is_not_utf8() -> None:
    result = run_request(td_api.ParseTextEntities(b"<b>\xff</b>", _HTML))
    assert result == td_api.Error(400, b"Text must be encoded in UTF-8")


def test_run_request_refuses_a_request_without_a_parse_mode() -> None:
    result = run_request(td_api.ParseTextEntities(b"<b>a</b>", None))
    assert result == td_api.Error(400, b"Parse mode must be non-empty")


def test_run_request_takes_65536_code_points_and_refuses_more() -> None:
    longest = "\U000000e9".encode() * 65_536
    assert run_request(td_api.ParseTextEntities(longest, _HTML)) == (
        td_api.FormattedText(longest, ())
    )
    result = run_request(td_api.ParseTextEntities(b"a" * 65_537, _HTML))
    assert result == td_api.Error(400, b"Can't parse entities: Text is too long")


def test_run_request_answers_a_refusal_of_the_parser_with_its_message() -> None:
    result = run_request(td_api.ParseTextEntities("<\U000000e9>".encode(), _HTML))
    message = (
        'Can\'t parse entities: Unsupported start tag "\U000000e9" at byte offset 0'
    )
    assert result == td_api.Error(400, message.encode())
