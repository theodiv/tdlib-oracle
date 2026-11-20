import pytest

from tdlib_oracle.tdlib.ipv6 import is_ipv6_address


@pytest.mark.parametrize(
    "text",
    [
        b"2001:db8:85a3:8d3:1319:8a2e:370:7348",
        b"2001:DB8:0:0:0:FF00:42:8329",
        b"0000:0000:0000:0000:0000:0000:0000:0000",
        b"::",
        b"::1",
        b"1::",
        b"1::8",
        b"1:2:3::6:7:8",
        b"1:2:3:4:5:6:7::",
        b"::2:3:4:5:6:7:8",
        b"::ffff:1.2.3.4",
        b"64:ff9b::255.255.255.255",
        b"1:2:3:4:5::0.0.0.0",
        b"1:2:3:4:5:6:1.2.3.4",
        b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255",  # the longest, 45 characters
    ],
)
def test_accepts_each_text_form(text: bytes) -> None:
    assert is_ipv6_address(text)


@pytest.mark.parametrize(
    "text",
    [
        b"",
        b":",
        b":::",
        b"1:2:3:4:5:6:7",  # seven groups without `::`
        b"1:2:3:4:5:6:7:8:9",
        b"1:2:3:4:5:6:7:8::",  # eight groups besides `::`
        b"::1:2:3:4:5:6:7:8",
        b"1:2:3:4:5:6::1.2.3.4",  # `::` left to stand for no group
        b"1::2::3",
        b":1::",
        b"1::2:",
        b"12345::",
        b"g::",
        b"1.2.3.4",
        b"1.2.3.4::",
        b"::1.2.3.4:5",  # an IPv4 address before the last group
        b"1:2:3:4:5:6:7:1.2.3.4",
        b"::1.2.3",
        b"::1.2.3.4.5",
        b"::256.1.1.1",
        b"::1.2.3.1000",
        b"::01.2.3.4",
        b"::1..3.4",
        b"::%0",  # a scope ID
        b"::1 ",
        b"[::1]",
        b"::1\x00",
        "::\U000000e9".encode(),
        b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.2550",
        b"1:" * 8000 + b"1",
    ],
)
def test_refuses_text_outside_the_forms(text: bytes) -> None:
    assert not is_ipv6_address(text)
