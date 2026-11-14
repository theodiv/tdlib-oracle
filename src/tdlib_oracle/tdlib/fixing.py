# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's fixing of a formatted text: cleaning, trimming, and the emptiness checks."""

from tdlib_oracle.tdlib.cleaning import clean_input_string, is_empty_string
from tdlib_oracle.text.failure import Failure


# Ported from td/telegram/MessageEntity.cpp, remove_invalid_entities(), its path for a
# text without entities.
def _remove_invalid_entities(text: bytes) -> tuple[int, int]:
    """Return the offset of the last byte that is neither a space nor a line feed.

    When every byte is one of them, the offset is the length of `text` and the second
    value is `-1`; otherwise the second value is `0`.
    """
    for pos in range(len(text)):
        back_pos = len(text) - pos - 1
        if text[back_pos] not in (0x0A, 0x20):
            return back_pos, 0
    return len(text), -1


# Ported from td/telegram/MessageEntity.cpp, fix_formatted_text(), its path for a text
# without entities.
def fix_formatted_text(
    text: bytes, *, allow_empty: bool, allow_empty_string: bool, skip_trim: bool
) -> bytes | Failure:
    """Return `text` as TDLib fixes a formatted text, or the `Failure` that refuses it.

    The text is cleaned, refused when only spaces and line feeds are left, trimmed of
    them at both ends unless `skip_trim` is set, and refused again when only blank
    characters are left. `allow_empty` turns both refusals into an empty text, and
    `allow_empty_string` keeps a text of blank characters.
    """
    result = clean_input_string(text)
    if result is None:
        return Failure(400, "Strings must be encoded in UTF-8")

    last_non_whitespace_pos, last_non_whitespace_utf16_offset = (
        _remove_invalid_entities(result)
    )
    if last_non_whitespace_utf16_offset == -1:
        if allow_empty:
            return b""
        return Failure(400, "Text must be non-empty")

    if skip_trim:
        fixed = result
    else:
        result = result[: last_non_whitespace_pos + 1]
        ltrim_count = 0
        while ltrim_count < len(result) and result[ltrim_count] in (0x0A, 0x20):
            ltrim_count += 1
        fixed = result[ltrim_count:]

    if is_empty_string(fixed):
        if not allow_empty:
            return Failure(400, "Text must be non-empty")
        if not allow_empty_string:
            fixed = b""

    # The C++ goes on to cut a text over 35,000 bytes, which cannot happen here, since
    # `clean_input_string` stops short of that limit. It then adds the entities TDLib
    # finds on its own, such as links and mentions, which verdicts leave out.
    return fixed


# Ported from td/telegram/MessageEntity.cpp, get_formatted_text(const Td *td, ...), for
# a bot's text without entities.
def get_formatted_text(
    text: bytes, *, allow_empty: bool, skip_trim: bool
) -> bytes | Failure:
    """Return a bot's `text` as TDLib fixes it, or the `Failure` that refuses it.

    A bot sends the text, so a text of blank characters is kept exactly when an empty
    text is allowed. The Bot API server never sets the `always_parse_markdown` option,
    so no Markdown is parsed.
    """
    return fix_formatted_text(
        text,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty,
        skip_trim=skip_trim,
    )
