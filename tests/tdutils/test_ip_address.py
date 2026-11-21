import pytest

from tdlib_oracle.tdutils.ip_address import init_ipv6_port


@pytest.mark.parametrize(
    "ipv6", [b"[::1]", b"::1", b"[1:2:3:4:5:6:7:8]", b"[::1\x00x]", b"::1\x00x"]
)
def test_init_ipv6_port_accepts_an_address_in_brackets_or_not_up_to_a_nul(
    ipv6: bytes,
) -> None:
    assert init_ipv6_port(ipv6)


@pytest.mark.parametrize(
    "ipv6", [b"", b"[]", b"[::g]", b"[::1", b"::1]", b"[[::1]]", b"\x00::1"]
)
def test_init_ipv6_port_refuses_anything_else(ipv6: bytes) -> None:
    assert not init_ipv6_port(ipv6)
