from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.cstring import Span
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    MessageEntity,
    find_bank_card_numbers,
    find_bot_commands,
    find_cashtags,
    find_entities,
    find_hashtags,
    find_mentions,
    find_tg_urls,
    find_ton_addresses,
    find_urls,
    is_email_address,
)


def _matches(find: Callable[[bytes], tuple[Span, ...]], text: bytes) -> list[bytes]:
    return [text[begin:end] for begin, end in find(text)]


def test_find_mentions_gives_byte_spans() -> None:
    text = "\U0001f600 @username".encode()
    assert find_mentions(text) == ((5, 14),)


def test_find_mentions_keeps_a_short_username_only_from_the_list() -> None:
    assert _matches(find_mentions, b"@gif @GIF @abc @abcd") == [
        b"@gif",
        b"@GIF",
        b"@abcd",
    ]


def test_find_mentions_skips_a_mention_in_a_word() -> None:
    assert _matches(find_mentions, "x@user \U00000430@user".encode()) == []


def test_find_bot_commands_takes_a_username() -> None:
    assert _matches(find_bot_commands, b"/start@my_bot /help") == [
        b"/start@my_bot",
        b"/help",
    ]


@pytest.mark.parametrize("text", [b"</start", b"/start>", b"a/start", b"/start/"])
def test_find_bot_commands_skips_a_command_next_to_a_bracket_or_word(
    text: bytes,
) -> None:
    assert find_bot_commands(text) == ()


def test_find_hashtags_needs_a_letter() -> None:
    assert _matches(find_hashtags, b"#123 #12a #a_1") == [b"#12a", b"#a_1"]


def test_find_hashtags_keeps_the_first_256_hashtag_letters() -> None:
    text = b"#" + b"a" * 300
    assert _matches(find_hashtags, text) == [text[:257]]


def test_find_cashtags_takes_capital_letters_or_1inch() -> None:
    assert _matches(find_cashtags, b"$USD $1INCH $usd $ABCDEFGHI") == [
        b"$USD",
        b"$1INCH",
    ]


@pytest.mark.parametrize(
    "number",
    [
        b"4000000000006",  # Visa, 13 digits
        b"2221000000000009",  # Mastercard of the 2 series
        b"340000000000009",  # American Express, 15 digits
        b"6200000000000005",  # UnionPay, 16 digits
        b"6200000000000000000",  # UnionPay, 19 digits
        b"2200000000000004",  # MIR, 16 digits
        b"9000000000001",  # no brand, so no length rule
        b"4000 0000 0000 6",
    ],
)
def test_find_bank_card_numbers_keeps_a_valid_number(number: bytes) -> None:
    assert _matches(find_bank_card_numbers, number) == [number]


@pytest.mark.parametrize(
    "number",
    [
        b"40000000000002",  # Visa, 14 digits
        b"272000000000001",  # Mastercard, 15 digits
        b"3700000000000007",  # American Express, 16 digits
        b"620000000000000",  # UnionPay, 15 digits
        b"22040000000000006",  # MIR, 17 digits
        b"4000000000007",  # a wrong Luhn check digit
        b"x4000000000006",  # after a letter
    ],
)
def test_find_bank_card_numbers_refuses_an_invalid_number(number: bytes) -> None:
    assert find_bank_card_numbers(number) == ()


def test_find_ton_addresses_checks_each_run_of_base64_characters() -> None:
    valid = b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N"
    assert _matches(find_ton_addresses, b"to " + valid + b" or " + valid[1:]) == [valid]


def test_find_tg_urls_starts_a_tonsite_link_at_the_last_three_letters() -> None:
    # Upstream moves the start back 3 bytes from the colon for "tonsite" as for "ton".
    assert _matches(find_tg_urls, b"tonsite://a") == [b"ite://a"]


def test_find_urls_leaves_mailto_out_of_an_email_address() -> None:
    assert find_urls(b"mailto:a@b.com") == (((7, 14), True),)


def test_find_urls_keeps_a_link_with_a_protocol_and_any_top_level_domain() -> None:
    assert find_urls(b"https://t.qqq qqq.qqq") == (((0, 13), False),)


def test_find_urls_refuses_a_lookalike_of_telegram_org() -> None:
    assert find_urls(b"teiegram.org") == ()


@pytest.mark.parametrize(
    ("text", "expected"),
    [
        (b"a.b+c@d.ef", True),
        (b"a@b", False),
        (b"a@b.c", False),
        (b"a@-b.cd", False),
        (b"\xc3\xa9@b.cd", False),
    ],
)
def test_is_email_address(text: bytes, expected: bool) -> None:
    assert is_email_address(text) == expected


def test_find_entities_gives_utf16_bounds_in_order() -> None:
    text = "\U0001f600 /start @user #tag $USD a@b.com".encode()
    assert find_entities(text, skip_bot_commands=False) == (
        MessageEntity(TYPE.BOT_COMMAND, 3, 6),
        MessageEntity(TYPE.MENTION, 10, 5),
        MessageEntity(TYPE.HASHTAG, 16, 4),
        MessageEntity(TYPE.CASHTAG, 21, 4),
        MessageEntity(TYPE.EMAIL_ADDRESS, 26, 7),
    )


def test_find_entities_skips_bot_commands_when_asked() -> None:
    assert find_entities(b"/start", skip_bot_commands=True) == ()


def test_find_entities_drops_an_entity_within_one_found_earlier() -> None:
    text = b"telegram.org/#tag"
    assert find_entities(text, skip_bot_commands=False) == (
        MessageEntity(TYPE.URL, 0, 17),
    )
