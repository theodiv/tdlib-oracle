# Ported from tdutils/td/utils/algorithm.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Algorithms of tdutils over lists: two lists combined in the order tdutils keeps."""

from collections.abc import Sequence
from typing import TypeVar

_T = TypeVar("_T")


# Ported from tdutils/td/utils/algorithm.h, combine(vector<T> &destination, vector<T>
# &&source).
def combine(destination: Sequence[_T], source: Sequence[_T]) -> list[_T]:
    """Return both lists as one: the longer first, or `destination` when as long.

    TDLib swaps the lists before it appends when `destination` is the shorter, and that
    decides the order a sort starts from.
    """
    if len(destination) < len(source):
        return [*source, *destination]
    return [*destination, *source]
