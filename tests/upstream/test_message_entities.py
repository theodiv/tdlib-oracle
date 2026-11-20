# Ported from test/message_entities.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

import random
from collections.abc import Callable, Sequence
from dataclasses import replace

from tdlib_oracle.tdlib.entities import TYPE, FormattedText, MessageEntity
from tdlib_oracle.tdlib.finding import (
    Span,
    find_bank_card_numbers,
    find_bot_commands,
    find_cashtags,
    find_hashtags,
    find_mentions,
    find_tg_urls,
    find_ton_addresses,
    find_urls,
    is_email_address,
)
from tdlib_oracle.tdlib.fixing import fix_formatted_text
from tdlib_oracle.text.failure import Failure
from tdlib_oracle.text.utf8 import utf8_utf16_length


def _matches(text: bytes, find: Callable[[bytes], tuple[Span, ...]]) -> list[bytes]:
    return [text[begin:end] for begin, end in find(text)]


# Ported from test/message_entities.cpp, check_mention().
def _check_mention(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_mentions) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, mention).
def test_mention() -> None:
    _check_mention(b"@mention", [b"@mention"])
    _check_mention(b"@mention ", [b"@mention"])
    _check_mention(b" @mention", [b"@mention"])
    _check_mention(b" @mention ", [b"@mention"])
    _check_mention(b"@abc @xyz @abc @xyz @xxx@yyy @ttt", [])
    _check_mention(
        b"@abcde @xyzxy @abcde @xyzxy @xxxxx@yyyyy @ttttt",
        [b"@abcde", b"@xyzxy", b"@abcde", b"@xyzxy", b"@xxxxx", b"@ttttt"],
    )
    _check_mention(b"no@mention", [])
    _check_mention(b"@n", [])
    _check_mention(
        b"@abcdefghijklmnopqrstuvwxyz123456", [b"@abcdefghijklmnopqrstuvwxyz123456"]
    )
    _check_mention(b"@abcdefghijklmnopqrstuvwxyz1234567", [])
    _check_mention("\U0000043d\U00000435\U00000442@mention".encode(), [])
    _check_mention(
        (
            b"@ya @gif @wiki @vid @bing @pic @bold @imdb @ImDb @coub @like @vote @giff "
            b"@cap ya cap @y @yar @bingg @bin"
        ),
        [
            b"@gif",
            b"@wiki",
            b"@vid",
            b"@bing",
            b"@pic",
            b"@bold",
            b"@imdb",
            b"@ImDb",
            b"@coub",
            b"@like",
            b"@vote",
            b"@giff",
            b"@bingg",
        ],
    )


# Ported from test/message_entities.cpp, check_bot_command().
def _check_bot_command(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_bot_commands) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, bot_command).
def test_bot_command() -> None:
    _check_bot_command(b"/abc", [b"/abc"])
    _check_bot_command(b" /abc", [b"/abc"])
    _check_bot_command(b"/abc ", [b"/abc"])
    _check_bot_command(b" /abc ", [b"/abc"])
    _check_bot_command(b"/a@abc", [b"/a@abc"])
    _check_bot_command(b"/a@b", [])
    _check_bot_command(b"/@bfdsa", [])
    _check_bot_command(b"/test/", [])


# Ported from test/message_entities.cpp, check_hashtag().
def _check_hashtag(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_hashtags) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, hashtag).
def test_hashtag() -> None:
    _check_hashtag(b"", [])
    _check_hashtag(b"#", [])
    _check_hashtag(b"##", [])
    _check_hashtag(b"###", [])
    _check_hashtag(b"#a", [b"#a"])
    _check_hashtag(b" #a", [b"#a"])
    _check_hashtag(b"#a ", [b"#a"])
    _check_hashtag(" #\U0000044f ".encode(), ["#\U0000044f".encode()])
    _check_hashtag(" \U0000044f#a ".encode(), [])
    _check_hashtag(b" #a# ", [])
    _check_hashtag(b" #123 ", [])
    _check_hashtag(b" #123a ", [b"#123a"])
    _check_hashtag(b" #a123 ", [b"#a123"])
    _check_hashtag(b" #123a# ", [])
    _check_hashtag(b" #" + b"1" * 300, [])
    _check_hashtag(b" #" + b"1" * 256, [])
    _check_hashtag(b" #" + b"1" * 256 + b"a ", [])
    _check_hashtag(b" #" + b"1" * 255 + b"a", [b"#" + b"1" * 255 + b"a"])
    _check_hashtag(
        b" #" + b"1" * 255 + "\U0000042f".encode(),
        [b"#" + b"1" * 255 + "\U0000042f".encode()],
    )
    _check_hashtag(b" #" + b"1" * 255 + b"a" + b"b" * 255 + b"# ", [])
    _check_hashtag(b"#a#b #c #d", [b"#c", b"#d"])
    _check_hashtag(b"#test", [b"#test"])
    _check_hashtag(b"#test@", [b"#test"])
    _check_hashtag(b"#test@a", [b"#test"])
    _check_hashtag(b"#test@ab", [b"#test"])
    _check_hashtag(b"#test@abc", [b"#test@abc"])
    _check_hashtag(b"#test@a-c", [b"#test"])
    _check_hashtag(
        b"#test@abcdefghijabcdefghijabcdefghijab",
        [b"#test@abcdefghijabcdefghijabcdefghijab"],
    )
    _check_hashtag(
        b"#test@abcdefghijabcdefghijabcdefghijabc",
        [b"#test@abcdefghijabcdefghijabcdefghijab"],
    )
    _check_hashtag("#te\U000000b7st".encode(), ["#te\U000000b7st".encode()])
    _check_hashtag(
        (
            "\U0001f604\U0001f604\U0001f604\U0001f604 \U0001f604\U0001f604\U0001f604#"
        ).encode()
        + b"1" * 200
        + "\U0000041e\U0000041e\U0000041e".encode()
        + b"2" * 200,
        [b"#" + b"1" * 200 + "\U0000041e\U0000041e\U0000041e".encode() + b"2" * 53],
    )
    _check_hashtag("#a\U00002122".encode(), [b"#a"])
    _check_hashtag("#a\U00000d79".encode(), [b"#a"])
    _check_hashtag(
        "#a\U00000d81\U00000d82\U00000df4\U00000e01\U00000e3f".encode(),
        ["#a\U00000d81\U00000d82\U00000df4\U00000e01".encode()],
    )
    _check_hashtag(
        (
            b"#a12345678901234561234567890123456123456789012345612345678901234561234567"
            b"8901234561234567890123456123456789012345612345678901234561234567890123456"
            b"1234567890123456123456789012345612345678901234561234567890123456123456789"
            b"012345612345678901234561234567890123456"
        ),
        [
            (
                b"#a1234567890123456123456789012345612345678901234561234567890123456123"
                b"456789012345612345678901234561234567890123456123456789012345612345678"
                b"901234561234567890123456123456789012345612345678901234561234567890123"
                b"45612345678901234561234567890123456123456789012345"
            )
        ],
    )


