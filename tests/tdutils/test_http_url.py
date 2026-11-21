import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.http_url import PROTOCOL, HttpUrl, parse_url

_WRONG_PORT = Failure(0, "Wrong port number specified in the URL")


def _http_url(
    host: bytes = b"a.b",
    *,
    protocol: int = PROTOCOL.HTTP,
    userinfo: bytes = b"",
    is_ipv6: bool = False,
    specified_port: int = 0,
    port: int = 80,
    query: bytes = b"/",
) -> HttpUrl:
    return HttpUrl(protocol, userinfo, host, is_ipv6, specified_port, port, query)


def test_parse_url_reads_each_part() -> None:
    assert parse_url(b"https://User:Pass@Example.COM:8443/Path?Q=1#F") == _http_url(
        b"example.com",
        protocol=PROTOCOL.HTTPS,
        userinfo=b"User:Pass",
        specified_port=8443,
        port=8443,
        query=b"/Path?Q=1#F",
    )


@pytest.mark.parametrize(
    ("url", "protocol", "port"),
    [
        (b"a.b", PROTOCOL.HTTP, 80),
        (b"HTTP://a.b", PROTOCOL.HTTP, 80),
        (b"hTtPs://a.b", PROTOCOL.HTTPS, 443),
    ],
)
def test_parse_url_takes_http_unless_the_url_names_https(
    url: bytes, protocol: int, port: int
) -> None:
    assert parse_url(url) == _http_url(protocol=protocol, port=port)


@pytest.mark.parametrize(
    "url", [b"ftp://a.b", b"://a.b", b"httpx://a.b", b"https ://a.b"]
)
def test_parse_url_refuses_another_protocol(url: bytes) -> None:
    assert parse_url(url) == Failure(0, "Unsupported URL protocol")


def test_parse_url_reads_no_protocol_past_a_slash() -> None:
    assert parse_url(b"a/b://c") == _http_url(b"a", query=b"/b://c")


@pytest.mark.parametrize(
    ("url", "specified_port", "port"),
    [
        (b"a.b:1", 1, 1),
        (b"a.b:65535", 65535, 65535),
        (b"a.b:00080", 80, 80),
        (b"https://a.b:0000000443", 443, 443),
        (b"https://a.b", 0, 443),
    ],
)
def test_parse_url_reads_the_port(url: bytes, specified_port: int, port: int) -> None:
    result = parse_url(url)
    assert isinstance(result, HttpUrl)
    assert (result.specified_port, result.port) == (specified_port, port)


@pytest.mark.parametrize(
    "url",
    [
        b"a.b:",
        b"a.b:0",
        b"a.b:00",
        b"a.b:65536",
        b"a.b:-1",
        b"a.b:-0",
        b"a.b:+1",
        b"a.b:0x1",
        b"a.b: 1",
        b"a.b:4294967377",  # 2**32 + 81, which a 32-bit integer reads as 81
        b"a.b:" + b"1" * 30,
    ],
)
def test_parse_url_refuses_a_port_out_of_range_or_not_a_number(url: bytes) -> None:
    assert parse_url(url) == _WRONG_PORT


def test_parse_url_reads_no_port_after_a_colon_that_starts_the_host() -> None:
    assert parse_url(b"http://:80/x") == Failure(0, "Disallowed character in URL host")


def test_parse_url_splits_the_userinfo_at_the_last_at_sign() -> None:
    assert parse_url(b"@a.b") == _http_url()
    assert parse_url(b"a@b@c.d") == Failure(0, "Disallowed character in URL userinfo")


def test_parse_url_reads_an_ipv6_host_in_brackets_in_lowercase() -> None:
    assert parse_url(b"[::FFFF:1.2.3.4]:8080") == _http_url(
        b"[::ffff:1.2.3.4]", is_ipv6=True, specified_port=8080, port=8080
    )


def test_parse_url_leaves_the_userinfo_of_an_ipv6_host_unchecked() -> None:
    assert parse_url(b"a b%@[::1]") == _http_url(
        b"[::1]", userinfo=b"a b%", is_ipv6=True
    )


