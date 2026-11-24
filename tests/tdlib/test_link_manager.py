import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.formatted_date import DATE_FLAG
from tdlib_oracle.tdlib.link_manager import (
    check_link,
    check_tg_url_host,
    get_checked_link,
    get_link_custom_emoji_id,
    get_link_formatted_date,
    get_link_user_id,
)


@pytest.mark.parametrize(
    ("link", "expected"),
    [
        (b"Example.COM/Path?Q#F", b"http://example.com/Path?Q#F"),
        (b"https://a.b:8443", b"https://a.b:8443/"),
        (b"http://[::1]", b"http://[::1]/"),
        (b"mailto:a@b.com", b"http://mailto:a@b.com/"),
        (b"http://a.b/" + b"x" * 40000, b"http://a.b/" + b"x" * 40000),
    ],
)
def test_check_link_keeps_an_http_link_in_its_parsed_form(
    link: bytes, expected: bytes
) -> None:
    assert check_link(link) == expected


@pytest.mark.parametrize(
    ("link", "expected"),
    [
        (b"tg:resolve?domain=a", b"tg://resolve?domain=a"),
        (b"tg://resolve/?domain=a", b"tg://resolve?domain=a"),
        (b"TG://A/b", b"tg://a/b"),
        (b"tg://a", b"tg://a/"),
        (b"tg://a/?", b"tg://a?"),
        (b"ton://wallet", b"ton://wallet/"),
        (b"TON:a-b_c", b"ton://a-b_c/"),
        (b"tonsite://a.ton/x", b"tonsite://a.ton/x"),
        (b"TonSite:a.b", b"tonsite://a.b/"),
    ],
)
def test_check_link_writes_a_tg_ton_or_tonsite_link_with_its_scheme(
    link: bytes, expected: bytes
) -> None:
    assert check_link(link) == expected


@pytest.mark.parametrize(
    ("link", "message"),
    [
        (b"tg:http://a", "Wrong tg URL"),
        (b"tg:HTTP://a", "Wrong tg URL"),
        (b"tg:https://a", "Wrong tg URL"),
        (b"tg:u@a", "Wrong tg URL"),
        (b"tg:a:1", "Wrong tg URL"),
        (b"tg:[::1]", "Wrong tg URL"),
        (b"ton:u@a", "Wrong ton URL"),
        (b"tonsite:a:1", "Wrong ton URL"),
        (b"tg:a.b", "Unallowed characters in URL host"),
        (b"ton:a.b", "Unallowed characters in URL host"),
        (b"tg:a%41", "Unallowed characters in URL host"),
        (b"tonsite:a!b", "Unallowed characters in URL host"),
        (b"tg:ftp://a", "Unsupported URL protocol"),
        (b"tg:///a", "URL host is empty"),
        (b"tgx:a", "Wrong port number specified in the URL"),
        (b"http://localhost", "Wrong HTTP URL"),
        (b"", "URL host is empty"),
    ],
)
def test_check_link_refuses_a_link_with_its_url_quoted(
    link: bytes, message: str
) -> None:
    expected = Failure(400, f"URL '{link.decode()}' is invalid: {message}")
    assert check_link(link) == expected


def test_check_link_quotes_a_utf_8_link_as_text() -> None:
    link = "\U000000e9".encode()
    assert check_link(link) == Failure(
        400, "URL '\U000000e9' is invalid: Wrong HTTP URL"
    )


@pytest.mark.parametrize(
    ("link", "message"), [(b"a\x00b", "URL 'a"), (b"\x00", "URL '")]
)
def test_check_link_quotes_a_link_up_to_its_first_nul(
    link: bytes, message: str
) -> None:
    assert check_link(link) == Failure(400, message)


@pytest.mark.parametrize("link", [b"\xff", b"caf\xe9", b"\xed\xa0\x80"])
def test_check_link_quotes_no_link_that_is_not_utf_8(link: bytes) -> None:
    assert check_link(link) == Failure(400, "URL is invalid: Wrong HTTP URL")


@pytest.mark.parametrize(
    ("link", "expected"),
    [
        (b"HTTP://A.B", b"http://a.b/"),
        (b"tg:a", b"tg://a/"),
        (b"http://localhost", b""),
        (b"tg:a.b", b""),
        (b"\xff", b""),
    ],
)
def test_get_checked_link_gives_the_kept_form_or_nothing(
    link: bytes, expected: bytes
) -> None:
    assert get_checked_link(link) == expected


@pytest.mark.parametrize(
    ("url", "user_id"),
    [
        (b"tg://user?id=123456789", 123456789),
        (b"TG://USER?ID=5", 5),
        (b"tg:user?id=5", 5),
        (b"tg://user/?id=5", 5),
        (b"tg://user?x=1&id=7", 7),
        (b"tg://user?id=5&id=6", 5),
        (b"tg://user?id=5#frag", 5),
        (b"tg://user?id=-5", -5),
        (b"tg://user?id=0", 0),
        (b"tg://user?id=9223372036854775807", 9223372036854775807),
        (b"tg://user?id=-9223372036854775808", -9223372036854775808),
        (b"tg://user?" + b"&" * 40000 + b"id=5", 5),
    ],
)
def test_get_link_user_id_reads_the_first_id_parameter(
    url: bytes, user_id: int
) -> None:
    assert get_link_user_id(url) == user_id


