# Ported from tdutils/td/utils/Parser.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The parser of tdutils: the bytes up to the first of a set of characters."""


# Ported from tdutils/td/utils/Parser.h, ParserImpl::read_till_nofail(Slice str), for a
# parser whose status holds no error.
def read_till_nofail(data: bytes, pos: int, characters: bytes) -> tuple[int, int]:
    """Return the span from `pos` of `data` to the first of `characters`, or to its end.

    A parser that stands at `pos` moves to the end of the span, where its next
    read starts.
    """
    ends = [data.find(c, pos) for c in characters]
    return pos, min((end for end in ends if end != -1), default=len(data))
