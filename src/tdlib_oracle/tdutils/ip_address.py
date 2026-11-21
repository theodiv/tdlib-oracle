# Ported from tdutils/td/utils/port/IPAddress.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""IP addresses of tdutils: the check of an IPv6 address, in brackets or not."""

from tdlib_oracle.runtime.ipv6 import is_ipv6_address


# Ported from tdutils/td/utils/port/IPAddress.cpp, IPAddress::init_ipv6_port(), for the
# port 1 that parse_url() passes, without its error message.
def init_ipv6_port(ipv6: bytes) -> bool:
    """Return whether `ipv6`, in brackets or not, is an IPv6 address.

    The address is read up to its first NUL, as `inet_pton()` reads a C string.
    """
    if len(ipv6) > 2 and ipv6[0] == 0x5B and ipv6[-1] == 0x5D:  # '[' and ']'
        ipv6 = ipv6[1:-1]
    return is_ipv6_address(ipv6.partition(b"\0")[0])
