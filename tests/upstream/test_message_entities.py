# Ported from test/message_entities.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

from tdlib_oracle.tdlib.fixing import fix_formatted_text
from tdlib_oracle.text.failure import Failure


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, const td::string &expected_str, ...), for a
# text without entities.
def _check_fix_formatted_text(
    text: bytes,
    expected_text: bytes,
    allow_empty: bool = True,
    skip_new_entities: bool = False,
    skip_bot_commands: bool = False,
    skip_trim: bool = True,
) -> None:
    # The port finds no entities on its own, so `skip_new_entities` and
    # `skip_bot_commands` change nothing; they stay so that each call reads as
    # upstream's does.
    result = fix_formatted_text(
        text, allow_empty=allow_empty, allow_empty_string=False, skip_trim=skip_trim
    )
    assert result == expected_text


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, bool allow_empty, ...), for a text
# without entities.
def _check_fix_formatted_text_fails(
    text: bytes,
    allow_empty: bool,
    skip_new_entities: bool,
    skip_bot_commands: bool,
    skip_trim: bool,
) -> None:
    result = fix_formatted_text(
        text, allow_empty=allow_empty, allow_empty_string=False, skip_trim=skip_trim
    )
    assert isinstance(result, Failure)


# Ported from test/message_entities.cpp, TEST(MessageEntities, fix_formatted_text), the
# cases in which neither the text nor the result holds an entity.
def test_fix_formatted_text() -> None:
    text = bytes(range(33))

    _check_fix_formatted_text(text, b"", True, True, True, True)
    _check_fix_formatted_text(text, b"", True, True, False, True)
    _check_fix_formatted_text(text, b"", True, False, True, True)
    _check_fix_formatted_text(text, b"", True, False, False, True)
    _check_fix_formatted_text(text, b"", True, False, False, False)
    _check_fix_formatted_text_fails(text, False, False, False, False)
    _check_fix_formatted_text_fails(text, False, False, False, True)

    _check_fix_formatted_text(b"  aba\n ", b"  aba\n ", True, True, True, True)
    _check_fix_formatted_text(b"  aba\n ", b"aba", True, True, True, False)
    _check_fix_formatted_text(b"  \n ", b"", True, True, True, True)
    _check_fix_formatted_text(b"  \n ", b"", True, True, True, False)
    _check_fix_formatted_text_fails(b"  \n ", False, True, True, False)

    # Upstream also runs these without skipping new entities and expects the entities
    # TDLib finds on its own, which the port leaves out.
    text = b"  /test @abaca #ORD $ABC  telegram.org "
    for skip_trim in (False, True):
        expected_text = text if skip_trim else text[2 : len(text) - 1]
        for skip_bot_commands in (False, True):
            _check_fix_formatted_text(
                text, expected_text, True, True, skip_bot_commands, skip_trim
            )
            _check_fix_formatted_text(
                text, expected_text, False, True, skip_bot_commands, skip_trim
            )