@pytest.mark.parametrize(
    "url",
    [
        b"[]",
        b"[\x00]",
        b"[::g]",
        b"[::%0]",  # a scope ID, which inet_pton() refuses
        b"[1:2:3:4:5:6:7:8:9]",
        b"[1.2.3.4]",
    ],
)
def test_parse_url_refuses_brackets_around_no_ipv6_address(url: bytes) -> None:
    assert parse_url(url) == Failure(0, "Wrong IPv6 address specified in the URL")


def test_parse_url_reads_an_ipv6_address_up_to_a_nul_then_refuses_the_nul() -> None:
    assert parse_url(b"[::1\x00x]") == Failure(0, "Wrong IPv6 URL host")


def test_parse_url_checks_a_host_with_a_bracket_on_one_side_as_any_host() -> None:
    assert parse_url(b"http://[::1]x") == Failure(0, "Disallowed character in URL host")


@pytest.mark.parametrize(
    ("url", "message"),
    [
        (b"http://", "URL host is empty"),
        (b"http://u@:1/", "URL host is empty"),
        (b".", "Host is invalid"),
    ],
)
def test_parse_url_refuses_an_empty_or_dot_host(url: bytes, message: str) -> None:
    assert parse_url(url) == Failure(0, message)


def test_parse_url_keeps_a_host_of_two_dots() -> None:
    assert parse_url(b"..") == _http_url(b"..")


@pytest.mark.parametrize(
    ("url", "query"),
    [
        (b"a.b", b"/"),
        (b"a.b?x", b"/?x"),
        (b"a.b#x", b"/#x"),
        (b"a.b/x y\t", b"/x%20y"),
        (b"a.b/ \t\r\n\x00\x0b", b"/"),
        (b"a.b/x\x0c", b"/x%0C"),
        (b"a.b/\x00\x1f !", b"/%00%1F%20!"),
        (b"a.b?\x7f\xc3\xa9", b"/?\x7f\xc3\xa9"),
    ],
)
def test_parse_url_trims_the_query_and_encodes_its_controls_and_spaces(
    url: bytes, query: bytes
) -> None:
    assert parse_url(url) == _http_url(query=query)


@pytest.mark.parametrize(
    "url",
    [
        b"%41a.b",
        b"!$,~*'();&+=-_.a",
        "\U00000434\U0000043e\U0000043c.\U00000440\U00000444".encode(),
        "\U0001f600.com".encode(),
        b"caf\xe9.com",  # Latin-1, not UTF-8
        b"\xed\xa0\x80.com",  # a lone surrogate
        b"u:p:q@a.b",
    ],
)
def test_parse_url_accepts_the_allowed_symbols_and_any_byte_past_ascii(
    url: bytes,
) -> None:
    assert isinstance(parse_url(url), HttpUrl)


@pytest.mark.parametrize(
    ("url", "message"),
    [
        (b"a%.b", "Wrong percent-encoded symbol in URL host"),
        (b"a%4.b", "Wrong percent-encoded symbol in URL host"),
        (b"a.b%", "Wrong percent-encoded symbol in URL host"),
        (b"a.b%4", "Wrong percent-encoded symbol in URL host"),
        (b"%%41.b", "Wrong percent-encoded symbol in URL host"),
        (b"a%<.b", "Wrong percent-encoded symbol in URL host"),
        (b"<%.b", "Disallowed character in URL host"),
        (b"a b.c", "Disallowed character in URL host"),
        (b"u<@a<.b", "Disallowed character in URL host"),
        (b"%4@a.b", "Wrong percent-encoded symbol in URL userinfo"),
        (b"u%@a.b", "Wrong percent-encoded symbol in URL userinfo"),
        (b"u<@a.b", "Disallowed character in URL userinfo"),
    ],
)
def test_parse_url_refuses_the_first_bad_character_of_the_host_then_the_userinfo(
    url: bytes, message: str
) -> None:
    assert parse_url(url) == Failure(0, message)


@pytest.mark.parametrize(
    ("url", "expected"),
    [
        (b"HTTPS://U:P@A.B:8443?q", b"https://U:P@a.b:8443/?q"),
        (b"a.b", b"http://a.b/"),
        (b"http://a.b:80", b"http://a.b:80/"),
        (b"[::1]:1/x", b"http://[::1]:1/x"),
    ],
)
def test_get_url_writes_the_url_back_with_the_port_it_named(
    url: bytes, expected: bytes
) -> None:
    result = parse_url(url)
    assert isinstance(result, HttpUrl)
    assert result.get_url() == expected