# Ported from test/message_entities.cpp, check_cashtag().
def _check_cashtag(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_cashtags) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, cashtag).
def test_cashtag() -> None:  # noqa: PLR0915  # mirrors upstream
    _check_cashtag(b"", [])
    _check_cashtag(b"$", [])
    _check_cashtag(b"$$", [])
    _check_cashtag(b"$$$", [])
    _check_cashtag(b"$a", [])
    _check_cashtag(b" $a", [])
    _check_cashtag(b"$a ", [])
    _check_cashtag(" $\U0000044f ".encode(), [])
    _check_cashtag(b"$ab", [])
    _check_cashtag(b"$abc", [])
    _check_cashtag(b"$", [])
    _check_cashtag(b"$A", [b"$A"])
    _check_cashtag(b"$AB", [b"$AB"])
    _check_cashtag("$AB\U00000421".encode(), [])
    _check_cashtag("$\U00000410BC".encode(), [])
    _check_cashtag("$\U00000410\U00000412\U00000421".encode(), [])
    _check_cashtag(b"$ABC", [b"$ABC"])
    _check_cashtag(b"$ABCD", [b"$ABCD"])
    _check_cashtag(b"$ABCDE", [b"$ABCDE"])
    _check_cashtag(b"$ABCDEF", [b"$ABCDEF"])
    _check_cashtag(b"$ABCDEFG", [b"$ABCDEFG"])
    _check_cashtag(b"$ABCDEFGH", [b"$ABCDEFGH"])
    _check_cashtag(b"$ABCDEFGHJ", [])
    _check_cashtag(b"$ABCDEFGH1", [])
    _check_cashtag(b" $XYZ", [b"$XYZ"])
    _check_cashtag(b"$XYZ ", [b"$XYZ"])
    _check_cashtag(b" $XYZ ", [b"$XYZ"])
    _check_cashtag(b" $$XYZ ", [])
    _check_cashtag(b" $XYZ$ ", [])
    _check_cashtag(b" $ABC1 ", [])
    _check_cashtag(b" $1ABC ", [])
    _check_cashtag(b" 1$ABC ", [])
    _check_cashtag(" \U00000410$ABC ".encode(), [])
    _check_cashtag(b"$ABC$DEF $GHI $KLM", [b"$GHI", b"$KLM"])
    _check_cashtag(b"$TEST", [b"$TEST"])
    _check_cashtag(b"$TEST@", [b"$TEST"])
    _check_cashtag(b"$TEST@a", [b"$TEST"])
    _check_cashtag(b"$TEST@ab", [b"$TEST"])
    _check_cashtag(b"$TEST@abc", [b"$TEST@abc"])
    _check_cashtag(b"$TEST@a-c", [b"$TEST"])
    _check_cashtag(
        b"$TEST@abcdefghijabcdefghijabcdefghijab",
        [b"$TEST@abcdefghijabcdefghijabcdefghijab"],
    )
    _check_cashtag(b"$TEST@abcdefghijabcdefghijabcdefghijabc", [b"$TEST"])
    _check_cashtag(b"$1INC", [])
    _check_cashtag(b"$1INCH", [b"$1INCH"])
    _check_cashtag(b"...$1INCH...", [b"$1INCH"])
    _check_cashtag(b"$1inch", [])
    _check_cashtag(b"$1INCHA", [])
    _check_cashtag("$1INCH\U00000410".encode(), [])
    _check_cashtag("$ABC\U00002122".encode(), [b"$ABC"])
    _check_cashtag("\U00002122$ABC".encode(), [b"$ABC"])
    _check_cashtag("\U00002122$ABC\U00002122".encode(), [b"$ABC"])
    _check_cashtag("$ABC\U00000d79".encode(), [b"$ABC"])
    _check_cashtag("$ABC\U00000d81".encode(), [])
    _check_cashtag("$ABC\U00000d82".encode(), [])
    _check_cashtag("$ABC\U00000df4".encode(), [])
    _check_cashtag("$ABC\U00000e01".encode(), [])
    _check_cashtag("$ABC\U00000e3f".encode(), [b"$ABC"])


# TEST(MessageEntities, media_timestamp) stays out: a bot skips media timestamps, so the
# port finds none.


# Ported from test/message_entities.cpp, check_bank_card_number().
def _check_bank_card_number(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_bank_card_numbers) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, bank_card_number).
def test_bank_card_number() -> None:
    _check_bank_card_number(b"", [])
    _check_bank_card_number(b"123456789015", [])
    _check_bank_card_number(b"1234567890120", [])
    _check_bank_card_number(b"1234567890121", [])
    _check_bank_card_number(b"1234567890122", [])
    _check_bank_card_number(b"1234567890123", [])
    _check_bank_card_number(b"1234567890124", [])
    _check_bank_card_number(b"1234567890125", [])
    _check_bank_card_number(b"1234567890126", [])
    _check_bank_card_number(b"1234567890127", [])
    _check_bank_card_number(b"1234567890128", [b"1234567890128"])
    _check_bank_card_number(b"1234567890129", [])
    _check_bank_card_number(b"12345678901500", [b"12345678901500"])
    _check_bank_card_number(b"123456789012800", [b"123456789012800"])
    _check_bank_card_number(b"1234567890151800", [b"1234567890151800"])
    _check_bank_card_number(b"12345678901280000", [b"12345678901280000"])
    _check_bank_card_number(b"123456789015009100", [b"123456789015009100"])
    _check_bank_card_number(b"1234567890128000000", [b"1234567890128000000"])
    _check_bank_card_number(b"12345678901500910000", [])
    _check_bank_card_number(
        b" - - - - 1 - -- 2 - - -- 34 - - - 56- - 7890150000  - - - -", []
    )
    _check_bank_card_number(
        b" - - - - 1 - -- 234 - - 56- - 7890150000  - - - -",
        [b"1 - -- 234 - - 56- - 7890150000"],
    )
    _check_bank_card_number(
        b"4916-3385-0608-2832; 5280 9342 8317 1080 ;345936346788903",
        [b"4916-3385-0608-2832", b"5280 9342 8317 1080", b"345936346788903"],
    )
    _check_bank_card_number(
        b"4556728228023269, 4916141675244747020, 49161416752447470, 4556728228023269",
        [b"4556728228023269", b"4916141675244747020", b"4556728228023269"],
    )
    _check_bank_card_number(b"a1234567890128", [])
    _check_bank_card_number(b"1234567890128a", [])
    _check_bank_card_number("1234567890128\U00000430".encode(), [])
    _check_bank_card_number("\U000004301234567890128".encode(), [])
    _check_bank_card_number(b"1234567890128_", [])
    _check_bank_card_number(b"_1234567890128", [])
    _check_bank_card_number(b"1234567890128/", [b"1234567890128"])
    _check_bank_card_number(b'"1234567890128', [b"1234567890128"])
    _check_bank_card_number(b"+1234567890128", [])


