# Ported from td/telegram/SynchronousRequests.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's synchronous requests: the entities that the markup of a text gives."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_entity import (
    FormattedText,
    get_text_entities_object,
    parse_html,
    parse_markdown,
    parse_markdown_v2,
)
from tdlib_oracle.tdutils.utf8 import check_utf8, utf8_length

# Ported from td/telegram/SynchronousRequests.cpp,
# SynchronousRequests::do_request(td_api::parseTextEntities &request), the length in
# code points past which it refuses a text.
_MAX_TEXT_LENGTH = 65536


# Ported from td/telegram/SynchronousRequests.cpp, SynchronousRequests::run_request(),
# for a parseTextEntities request, without its logging.
def run_request(
    function: td_api.ParseTextEntities,
) -> td_api.FormattedText | td_api.Error:
    """Return TDLib's answer to `function`, a request it answers synchronously."""
    return do_request(function)


# Ported from td/telegram/SynchronousRequests.cpp,
# SynchronousRequests::do_request(td_api::parseTextEntities &request).
def do_request(
    request: td_api.ParseTextEntities,
) -> td_api.FormattedText | td_api.Error:
    """Return the text of `request` without markup, with its entities, or the error."""
    # A carriage return can separate parts of the text, so it is checked, not cleaned.
    if not check_utf8(request.text):
        return td_api.Error(400, b"Text must be encoded in UTF-8")
    if request.parse_mode is None:
        return td_api.Error(400, b"Parse mode must be non-empty")

    result: FormattedText | Failure
    if utf8_length(request.text) > _MAX_TEXT_LENGTH:
        result = Failure(0, "Text is too long")
    else:
        match request.parse_mode:
            case td_api.TextParseModeHTML():
                result = parse_html(request.text)
            case td_api.TextParseModeMarkdown(version=0 | 1):
                result = parse_markdown(request.text)
            case td_api.TextParseModeMarkdown(version=2):
                result = parse_markdown_v2(request.text)
            case _:
                result = Failure(0, "Wrong Markdown version specified")
    if isinstance(result, Failure):
        message = result.message.encode("utf-8", "surrogateescape")
        return td_api.Error(400, b"Can't parse entities: " + message)
    return td_api.FormattedText(result.text, get_text_entities_object(result.entities))