@pytest.mark.parametrize(
    "url",
    [
        b"",
        b"tg:",
        b"http://user?id=5",
        b"tg:/user?id=5",
        b"tg://users?id=5",
        b"tg://user",
        b"tg://user#?id=5",
        b"tg://user?",
        b"tg://user?#id=5",
        b"tg://user?idx=5",
        b"tg://user?xid=5",
        b"tg://user?id",
        b"tg://user?id&id=5",
        b"tg://user?id=",
        b"tg://user?id=007",
        b"tg://user?id=-0",
        b"tg://user?id=+5",
        b"tg://user?id=5x",
        b"tg://user?id=5=6",
        b"tg://user?id=9223372036854775808",
        b"tg://user?id=-9223372036854775809",
        b"tg://user?id=18446744073709551615",  # 2**64 - 1, which reads as -1
        b"tg://user?id=18446744073709551621",  # 2**64 + 5, which reads as 5
        b"tg://user?id=" + b"1" * 25,
        b"tg://user?" + b"&" * 40000,
    ],
)
def test_get_link_user_id_finds_no_user_id(url: bytes) -> None:
    assert get_link_user_id(url) == 0


@pytest.mark.parametrize(
    ("url", "query"),
    [
        (b"tg://emoji?id=5", b"id=5"),
        (b"tg:emoji?id=5", b"id=5"),
        (b"TG://EMOJI/?id=5", b"id=5"),
        (b"tg://emoji?id=5#id=6", b"id=5"),
        (b"tg://emoji?", b""),
    ],
)
def test_check_tg_url_host_finds_the_parameters_of_a_link_to_the_host(
    url: bytes, query: bytes
) -> None:
    span = check_tg_url_host(url, b"emoji")
    assert not isinstance(span, Failure)
    begin, end = span
    assert url[begin:end] == query


@pytest.mark.parametrize(
    ("url", "message"),
    [
        (b"", "URL must have scheme tg"),
        (b"http://emoji?id=5", "URL must have scheme tg"),
        (b"tg:/emoji?id=5", 'URL must have host "emoji"'),
        (b"tg://emojis?id=5", 'URL must have host "emoji"'),
        (b"tg://time?id=5", 'URL must have host "emoji"'),
        (b"tg://emoji", "URL must have parameters"),
        (b"tg://emoji/", "URL must have parameters"),
        (b"tg://emoji//?id=5", "URL must have parameters"),
        (b"tg://emoji#?id=5", "URL must have parameters"),
    ],
)
def test_check_tg_url_host_refuses_a_link_to_no_parameters_of_the_host(
    url: bytes, message: str
) -> None:
    assert check_tg_url_host(url, b"emoji") == Failure(400, message)


@pytest.mark.parametrize(
    ("url", "custom_emoji_id"),
    [
        (b"tg://emoji?id=5", 5),
        (b"tg://emoji?x=1&id=5&id=6", 5),
        (b"tg://emoji?id=5&id=x", 5),
        (b"tg://emoji?id=-5", -5),
        (b"tg://emoji?id=9223372036854775807", 9223372036854775807),
    ],
)
def test_get_link_custom_emoji_id_reads_the_first_id_parameter(
    url: bytes, custom_emoji_id: int
) -> None:
    assert get_link_custom_emoji_id(url) == custom_emoji_id


@pytest.mark.parametrize(
    ("url", "message"),
    [
        (b"tg://emoji?id=0", "Invalid custom emoji identifier specified"),
        (b"tg://emoji?id=05", "Invalid custom emoji identifier specified"),
        (b"tg://emoji?id=", "Invalid custom emoji identifier specified"),
        (b"tg://emoji?id=x&id=5", "Invalid custom emoji identifier specified"),
        (
            b"tg://emoji?id=9223372036854775808",
            "Invalid custom emoji identifier specified",
        ),
        (b"tg://emoji?ID=5", "Custom emoji URL must have an emoji identifier"),
        (b"tg://emoji?x#&id=5", "Custom emoji URL must have an emoji identifier"),
        (b"tg://emoji?", "Custom emoji URL must have an emoji identifier"),
        (b"tg://time?id=5", 'URL must have host "emoji"'),
    ],
)
def test_get_link_custom_emoji_id_refuses_a_link_without_a_valid_first_id(
    url: bytes, message: str
) -> None:
    assert get_link_custom_emoji_id(url) == Failure(400, message)


@pytest.mark.parametrize(
    ("url", "formatted_date"),
    [
        (b"tg://time?unix=5", (5, 0)),
        (b"tg://time?unix=5&format=wDT", (5, 52)),
        (b"tg://time?format=r&unix=5", (5, DATE_FLAG.RELATIVE)),
        (b"tg://time?unix=5&unix=6&format=t&format=T", (6, DATE_FLAG.LONG_TIME)),
        (b"tg://time?unix=5&format=t&format=", (5, 0)),
        (b"tg://time?unix=2147483647#unix=0", (2147483647, 0)),
    ],
)
def test_get_link_formatted_date_reads_the_last_unix_time_and_format(
    url: bytes, formatted_date: tuple[int, int]
) -> None:
    assert get_link_formatted_date(url) == formatted_date


@pytest.mark.parametrize(
    ("url", "message"),
    [
        (b"tg://time?unix=0", "Invalid Unix time specified"),
        (b"tg://time?unix=-1", "Invalid Unix time specified"),
        (b"tg://time?unix=2147483648", "Invalid Unix time specified"),
        (b"tg://time?unix=5&unix=x", "Invalid Unix time specified"),
        (b"tg://time?unix", "Invalid Unix time specified"),
        (b"tg://time?format=t", "URL must have the corresponding Unix time"),
        (b"tg://time?UNIX=5", "URL must have the corresponding Unix time"),
        (b"tg://time?unix=5&format=q", "Invalid date format used"),
        (b"tg://emoji?unix=5", 'URL must have host "time"'),
    ],
)
def test_get_link_formatted_date_refuses_a_link_without_a_valid_date(
    url: bytes, message: str
) -> None:
    assert get_link_formatted_date(url) == Failure(400, message)
