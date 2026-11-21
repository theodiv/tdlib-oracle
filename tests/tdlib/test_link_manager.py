import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.link_manager import (
    check_link,
    get_checked_link,
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
