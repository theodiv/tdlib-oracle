# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's conversion of the formatted text a client sends into the one it keeps."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity.fixing import fix_formatted_text


# Ported from td/telegram/MessageEntity.cpp, get_formatted_text(const Td *td, ...), for
# a bot's text without entities.
def get_formatted_text(
    text: bytes, *, allow_empty: bool, skip_trim: bool
) -> bytes | Failure:
    """Return a bot's `text` as TDLib fixes it, or the `Failure` that refuses it.

    A bot sends the text, so a text of blank characters is kept exactly when an empty
    text is allowed. The Bot API server never sets the `always_parse_markdown` option,
    so no Markdown is parsed. The entities TDLib finds in the text leave the text as it
    is, and only the text comes back, so none are looked for, as for a bot with more
    than one session.
    """
    result = fix_formatted_text(
        text,
        (),
        allow_empty=allow_empty,
        allow_empty_string=allow_empty,
        skip_new_entities=True,
        skip_bot_commands=True,
        skip_trim=skip_trim,
    )
    if isinstance(result, Failure):
        return result
    return result.text