# Ported from test/message_entities.cpp, check_ton_address().
def _check_ton_address(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_ton_addresses) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, ton_address).
def test_ton_address() -> None:
    _check_ton_address(b"", [])
    _check_ton_address(
        b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N",
        [b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N"],
    )
    _check_ton_address(
        b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBI",
        [b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBI"],
    )
    _check_ton_address(b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBJ", [])
    _check_ton_address(b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEB", [])
    _check_ton_address(b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBIA", [])
    _check_ton_address(
        b"UQDqgkqefbZu_fZ7-8eib6h3vLubZxQfu-KRi829HBBUGzWm",
        [b"UQDqgkqefbZu_fZ7-8eib6h3vLubZxQfu-KRi829HBBUGzWm"],
    )
    _check_ton_address(
        b"UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm",
        [b"UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm"],
    )
    _check_ton_address(b"UQDqgkqefbZu_fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm", [])
    _check_ton_address(
        b"====UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm.",
        [b"UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm"],
    )
    _check_ton_address(
        (
            b"#UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm EQCD39VS5jcptHL8vMjEXrz"
            b"GaRcCVYto7HUn4bpAOg8xqB2N"
        ),
        [
            b"UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm",
            b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N",
        ],
    )


# Ported from test/message_entities.cpp, check_tg_url().
def _check_tg_url(text: bytes, expected: list[bytes]) -> None:
    assert _matches(text, find_tg_urls) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, tg_url).
def test_tg_url() -> None:
    _check_tg_url(b"", [])
    _check_tg_url(b"tg://", [])
    _check_tg_url(b"tg://a", [b"tg://a"])
    _check_tg_url(b"a", [])
    _check_tg_url(b"stg://a", [b"tg://a"])
    _check_tg_url(
        (
            b"asd  asdas das ton:asd tg:test ton://resolve tg://resolve TON://_-RESOLVE"
            b"_- TG://-_RESOLVE-_"
        ),
        [b"ton://resolve", b"tg://resolve", b"TON://_-RESOLVE_-", b"TG://-_RESOLVE-_"],
    )
    _check_tg_url(b"tg:test/", [])
    _check_tg_url(b"tg:/test/", [])
    _check_tg_url(b"tg://test/", [b"tg://test/"])
    _check_tg_url(b"tg://test/?", [b"tg://test/"])
    _check_tg_url(b"tg://test/#", [b"tg://test/#"])
    _check_tg_url(b"tg://test?", [b"tg://test"])
    _check_tg_url(b"tg://test#", [b"tg://test"])
    _check_tg_url(
        (
            "tg://test/\U00002015asd\U00002015?asd=asd&asdas=\U00002015#\U00002015"
            "\U00002015\U00002015\U00002015"
        ).encode(),
        [
            (
                "tg://test/\U00002015asd\U00002015?asd=asd&asdas=\U00002015#\U00002015"
                "\U00002015\U00002015\U00002015"
            ).encode()
        ],
    )
    _check_tg_url(b"tg://test/?asd", [b"tg://test/?asd"])
    _check_tg_url(b"tg://test/?.:;,('?!`.:;,('?!`", [b"tg://test/"])
    _check_tg_url(b"tg://test/#asdf", [b"tg://test/#asdf"])
    _check_tg_url(b"tg://test?asdf", [b"tg://test?asdf"])
    _check_tg_url(b"tg://test#asdf", [b"tg://test#asdf"])
    _check_tg_url("tg://test?as\U00002016df".encode(), [b"tg://test?as"])
    _check_tg_url(b"tg://test?sa<df", [b"tg://test?sa"])
    _check_tg_url(b"tg://test?as>df", [b"tg://test?as"])
    _check_tg_url(b'tg://test?as"df', [b"tg://test?as"])
    _check_tg_url("tg://test?as\U000000abdf".encode(), [b"tg://test?as"])
    _check_tg_url("tg://test?as\U000000bbdf".encode(), [b"tg://test?as"])
    _check_tg_url(b"tg://test?as(df", [b"tg://test?as(df"])
    _check_tg_url(b"tg://test?as)df", [b"tg://test?as)df"])
    _check_tg_url(b"tg://test?as[df", [b"tg://test?as[df"])
    _check_tg_url(b"tg://test?as]df", [b"tg://test?as]df"])
    _check_tg_url(b"tg://test?as{df", [b"tg://test?as{df"])
    _check_tg_url(b"tg://test?as'df", [b"tg://test?as'df"])
    _check_tg_url(b"tg://test?as}df", [b"tg://test?as}df"])
    _check_tg_url(b"tg://test?as$df", [b"tg://test?as$df"])
    _check_tg_url(b"tg://test?as%df", [b"tg://test?as%df"])
    _check_tg_url(b"tg://%30/sccct", [])
    _check_tg_url(b"tg://test:asd@google.com:80", [b"tg://test"])
    _check_tg_url(b"tg://google.com", [b"tg://google"])
    _check_tg_url(b"tg://google/.com", [b"tg://google/.com"])
    _check_tg_url(b"tg://127.0.0.1", [b"tg://127"])
    _check_tg_url(
        "tg://\U00000431.\U00000430.\U0000043d.\U00000430.\U0000043d\U00000430".encode(),
        [],
    )


# Ported from test/message_entities.cpp, check_is_email_address().
def _check_is_email_address(text: bytes, expected: bool) -> None:
    assert is_email_address(text) == expected, text


# Ported from test/message_entities.cpp, TEST(MessageEntities, is_email_address).
def test_is_email_address() -> None:
    _check_is_email_address(b"telegram.org", False)
    _check_is_email_address(b"security@telegram.org", True)
    _check_is_email_address(b"security.telegram.org", False)
    _check_is_email_address(b"", False)
    _check_is_email_address(b"@", False)
    _check_is_email_address(b"A@a.a.a.ab", True)
    _check_is_email_address(b"A@a.ab", True)
    _check_is_email_address(b"Test@aa.aa.aa.aa", True)
    _check_is_email_address(b"Test@test.abd", True)
    _check_is_email_address(b"a@a.a.a.ab", True)
    _check_is_email_address(b"test@test.abd", True)
    _check_is_email_address(b"test@test.com", True)
    _check_is_email_address(b"test.abd", False)
    _check_is_email_address(b"a.ab", False)
    _check_is_email_address(b"a.bc@d.ef", True)

    bad_userdatas = [
        b"",
        b"a.a.a.a.a.a.a.a.a.a.a.a",
        b"+.+.+.+.+.+",
        b"*.a.a",
        b"a.*.a",
        b"a.a.*",
        b"a.a.",
        b"a.a.abcdefghijklmnopqrstuvwxyz0123456789",
        b"a.abcdefghijklmnopqrstuvwxyz0.a",
        b"abcdefghijklmnopqrstuvwxyz0.a.a",
    ]
    good_userdatas = [
        b"a.a.a.a.a.a.a.a.a.a.a",
        b"a+a+a+a+a+a+a+a+a+a+a",
        b"+.+.+.+.+._",
        b"aozAQZ0-5-9_+-aozAQZ0-5-9_.aozAQZ0-5-9_.-._.+-",
        b"a.a.a",
        b"a.a.abcdefghijklmnopqrstuvwxyz012345678",
        b"a.abcdefghijklmnopqrstuvwxyz.a",
        b"a..a",
        b"abcdefghijklmnopqrstuvwxyz.a.a",
        b".a.a",
    ]

    bad_domains = [
        b"",
        b".",
        b"abc",
        b"localhost",
        b"a.a.a.a.a.a.a.ab",
        b".......",
        b"a.a.a.a.a.a+ab",
        b"a+a.a.a.a.a.ab",
        b"a.a.a.a.a.a.a",
        b"a.a.a.a.a.a.abcdefghi",
        b"a.a.a.a.a.a.ab0yz",
        b"a.a.a.a.a.a.ab9yz",
        b"a.a.a.a.a.a.ab-yz",
        b"a.a.a.a.a.a.ab_yz",
        b"a.a.a.a.a.a.ab*yz",
        b".ab",
        b".a.ab",
        b"a..ab",
        b"a.a.a..a.ab",
        b".a.a.a.a.ab",
        b"abcdefghijklmnopqrstuvwxyz01234.ab",
        b"ab0cd.abd.aA*sd.0.9.0-9.ABOYZ",
        b"ab*cd.abd.aAasd.0.9.0-9.ABOYZ",
        b"ab0cd.abd.aAasd.0.9.0*9.ABOYZ",
        b"*b0cd.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0c*.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.0-*.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.*-9.ABOYZ",
        b"-b0cd.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0c-.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.-.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.--9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.0--.ABOYZ",
        b"_b0cd.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0c_.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd._.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9._-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.0-_.ABOYZ",
        b"-.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.-.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9.-.ABOYZ",
        b"_.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d._.0.9.0-9.ABOYZ",
        b"ab0cd.ab_d.aA-sd.0.9._.ABOYZ",
    ]
    good_domains = [
        b"a.a.a.a.a.a.ab",
        b"a.a.a.a.a.a.abcdef",
        b"a.a.a.a.a.a.aboyz",
        b"a.a.a.a.a.a.ABOYZ",
        b"a.a.a.a.a.a.AbOyZ",
        b"abcdefghijklmnopqrstuvwxyz0123.ab",
        b"ab0cd.ab_d.aA-sd.0.9.0-9.ABOYZ",
        b"A.Z.aA-sd.a.z.0-9.ABOYZ",
    ]

    for userdata in bad_userdatas:
        for domain in bad_domains:
            _check_is_email_address(userdata + b"@" + domain, False)
            _check_is_email_address(userdata + domain, False)
        for domain in good_domains:
            _check_is_email_address(userdata + b"@" + domain, False)
            _check_is_email_address(userdata + domain, False)
    for userdata in good_userdatas:
        for domain in bad_domains:
            _check_is_email_address(userdata + b"@" + domain, False)
            _check_is_email_address(userdata + domain, False)
        for domain in good_domains:
            _check_is_email_address(userdata + b"@" + domain, True)
            _check_is_email_address(userdata + domain, False)


# Ported from test/message_entities.cpp, check_url().
def _check_url(
    text: bytes,
    expected_urls: list[bytes],
    expected_email_addresses: Sequence[bytes] = (),
) -> None:
    urls = []
    email_addresses = []
    for (begin, end), is_email in find_urls(text):
        if is_email:
            email_addresses.append(text[begin:end])
        else:
            urls.append(text[begin:end])
    assert urls == expected_urls, text
    assert email_addresses == list(expected_email_addresses), text


# Ported from test/message_entities.cpp, TEST(MessageEntities, url).
def test_url() -> None:  # noqa: PLR0915  # mirrors upstream
    _check_url(b"telegram.org", [b"telegram.org"])
    _check_url(b"(telegram.org)", [b"telegram.org"])
    _check_url(b"\ntelegram.org)", [b"telegram.org"])
    _check_url(b" telegram.org)", [b"telegram.org"])
    _check_url(b".telegram.org)", [])
    _check_url(b"()telegram.org/?q=()", [b"telegram.org/?q=()"])
    _check_url(b'"telegram.org"', [b"telegram.org"])
    _check_url(
        b" telegram. org. www. com... telegram.org... ...google.com...",
        [b"telegram.org"],
    )
    _check_url(b" telegram.org ", [b"telegram.org"])
    _check_url(
        (
            "\U00000422\U00000430\U0000043a\U0000043e\U00000439 \U00000441\U00000430"
            "\U00000439\U00000442: http://www.google.com \U00000438\U0000043b\U00000438"
            " \U00000442\U00000430\U0000043a\U0000043e\U00000439 telegram.org "
        ).encode(),
        [b"http://www.google.com", b"telegram.org"],
    )
    _check_url(b" telegram.org. ", [b"telegram.org"])
    _check_url(b"http://google,.com", [])
    _check_url(
        b"http://telegram.org/?asd=123#123.", [b"http://telegram.org/?asd=123#123"]
    )
    _check_url(b"[http://google.com](test)", [b"http://google.com"])
    _check_url(b"", [])
    _check_url(b".", [])
    _check_url(b"http://@google.com", [])
    _check_url(b"http://@goog.com", [])
    _check_url(b"http://@@google.com", [])
    _check_url(b"http://a@google.com", [b"http://a@google.com"])
    _check_url(b"http://test@google.com", [b"http://test@google.com"])
    _check_url(
        "google.com:\U00001a89\U00001a89\U00001a89\U00001a89\U00001a89".encode(),
        [b"google.com"],
    )
    _check_url(b"https://telegram.org", [b"https://telegram.org"])
    _check_url(b"http://telegram.org", [b"http://telegram.org"])
    _check_url(b"ftp://telegram.org", [b"ftp://telegram.org"])
    _check_url(b"ftps://telegram.org", [])
    _check_url(b"sftp://telegram.org", [])
    _check_url(b"tonsite://telegram.ton", [b"tonsite://telegram.ton"])
    _check_url(b"telegram.ton", [b"telegram.ton"])
    _check_url(b"telegram.onion", [b"telegram.onion"])
    _check_url(b"telegram.tonsite", [])
    _check_url(b"hTtPs://telegram.org", [b"hTtPs://telegram.org"])
    _check_url(b"HTTP://telegram.org", [b"HTTP://telegram.org"])
    _check_url("\U00000430HTTP://telegram.org".encode(), [b"HTTP://telegram.org"])
    _check_url(b"sHTTP://telegram.org", [])
    _check_url(b"://telegram.org", [])
    _check_url("google.com:\U00001a80\U00001a80".encode(), [b"google.com"])
    _check_url(
        (
            b"http://abcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijk"
            b"abcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefg"
            b"hijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabc"
            b"defghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghij"
            b"kabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdef"
            b"ghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkab"
            b"cdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghi"
            b"jkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcde"
            b"fghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijka"
            b"bcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefgh"
            b"ijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcd"
            b"efghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijkabcdefghijk"
            b".com"
        ),
        [],
    )
    _check_url("http://\U00002009\U00002009.com".encode(), [])
    _check_url("URL: \U00002009\U00002009\U00002009\U00002009.com".encode(), [])
    _check_url("URL:\U00002009.com".encode(), [])
    _check_url(b".com", [])
    _check_url("http://\U00002009\U00002009.".encode(), [])
    _check_url(b"http://.", [])
    _check_url(b"http://.com", [])
    _check_url(b"http://  .", [])
    _check_url(b",ahttp://google.com", [b"http://google.com"])
    _check_url(b".ahttp://google.com", [])
    _check_url(b"http://1.0", [])
    _check_url(b"http://a.0", [])
    _check_url(b"http://a.a", [])
    _check_url(b"google.com:1#ab c", [b"google.com:1#ab"])
    _check_url(b"google.com:1#", [b"google.com:1"])
    _check_url(b"google.com:1#1", [b"google.com:1#1"])
    _check_url(b"google.com:00000001/abs", [b"google.com:00000001/abs"])
    _check_url(b"google.com:000000065535/abs", [b"google.com:000000065535/abs"])
    _check_url(b"google.com:000000065536/abs", [b"google.com"])
    _check_url(b"google.com:000000080/abs", [b"google.com:000000080/abs"])
    _check_url(b"google.com:0000000/abs", [b"google.com"])
    _check_url(b"google.com:0/abs", [b"google.com"])
    _check_url(b"google.com:/abs", [b"google.com"])
    _check_url(b"google.com:65535", [b"google.com:65535"])
    _check_url(b"google.com:65536", [b"google.com"])
    _check_url(b"google.com:99999", [b"google.com"])
    _check_url(b"google.com:100000", [b"google.com"])
    _check_url(b"127.001", [])
    _check_url(b"127.0.0.1", [b"127.0.0.1"])
    _check_url(b"127.0.0.01", [])
    _check_url(b"127.0.0.256", [])
    _check_url(b"127.0.0.300", [])
    _check_url(b"127.0.0.1000", [])
    _check_url(b"127.0.0.260", [])
    _check_url(b"1.0", [])
    _check_url("www.\U0001f919.tk".encode(), ["www.\U0001f919.tk".encode()])
    _check_url(b"a.ab", [])
    _check_url(b"test.abd", [])
    _check_url(
        (
            "\U00000422\U00000435\U00000421\U00000442.\U0000041c\U0000043e\U00000441"
            "\U0000043a\U00000432\U00000430"
        ).encode(),
        [],
    )
    _check_url(
        (
            "\U00000422\U00000435\U00000421\U00000442.\U0000041c\U0000043e\U00000421"
            "\U0000043a\U00000412\U00000391"
        ).encode(),
        [],
    )
    _check_url(
        (
            "\U00000422\U00000435\U00000421\U00000442.\U0000041c\U0000043e\U00000421"
            "\U0000043a\U00000412\U00000430"
        ).encode(),
        [
            (
                "\U00000422\U00000435\U00000421\U00000442.\U0000041c\U0000043e"
                "\U00000421\U0000043a\U00000412\U00000430"
            ).encode()
        ],
    )
    _check_url(
        (
            "\U00000422\U00000435\U00000421\U00000442.\U0000041c\U0000043e\U00000421"
            "\U0000043a\U00000412\U00000430\U00000447"
        ).encode(),
        [],
    )
    _check_url(
        (
            "http://\U000000c0\U00000422\U00000435\U00000421\U00000442.\U0000041c"
            "\U0000043e\U00000421\U0000043a\U00000412\U00000430\U00000447"
        ).encode(),
        [
            (
                "http://\U000000c0\U00000422\U00000435\U00000421\U00000442.\U0000041c"
                "\U0000043e\U00000421\U0000043a\U00000412\U00000430\U00000447"
            ).encode()
        ],
    )
    _check_url(
        "\U000000c0\U000000c1.com. \U000000c0\U000000c1.com.".encode(),
        ["\U000000c0\U000000c1.com".encode(), "\U000000c0\U000000c1.com".encode()],
    )
    _check_url(
        "\U000000c0\U000000c1.com,\U000000c0\U000000c1.com.".encode(),
        ["\U000000c0\U000000c1.com".encode(), "\U000000c0\U000000c1.com".encode()],
    )
    _check_url(b"teiegram.org/test", [])
    _check_url(b"TeiegraM.org/test", [])
    _check_url(
        b"http://test.google.com/?q=abc()}[]def", [b"http://test.google.com/?q=abc()"]
    )
    _check_url(
        b"http://test.google.com/?q=abc([{)]}def",
        [b"http://test.google.com/?q=abc([{)]}def"],
    )
    _check_url(
        b"http://test.google.com/?q=abc(){}]def", [b"http://test.google.com/?q=abc(){}"]
    )
    _check_url(
        b"http://test.google.com/?q=abc){}[]def", [b"http://test.google.com/?q=abc"]
    )
    _check_url(
        b"http://test.google.com/?q=abc(){}[]def",
        [b"http://test.google.com/?q=abc(){}[]def"],
    )
    _check_url(b"http://test-.google.com", [])
    _check_url(b"http://test_.google.com", [b"http://test_.google.com"])
    _check_url(b"http://google_.com", [])
    _check_url(b"http://google._com_", [])
    _check_url(b"http://[2001:4860:0:2001::68]/", [])
    _check_url(b"tg://resolve", [])
    _check_url(b"test.abd", [])
    _check_url(b"/.b/..a    @.....@/. a.ba", [b"a.ba"])
    _check_url(b"bbbbbbbbbbbbbb.@.@", [])
    _check_url(b"http://google.com/", [b"http://google.com/"])
    _check_url(b"http://google.com?", [b"http://google.com"])
    _check_url(b"http://google.com#", [b"http://google.com"])
    _check_url(b"http://google.com##", [b"http://google.com##"])
    _check_url(b"http://google.com/?", [b"http://google.com/"])
    _check_url(b"https://www.google.com/ab,", [b"https://www.google.com/ab"])
    _check_url(b"@.", [])
    _check_url(
        (
            'a.b.google.com dfsknnfs gsdfgsg http://c\U000000f3duia.de/ dffdg," 12)(cp'
            'ia.de/())(" http://\U00000433\U00000440\U00000438\U00000448\U0000043a'
            "\U00000430.\U00000440\U00000444/ sdufhdf http://xn--80afpi2a3c.xn--p1ai/ I"
            " have a good time.Thanks, guys!\n\n(hdfughidufhgdis) go#ogle.com "
            "\U00000433\U00000440\U00000438\U00000448\U0000043a\U00000430.\U00000440"
            "\U00000444 hsighsdf gi \U0000043f\U0000043e\U00000447\U00000442\U00000430."
            "\U00000440\U00000444\n\n\U0000272adf.ws/123      xn--80afpi2a3c.xn--p1ai\n"
            "\nhttp://foo.com/blah_blah\nhttp://foo.com/blah_blah/\n(Something like htt"
            "p://foo.com/blah_blah)\nhttp://foo.com/blah_blah_(wikipedi8989a_\U00000412"
            "\U00000430\U00000441\U0000044f)\n(Something like http://foo.com/blah_blah_"
            "(\U00000421\U00000442\U00000430\U0000043a\U00000430\U0000043d_007))\nhttp:"
            "//foo.com/blah_blah.\nhttp://foo.com/blah_blah/.\n<http://foo.com/blah_bla"
            "h>\n<http://fo@@@@@@@@@^%#*@^&@$#*@#%^*&!^#o.com/blah_blah/>\nhttp://foo.c"
            "om/blah_blah,\nhttp://www.example.com/wpstyle/?p=364.\nhttp://\U0000272adf"
            ".ws/123\nrdar://1234\nrdar:/1234\nhttp://userid:password@example.com:8080"
            "\nhttp://userid@example.com\nhttp://userid@example.com:8080\nhttp://userid"
            ":password@example.com\nhttp://example.com:8080 x-yojimbo-item://6303E4C1-x"
            "xxx-45A6-AB9D-3A908F59AE0E\nmessage://%3c330e7f8409726r6a4ba78dkf1fd71420c"
            "1bf6ff@mail.gmail.com%3e\nhttp://\U000027a1\U0000fe0f.ws/\U00004a39\nwww."
            "\U000027a1\U0000fe0f.ws/\U00004a39\n<tag>http://example.com</tag>\nJust a "
            "www.example.com link.\n\n\U000027a1\U0000fe0f.ws/\U00004a39\n\nabcdefghijk"
            "lmnopqrstuvwxyz0123456789qwe_sdfsdf.aweawe-sdfs.com\nwww.\U0001f919.tk:1\n"
            "google.com:\U00001a89\U00001a89\U00001a89\U00001a89\ngoogle.com:\U00001a80"
            "\U00001a80\nhttp://\U00002009\U00002009.com\nURL: \U00002009\U00002009"
            "\U00002009\U00002009.com\nURL: .com\n\ngoogle.com?qwe\ngoogle.com#qwe\ngoo"
            "gle.com/?\ngoogle.com/#\ngoogle.com?\ngoogle.com#\n"
        ).encode(),
        [
            b"a.b.google.com",
            "http://c\U000000f3duia.de/".encode(),
            b"cpia.de/()",
            (
                "http://\U00000433\U00000440\U00000438\U00000448\U0000043a\U00000430."
                "\U00000440\U00000444/"
            ).encode(),
            b"http://xn--80afpi2a3c.xn--p1ai/",
            (
                "\U00000433\U00000440\U00000438\U00000448\U0000043a\U00000430."
                "\U00000440\U00000444"
            ).encode(),
            (
                "\U0000043f\U0000043e\U00000447\U00000442\U00000430.\U00000440"
                "\U00000444"
            ).encode(),
            "\U0000272adf.ws/123".encode(),
            b"xn--80afpi2a3c.xn--p1ai",
            b"http://foo.com/blah_blah",
            b"http://foo.com/blah_blah/",
            b"http://foo.com/blah_blah",
            (
                "http://foo.com/blah_blah_(wikipedi8989a_\U00000412\U00000430\U00000441"
                "\U0000044f)"
            ).encode(),
            (
                "http://foo.com/blah_blah_(\U00000421\U00000442\U00000430\U0000043a"
                "\U00000430\U0000043d_007)"
            ).encode(),
            b"http://foo.com/blah_blah",
            b"http://foo.com/blah_blah/",
            b"http://foo.com/blah_blah",
            b"http://foo.com/blah_blah",
            b"http://www.example.com/wpstyle/?p=364",
            "http://\U0000272adf.ws/123".encode(),
            b"http://userid:password@example.com:8080",
            b"http://userid@example.com",
            b"http://userid@example.com:8080",
            b"http://userid:password@example.com",
            b"http://example.com:8080",
            "http://\U000027a1\U0000fe0f.ws/\U00004a39".encode(),
            "www.\U000027a1\U0000fe0f.ws/\U00004a39".encode(),
            b"http://example.com",
            b"www.example.com",
            "\U000027a1\U0000fe0f.ws/\U00004a39".encode(),
            b"abcdefghijklmnopqrstuvwxyz0123456789qwe_sdfsdf.aweawe-sdfs.com",
            "www.\U0001f919.tk:1".encode(),
            b"google.com",
            b"google.com",
            b"google.com?qwe",
            b"google.com#qwe",
            b"google.com/",
            b"google.com/#",
            b"google.com",
            b"google.com",
        ],
    )
    _check_url("https://t.\U00002026".encode(), [])
    _check_url(
        b"('http://telegram.org/a-b/?br=ie&lang=en',)",
        [b"http://telegram.org/a-b/?br=ie&lang=en"],
    )
    _check_url(
        b"https://ai.telegram.org/bot%20bot/test-...",
        [b"https://ai.telegram.org/bot%20bot/test-"],
    )
    _check_url(b"a.bc@c.com", [], [b"a.bc@c.com"])
    _check_url(b"https://a.bc@c.com", [b"https://a.bc@c.com"])
    _check_url(b"https://a.de[bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de/bc@c.com", [b"https://a.de/bc@c.com"])
    _check_url(b"https://a.de]bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de{bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de}bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de(bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de)bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.debc@c.com", [b"https://a.debc@c.com"])
    _check_url(b"https://a.de'bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.de`bc@c.com", [b"https://a.de"], [b"bc@c.com"])
    _check_url(b"https://a.bcde.fg@c.com", [b"https://a.bcde.fg@c.com"])
    _check_url(b"https://a:h.bcde.fg@c.com", [b"https://a:h.bcde.fg@c.com"])
    _check_url(b"https://abc@c.com", [b"https://abc@c.com"])
    _check_url(b"https://de[bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de/bc@c.com", [])
    _check_url(b"https://de]bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de{bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de}bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de(bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de)bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de\\bc@c.com", [b"https://de\\bc@c.com"])
    _check_url(b"https://de'bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://de`bc@c.com", [], [b"bc@c.com"])
    _check_url(b"https://bc:defg@c.com", [b"https://bc:defg@c.com"])
    _check_url(b"https://a:hbc:defg@c.com", [b"https://a:hbc:defg@c.com"])
    _check_url(b"https://a.bc@test.com:cd.com", [b"https://a.bc@test.com", b"cd.com"])
    _check_url(b"telegram.Org", [])
    _check_url(b"telegram.ORG", [b"telegram.ORG"])
    _check_url(b"a.b.c.com.a.b.c", [])
    _check_url(b"File '/usr/views.py'", [])
    _check_url(b"@views.py'", [])
    _check_url(b"#views.py'", [])
    _check_url(b"/views.py'", [])
    _check_url(b".views.py", [])
    _check_url(b"'views.py'", [b"views.py"])
    _check_url(b"bug.http://test.com/test/+#", [])
    _check_url(b"//AB.C.D.E.F.GH//", [])
    _check_url(
        b"<http://www.ics.uci.edu/pub/ietf/uri/historical.html#WARNING>",
        [b"http://www.ics.uci.edu/pub/ietf/uri/historical.html#WARNING"],
    )
    _check_url(b"Look :test@example.com", [b":test@example.com"], [])
    _check_url(b"Look mailto:test@example.com", [], [b"test@example.com"])
    _check_url(b"http://test.com#a", [b"http://test.com#a"])
    _check_url(b"http://test.com#", [b"http://test.com"])
    _check_url(b"http://test.com?#", [b"http://test.com?#"])
    _check_url(b"http://test.com/?#", [b"http://test.com/?#"])
    _check_url("https://t.me/abcdef\U00002026".encode(), [b"https://t.me/abcdef"])
    _check_url("https://t.me\U00002026".encode(), [b"https://t.me"])
    _check_url("https://t.m\U00002026".encode(), [])
    _check_url("https://t.\U00002026".encode(), [])
    _check_url("https://t\U00002026".encode(), [])
    _check_url(
        "\U0001f449http://ab.com/cdefgh-1IJ".encode(), [b"http://ab.com/cdefgh-1IJ"]
    )
    _check_url("...\U0001f449http://ab.com/cdefgh-1IJ".encode(), [])
    _check_url(b".?", [])
    _check_url(
        (
            "http://test\U00002015\U00002011@\U00002015google\U00002015.\U00002015com"
            "\U00002015/\U00002015\U00002013\U00002015\U00002010\U00002015/\U00002015/"
            "\U00002015/\U00002015?\U00002015\U00002011\U00002015#\U00002015\U00002015"
            "\U00002015"
        ).encode(),
        [
            (
                "http://test\U00002015\U00002011@\U00002015google\U00002015.\U00002015c"
                "om\U00002015/\U00002015\U00002013\U00002015\U00002010\U00002015/"
                "\U00002015/\U00002015/\U00002015?\U00002015\U00002011\U00002015#"
                "\U00002015\U00002015\U00002015"
            ).encode()
        ],
    )
    _check_url("http://google.com/\U00002016".encode(), [b"http://google.com/"])
    _check_url(b"a@b@c.com", [], [])
    _check_url(b"abc@c.com@d.com", [])
    _check_url(b"a@b.com:c@1", [], [b"a@b.com"])
    _check_url(b"test@test.software", [], [b"test@test.software"])
    _check_url(b"a:b?@gmail.com", [])
    _check_url(b"a?:b@gmail.com", [])
    _check_url(b"a#:b@gmail.com", [])
    _check_url(b"a:b#@gmail.com", [])
    _check_url(b"a!:b@gmail.com", [b"a!:b@gmail.com"])
    _check_url(b"a:b!@gmail.com", [b"a:b!@gmail.com"])
    _check_url(b"http://test_.com", [])
    _check_url(b"test_.com", [])
    _check_url(b"_test.com", [])
    _check_url(b"_.test.com", [b"_.test.com"])


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, const td::string &expected_str, ...).
def _check_fix_formatted_text(
    text: bytes,
    entities: tuple[MessageEntity, ...],
    expected_text: bytes,
    expected_entities: tuple[MessageEntity, ...],
    allow_empty: bool = True,
    skip_new_entities: bool = False,
    skip_bot_commands: bool = False,
    skip_trim: bool = True,
) -> None:
    result = fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=False,
        skip_new_entities=skip_new_entities,
        skip_bot_commands=skip_bot_commands,
        skip_trim=skip_trim,
    )
    assert result == FormattedText(expected_text, expected_entities)


# Ported from test/message_entities.cpp, check_fix_formatted_text(td::string str,
# td::vector<td::MessageEntity> entities, bool allow_empty, ...).
def _check_fix_formatted_text_fails(
    text: bytes,
    entities: tuple[MessageEntity, ...],
    allow_empty: bool,
    skip_new_entities: bool,
    skip_bot_commands: bool,
    skip_trim: bool,
) -> None:
    result = fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=False,
        skip_new_entities=skip_new_entities,
        skip_bot_commands=skip_bot_commands,
        skip_trim=skip_trim,
    )
    assert isinstance(result, Failure)


# Ported from test/message_entities.cpp, TEST(MessageEntities, fix_formatted_text), its
# loop over random texts. It stays out of the test's body, since CPython 3.12 traces
# each line in a time that grows with the length of the function holding it.
def _check_fix_formatted_text_on_random_texts() -> None:  # noqa: PLR0912, PLR0915  # mirrors upstream
    # td::Random, seeded so that a failure reproduces.
    rng = random.Random(20261119)
    for test_n in range(100000):
        is_url = rng.random() < 0.5
        url_offset = 0
        url_end = 0
        if is_url:
            text = (
                b"a" * rng.randint(1, 5) + b":example.com:" + b"a" * rng.randint(1, 5)
            )
            url_offset = text.find(b"e")
            url_end = url_offset + 11
        else:
            text = b"a" * rng.randint(1, 20)

        n = rng.randint(1, 20)
        entity_list = []
        for _ in range(n):
            entity_type = rng.randint(4, TYPE.SIZE - 1)
            offset = rng.randint(0, len(text) - 1)
            max_length = len(text) - offset
            if (test_n & 1) != 0 and max_length > 4:
                max_length = 4
            length = rng.randint(0, max_length)
            entity_list.append(MessageEntity(entity_type, offset, length))

        def get_type_mask(
            length: int, entities: tuple[MessageEntity, ...]
        ) -> list[int]:
            result = [0] * length
            for entity in entities:
                for pos in range(entity.length):
                    result[entity.offset + pos] |= 1 << entity.type
            return result

        old_type_mask = get_type_mask(len(text), tuple(entity_list))
        result = fix_formatted_text(
            text,
            tuple(entity_list),
            allow_empty=False,
            allow_empty_string=False,
            skip_new_entities=False,
            skip_bot_commands=True,
            skip_trim=False,
        )
        case = (test_n, text, entity_list)
        assert not isinstance(result, Failure), case
        text = result.text
        entities = result.entities
        new_type_mask = get_type_mask(len(text), entities)
        splittable_mask = (1 << 5) | (1 << 6) | (1 << 14) | (1 << 15) | (1 << 19)
        pre_mask = (1 << 7) | (1 << 8) | (1 << 9)
        for pos in range(len(text)):
            if (new_type_mask[pos] & pre_mask) != 0:
                assert (new_type_mask[pos] & splittable_mask) == 0, case
            else:
                assert (old_type_mask[pos] & splittable_mask) == (
                    new_type_mask[pos] & splittable_mask
                ), case
        keep_url = is_url
        url_entity = MessageEntity(TYPE.URL, url_offset, url_end - url_offset)
        for entity in entities:
            if entity == url_entity:
                continue
            offset = entity.offset
            end = offset + entity.length

            if (
                keep_url
                and ((1 << entity.type) & splittable_mask) == 0
                and not (end <= url_offset or url_end <= offset)
            ):
                keep_url = (
                    entity.type in (TYPE.BLOCK_QUOTE, TYPE.EXPANDABLE_BLOCK_QUOTE)
                    and offset <= url_offset
                    and url_end <= end
                )
        assert keep_url == (entities.count(url_entity) == 1), case

        for i in range(len(entities)):
            type_mask = 1 << entities[i].type
            for j in range(i + 1, len(entities)):
                # sorted
                assert entities[j].offset > entities[i].offset or (
                    entities[j].offset == entities[i].offset
                    and entities[j].length <= entities[i].length
                ), case

                # not intersecting
                assert (
                    entities[j].offset >= entities[i].offset + entities[i].length
                    or entities[j].offset + entities[j].length
                    <= entities[i].offset + entities[i].length
                ), case

                if entities[j].offset < entities[i].offset + entities[i].length:
                    # types are different
                    assert entities[j].type != entities[i].type, case

                    # pre can't contain other entities
                    assert (type_mask & pre_mask) == 0, case

                    if (type_mask & splittable_mask) == 0 and entities[i].type not in (
                        TYPE.BLOCK_QUOTE,
                        TYPE.EXPANDABLE_BLOCK_QUOTE,
                    ):
                        # continuous entities can contain only splittable entities
                        assert ((1 << entities[j].type) & splittable_mask) != 0, case


# Ported from test/message_entities.cpp, TEST(MessageEntities, fix_formatted_text).
def test_fix_formatted_text() -> None:  # noqa: PLR0912, PLR0915  # mirrors upstream
    text = b""
    fixed_text = b""
    for i in range(33):
        text += bytes([i])
        if i != 13:
            if i != 10:
                fixed_text += b" "
            else:
                fixed_text += text[-1:]

    _check_fix_formatted_text(text, (), b"", (), True, True, True, True)
    _check_fix_formatted_text(text, (), b"", (), True, True, False, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, True, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, False, True)
    _check_fix_formatted_text(text, (), b"", (), True, False, False, False)
    _check_fix_formatted_text_fails(text, (), False, False, False, False)
    _check_fix_formatted_text_fails(text, (), False, False, False, True)

    _check_fix_formatted_text(b"  aba\n ", (), b"  aba\n ", (), True, True, True, True)
    _check_fix_formatted_text(b"  aba\n ", (), b"aba", (), True, True, True, False)
    _check_fix_formatted_text(b"  \n ", (), b"", (), True, True, True, True)
    _check_fix_formatted_text(b"  \n ", (), b"", (), True, True, True, False)
    _check_fix_formatted_text_fails(b"  \n ", (), False, True, True, False)

    text += b"a  \r\n  "
    fixed_text += b"a  \n  "

    for i in range(33, 36):
        entities: tuple[MessageEntity, ...] = (MessageEntity(TYPE.PRE, 0, i),)

        fixed_entities: tuple[MessageEntity, ...] = (MessageEntity(TYPE.PRE, 0, i - 1),)
        _check_fix_formatted_text(
            text, entities, fixed_text, fixed_entities, True, False, False, True
        )

        expected_text = fixed_text[:33]
        fixed_entities = (MessageEntity(TYPE.PRE, 0, 32 if i == 33 else 33),)
        _check_fix_formatted_text(
            text, entities, expected_text, fixed_entities, False, False, False, False
        )

    for i in range(33, 36):
        entities = (MessageEntity(TYPE.BOLD, 0, i),)

        fixed_entities = (MessageEntity(TYPE.BOLD, 0, i - 1),)  # deleted \r
        _check_fix_formatted_text(
            text, entities, fixed_text, fixed_entities, True, False, False, True
        )

        expected_text = fixed_text[:33]
        if i != 33:
            fixed_entities = (MessageEntity(TYPE.BOLD, 0, 33),)
        _check_fix_formatted_text(
            text, entities, expected_text, fixed_entities, False, False, False, False
        )

    text = "\U0001f449 \U0001f449  ".encode()
    for i in range(10):
        entities = (MessageEntity(TYPE.BOLD, i, 1),)
        if i not in (2, 5, 6):
            _check_fix_formatted_text_fails(text, entities, True, True, True, True)
            _check_fix_formatted_text_fails(text, entities, False, False, False, False)
        else:
            _check_fix_formatted_text(
                text,
                entities,
                text,
                (MessageEntity(TYPE.BOLD, i, 1),),
                True,
                True,
                True,
                True,
            )
            if i == 2:
                _check_fix_formatted_text(
                    text,
                    entities,
                    text[:-2],
                    (MessageEntity(TYPE.BOLD, i, 1),),
                    False,
                    False,
                    False,
                    False,
                )
            else:
                _check_fix_formatted_text(
                    text, entities, text[:-2], (), False, False, False, False
                )

    text = b"  /test @abaca #ORD $ABC  telegram.org "
    for skip_trim in (False, True):
        shift = 2 if skip_trim else 0
        expected_text = text if skip_trim else text[2 : len(text) - 1]

        for skip_new_entities in (False, True):
            for skip_bot_commands in (False, True):
                found: list[MessageEntity] = []
                if not skip_new_entities:
                    if not skip_bot_commands:
                        found.append(MessageEntity(TYPE.BOT_COMMAND, shift, 5))
                    found.append(MessageEntity(TYPE.MENTION, shift + 6, 6))
                    found.append(MessageEntity(TYPE.HASHTAG, shift + 13, 4))
                    found.append(MessageEntity(TYPE.CASHTAG, shift + 18, 4))
                    found.append(MessageEntity(TYPE.URL, shift + 24, 12))

                _check_fix_formatted_text(
                    text,
                    (),
                    expected_text,
                    tuple(found),
                    True,
                    skip_new_entities,
                    skip_bot_commands,
                    skip_trim,
                )
                _check_fix_formatted_text(
                    text,
                    (),
                    expected_text,
                    tuple(found),
                    False,
                    skip_new_entities,
                    skip_bot_commands,
                    skip_trim,
                )

    text = b"aba \r\n caba "
    user_id = 1
    for length in range(1, 4):
        for offset in range(len(text) - length + 1):
            for entity_type in (TYPE.BOLD, TYPE.URL, TYPE.TEXT_URL, TYPE.MENTION_NAME):
                for skip_trim in (False, True):
                    fixed_text = b"aba \n caba " if skip_trim else b"aba \n caba"
                    fixed_length = (
                        length - 1 if offset <= 4 and offset + length >= 5 else length
                    )
                    fixed_offset = offset - 1 if offset >= 5 else offset
                    while fixed_offset + fixed_length > len(fixed_text):
                        fixed_length -= 1

                    entity = MessageEntity(entity_type, offset, length)
                    if entity_type == TYPE.TEXT_URL:
                        entity = replace(entity, argument=b"t.me")
                    elif entity_type == TYPE.MENTION_NAME:
                        entity = replace(entity, user_id=user_id)
                    fixed_entities = ()
                    if fixed_length > 0:
                        fixed_entities = (
                            replace(entity, offset=fixed_offset, length=fixed_length),
                        )
                    _check_fix_formatted_text(
                        text,
                        (entity,),
                        fixed_text,
                        fixed_entities,
                        True,
                        False,
                        False,
                        skip_trim,
                    )

    text = b"aba caba"
    for length in range(-10, 11):
        for offset in range(-10, 11):
            entities = (MessageEntity(TYPE.BOLD, offset, length),)
            if length < 0 or offset < 0 or (length > 0 and length + offset > len(text)):
                _check_fix_formatted_text_fails(
                    text, entities, True, False, False, False
                )
                _check_fix_formatted_text_fails(
                    text, entities, False, False, False, True
                )
                continue

            fixed_entities = ()
            if length > 0:
                fixed_entities = (MessageEntity(TYPE.BOLD, offset, length),)

            _check_fix_formatted_text(
                text, entities, text, fixed_entities, True, False, False, False
            )
            _check_fix_formatted_text(
                text, entities, text, fixed_entities, False, False, False, True
            )

    text = b"abadcaba"
    for length in range(1, 8):
        for offset in range(9 - length):
            for length2 in range(1, 8):
                for offset2 in range(9 - length2):
                    if offset != offset2:
                        entities = (
                            MessageEntity(TYPE.TEXT_URL, offset, length, b"t.me"),
                            MessageEntity(TYPE.TEXT_URL, offset2, length2, b"t.me"),
                            MessageEntity(TYPE.TEXT_URL, offset2 + length2, 1),
                        )
                        # std::sort, of two entities that start apart.
                        fixed = sorted(entities[:2], key=lambda entity: entity.offset)
                        if fixed[0].offset + fixed[0].length > fixed[1].offset:
                            fixed.pop()
                        _check_fix_formatted_text(
                            text,
                            entities,
                            text,
                            tuple(fixed),
                            False,
                            False,
                            False,
                            False,
                        )

    for raw in (
        " \n \U000027a1\U0000fe0f \U000027a1\U0000fe0f \U000027a1\U0000fe0f"
        " \U000027a1\U0000fe0f  \n ",
        "\n\n\nab cd ef gh        ",
    ):
        text = raw.encode()
        entity_list = []
        fixed_entity_list = []

        length = utf8_utf16_length(text)
        for i in range(10):
            if (i + 1) * 3 + 2 <= length:
                entity_list.append(MessageEntity(TYPE.BOLD, (i + 1) * 3, 2))
            if (i + 2) * 3 <= length:
                entity_list.append(MessageEntity(TYPE.ITALIC, (i + 1) * 3 + 2, 1))

            if i < 4:
                fixed_entity_list.append(MessageEntity(TYPE.BOLD, i * 3, 2))
            if i < 3:
                fixed_entity_list.append(MessageEntity(TYPE.ITALIC, i * 3 + 2, 1))

        # td::utf8_utf16_substr(str, 3, 11)
        expected_text = raw.encode("utf-16-le")[6:28].decode("utf-16-le").encode()
        _check_fix_formatted_text(
            text,
            tuple(entity_list),
            expected_text,
            tuple(fixed_entity_list),
            False,
            False,
            False,
            False,
        )

    for text in (b"\t", b"\r", b"\n", b"\t ", b"\r ", b"\n "):
        for entity_type in (TYPE.BOLD, TYPE.TEXT_URL):
            _check_fix_formatted_text(
                text,
                (MessageEntity(entity_type, 0, 1, b"http://telegram.org/"),),
                b"",
                (),
                True,
                False,
                False,
                True,
            )
    _check_fix_formatted_text(
        b"\r ",
        (MessageEntity(TYPE.BOLD, 0, 2), MessageEntity(TYPE.UNDERLINE, 0, 1)),
        b"",
        (),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r",
        (MessageEntity(TYPE.BOLD, 0, 3), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a ",
        (MessageEntity(TYPE.BOLD, 0, 2),),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r ",
        (MessageEntity(TYPE.BOLD, 0, 4), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a  ",
        (MessageEntity(TYPE.BOLD, 0, 3),),
        True,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"a \r b",
        (MessageEntity(TYPE.BOLD, 0, 5), MessageEntity(TYPE.UNDERLINE, 2, 1)),
        b"a  b",
        (MessageEntity(TYPE.BOLD, 0, 4),),
        True,
        False,
        False,
        True,
    )

    _check_fix_formatted_text(
        b"a\rbc\r",
        (
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 0, 2),
            MessageEntity(TYPE.ITALIC, 3, 2),
            MessageEntity(TYPE.BOLD, 3, 1),
        ),
        b"abc",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
    )
    _check_fix_formatted_text(
        b"a ",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 0, 1)),
        b"a",
        (MessageEntity(TYPE.BOLD, 0, 1), MessageEntity(TYPE.ITALIC, 0, 1)),
        False,
        False,
        False,
        False,
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1), MessageEntity(TYPE.ITALIC, 0, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1), MessageEntity(TYPE.ITALIC, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 1, 1),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.ITALIC, 1, 2)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.ITALIC, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.ITALIC, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.ITALIC, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 1, 2)),
        b"abc",
        (
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 1, 2),
            MessageEntity(TYPE.ITALIC, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 2), MessageEntity(TYPE.BOLD, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.BOLD, 2, 1)),
        b"abc",
        (MessageEntity(TYPE.ITALIC, 0, 1), MessageEntity(TYPE.BOLD, 2, 1)),
    )
    _check_fix_formatted_text(
        b"@tests @tests",
        (MessageEntity(TYPE.ITALIC, 0, 13),),
        b"@tests @tests",
        (
            MessageEntity(TYPE.MENTION, 0, 6),
            MessageEntity(TYPE.ITALIC, 0, 6),
            MessageEntity(TYPE.ITALIC, 6, 1),
            MessageEntity(TYPE.MENTION, 7, 6),
            MessageEntity(TYPE.ITALIC, 7, 6),
        ),
    )

    # __a~b~__
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.STRIKETHROUGH, 1, 1)),
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.STRIKETHROUGH, 0, 2), MessageEntity(TYPE.UNDERLINE, 1, 1)),
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
        ),
        b"ab",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 1, 1),
        ),
    )

    # __||a||b__
    _check_fix_formatted_text(
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
    )
    _check_fix_formatted_text(
        b"ab",
        (
            MessageEntity(TYPE.UNDERLINE, 0, 1),
            MessageEntity(TYPE.UNDERLINE, 1, 1),
            MessageEntity(TYPE.SPOILER, 0, 1),
        ),
        b"ab",
        (MessageEntity(TYPE.UNDERLINE, 0, 2), MessageEntity(TYPE.SPOILER, 0, 1)),
    )

    # _*a*_\r_*b*_
    _check_fix_formatted_text(
        b"a\rb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
        b"ab",
        (MessageEntity(TYPE.BOLD, 0, 2), MessageEntity(TYPE.ITALIC, 0, 2)),
    )
    _check_fix_formatted_text(
        b"a\nb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
        b"a\nb",
        (
            MessageEntity(TYPE.BOLD, 0, 1),
            MessageEntity(TYPE.ITALIC, 0, 1),
            MessageEntity(TYPE.BOLD, 2, 1),
            MessageEntity(TYPE.ITALIC, 2, 1),
        ),
    )

    # ||`a`||
    _check_fix_formatted_text(
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1), MessageEntity(TYPE.SPOILER, 0, 1)),
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1),),
    )
    _check_fix_formatted_text(
        b"a",
        (MessageEntity(TYPE.SPOILER, 0, 1), MessageEntity(TYPE.PRE, 0, 1)),
        b"a",
        (MessageEntity(TYPE.PRE, 0, 1),),
    )

    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3), MessageEntity(TYPE.STRIKETHROUGH, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 0, 3)),
        b"abc",
        (
            MessageEntity(TYPE.STRIKETHROUGH, 0, 1),
            MessageEntity(TYPE.PRE, 1, 1),
            MessageEntity(TYPE.STRIKETHROUGH, 2, 1),
        ),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 1, 2)),
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 2, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 1, 1), MessageEntity(TYPE.STRIKETHROUGH, 0, 2)),
        b"abc",
        (MessageEntity(TYPE.STRIKETHROUGH, 0, 1), MessageEntity(TYPE.PRE, 1, 1)),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.PRE, 0, 3), MessageEntity(TYPE.BLOCK_QUOTE, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 1, 1),),
    )
    _check_fix_formatted_text(
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3), MessageEntity(TYPE.PRE, 1, 1)),
        b"abc",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3), MessageEntity(TYPE.PRE, 1, 1)),
    )

    _check_fix_formatted_text(
        b"example.com", (), b"example.com", (MessageEntity(TYPE.URL, 0, 11),)
    )
    _check_fix_formatted_text(
        b"example.com",
        (MessageEntity(TYPE.PRE, 0, 3),),
        b"example.com",
        (MessageEntity(TYPE.PRE, 0, 3),),
    )
    _check_fix_formatted_text(
        b"example.com",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3),),
        b"example.com",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 3),),
    )
    _check_fix_formatted_text(
        b"example.com",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 11),),
        b"example.com",
        (MessageEntity(TYPE.BLOCK_QUOTE, 0, 11), MessageEntity(TYPE.URL, 0, 11)),
    )
    _check_fix_formatted_text(
        b"example.com",
        (MessageEntity(TYPE.ITALIC, 0, 11),),
        b"example.com",
        (MessageEntity(TYPE.URL, 0, 11), MessageEntity(TYPE.ITALIC, 0, 11)),
    )
    _check_fix_formatted_text(
        b"example.com",
        (MessageEntity(TYPE.ITALIC, 0, 3),),
        b"example.com",
        (MessageEntity(TYPE.URL, 0, 11), MessageEntity(TYPE.ITALIC, 0, 3)),
    )
    _check_fix_formatted_text(
        b"example.com a",
        (MessageEntity(TYPE.ITALIC, 0, 13),),
        b"example.com a",
        (
            MessageEntity(TYPE.URL, 0, 11),
            MessageEntity(TYPE.ITALIC, 0, 11),
            MessageEntity(TYPE.ITALIC, 11, 2),
        ),
    )
    _check_fix_formatted_text(
        b"a example.com",
        (MessageEntity(TYPE.ITALIC, 0, 13),),
        b"a example.com",
        (
            MessageEntity(TYPE.ITALIC, 0, 2),
            MessageEntity(TYPE.URL, 2, 11),
            MessageEntity(TYPE.ITALIC, 2, 11),
        ),
    )

    _check_fix_formatted_text_on_random_texts()

    _check_fix_formatted_text(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f a",
        (),
        b"\xe2\x80\x8c\xe2\x80\x8f  \xe2\x80\x8c\xe2\x80\x8c\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8c\xe2\x80\x8e \xe2\x80\x8f a",
        (),
    )
    _check_fix_formatted_text_fails(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f",
        (),
        False,
        False,
        False,
        True,
    )
    _check_fix_formatted_text(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c"
        b" \xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f",
        (),
        b"",
        (),
    )
