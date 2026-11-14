# Ported from tdutils/test/misc.cpp of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

from tdlib_oracle.text.utf8 import check_utf8


# Ported from tdutils/test/misc.cpp, test_check_utf8().
def _test_check_utf8(text: bytes, result: bool) -> None:
    assert check_utf8(text) == result


# Ported from tdutils/test/misc.cpp, TEST(Misc, check_utf8).
def test_check_utf8() -> None:
    _test_check_utf8(b"", True)
    _test_check_utf8(b"\xe0", False)
    _test_check_utf8(b"\xf0", False)
    _test_check_utf8(b"\xff", False)
    for i in range(256):
        _test_check_utf8(bytes([i]), i <= 0x7F)
        _test_check_utf8(bytes([i]) * 2, i <= 0x7F)
        _test_check_utf8(bytes([i]) * 10, i <= 0x7F)
    _test_check_utf8(b"artem", True)
    # The word "artem" in Cyrillic letters.
    _test_check_utf8(b"\xd0\xb0\xd1\x80\xd1\x82\xd0\xb5\xd0\xbc", True)
    _test_check_utf8(b"\xaf", False)
    _test_check_utf8(b"\xaf\xaf", False)
    _test_check_utf8(b"\xb0\x00", False)
    _test_check_utf8(b"\xb0\x80", False)
    _test_check_utf8(b"\xb1\x7f", False)
    _test_check_utf8(b"\xb1\x80", False)
    _test_check_utf8(b"\xb1\x8f", False)
    _test_check_utf8(b"\xc2\x80", True)
    _test_check_utf8(b"\xc2\x8f", True)
    _test_check_utf8(b"\xcf\xaf", True)
    _test_check_utf8(b"\xdf\xbf", True)
    _test_check_utf8(b"\xdf\xc0", False)
    _test_check_utf8(b"\xe0\xbf", False)
    _test_check_utf8(b"\xe0\x90\x80", False)
    _test_check_utf8(b"\xe0\x9f\x80", False)
    _test_check_utf8(b"\xe0\xa0\x80", True)
    _test_check_utf8(b"\xed\x9f\xbf", True)
    _test_check_utf8(b"\xed\x9f\xc0", False)
    _test_check_utf8(b"\xed\xa0\x80", False)
    _test_check_utf8(b"\xed\xa0\xbf", False)
    _test_check_utf8(b"\xed\xbf\xbf", False)
    _test_check_utf8(b"\xee\x80\x80", True)
    _test_check_utf8(b"\xef\xbf\xbf", True)
    _test_check_utf8(b"\xef\xbf\xc0", False)
    _test_check_utf8(b"\xef\xc0\xbf", False)
    _test_check_utf8(b"\xf0\xbf\xbf", False)
    _test_check_utf8(b"\xef\x90\x80\x80", False)
    _test_check_utf8(b"\xf0\x8f\x80\x80", False)
    _test_check_utf8(b"\xf0\x90\x80\x80", True)
    _test_check_utf8(b"\xf4\x8f\xbf\xbf", True)
    _test_check_utf8(b"\xf5\x8f\xbf\xbf", False)
    _test_check_utf8(b"\xf4\x90\x80\x80", False)
    _test_check_utf8(b"\xf4\x90\xbf\xbf", False)
    _test_check_utf8(b"\xf4\x8f\xc0\x80", False)
    _test_check_utf8(b"\xf4\x8f\xc0\xbf", False)
    _test_check_utf8(b"\xf4\x8f\xbf\xc0", False)
