# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's search of a text for the entities it adds on its own.

TDLib runs the search only on text it has checked, so every function here takes valid
UTF-8. Each kind of entity is found as the byte offsets `(begin, end)` of its matches,
and `find_entities` gathers them all as entities, in UTF-16 code units.
"""

from collections.abc import Iterable, Sequence
from dataclasses import replace

from tdlib_oracle.runtime.cstring import Span
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    MessageEntity,
    _remove_intersecting_entities,
    _sort_entities,
)
from tdlib_oracle.tdlib.ton_wallet_manager import check_ton_address
from tdlib_oracle.tdutils.base64 import is_base64any_character
from tdlib_oracle.tdutils.misc import is_alpha, is_digit
from tdlib_oracle.tdutils.unicode import CATEGORY, get_unicode_simple_category
from tdlib_oracle.tdutils.utf8 import (
    next_utf8_unsafe,
    prev_utf8_unsafe,
    utf8_length,
    utf8_substr,
    utf8_to_lower,
)

# Ported from td/telegram/MessageEntity.cpp, bad_path_end_chars in match_tg_urls(),
# match_urls(), and fix_url(): characters a link does not end with.
_BAD_PATH_END_CHARS = b".:;,('?!`"


# Ported from td/telegram/MessageEntity.cpp, is_word_character().
def _is_word_character(code: int) -> bool:
    match get_unicode_simple_category(code):
        case CATEGORY.LETTER | CATEGORY.DECIMAL_NUMBER | CATEGORY.NUMBER:
            return True
        case _:
            return code == 0x5F  # '_'


# Ported from td/telegram/MessageEntity.cpp, is_alpha_digit().
def _is_alpha_digit(code: int) -> bool:
    return 0x30 <= code <= 0x39 or 0x61 <= code <= 0x7A or 0x41 <= code <= 0x5A


# Ported from td/telegram/MessageEntity.cpp, is_alpha_digit_or_underscore().
def _is_alpha_digit_or_underscore(code: int) -> bool:
    return _is_alpha_digit(code) or code == 0x5F  # '_'


# Ported from td/telegram/MessageEntity.cpp, is_alpha_digit_or_underscore_or_minus().
def _is_alpha_digit_or_underscore_or_minus(code: int) -> bool:
    return _is_alpha_digit_or_underscore(code) or code == 0x2D  # '-'


# Ported from td/telegram/MessageEntity.cpp, match_mentions().
def _match_mentions(text: bytes) -> list[Span]:
    result = []
    end = len(text)
    ptr = 0
    while True:
        ptr = text.find(b"@", ptr)
        if ptr == -1:
            break

        if ptr != 0:
            _, prev = next_utf8_unsafe(text, prev_utf8_unsafe(text, ptr))
            if _is_word_character(prev):
                ptr += 1
                continue
        ptr += 1
        mention_begin = ptr
        while ptr != end and _is_alpha_digit_or_underscore(text[ptr]):
            ptr += 1
        mention_end = ptr
        mention_size = mention_end - mention_begin
        if mention_size < 2 or mention_size > 32:
            continue
        next_code = 0
        if ptr != end:
            _, next_code = next_utf8_unsafe(text, ptr)
        if _is_word_character(next_code):
            continue
        result.append((mention_begin - 1, mention_end))
    return result


# Ported from td/telegram/MessageEntity.cpp, match_bot_commands(), the characters
# besides word characters that it finds no bot command next to: '/', '<', and '>'.
_COMMAND_NEIGHBORS = (0x2F, 0x3C, 0x3E)


# Ported from td/telegram/MessageEntity.cpp, match_bot_commands().
def _match_bot_commands(text: bytes) -> list[Span]:
    result = []
    end = len(text)
    ptr = 0
    while True:
        ptr = text.find(b"/", ptr)
        if ptr == -1:
            break

        if ptr != 0:
            _, prev = next_utf8_unsafe(text, prev_utf8_unsafe(text, ptr))
            if _is_word_character(prev) or prev in _COMMAND_NEIGHBORS:
                ptr += 1
                continue

        ptr += 1
        command_begin = ptr
        while ptr != end and _is_alpha_digit_or_underscore(text[ptr]):
            ptr += 1
        command_end = ptr
        command_size = command_end - command_begin
        if command_size < 1 or command_size > 64:
            continue

        if ptr != end and text[ptr] == 0x40:  # '@'
            ptr += 1
            mention_begin = ptr
            while ptr != end and _is_alpha_digit_or_underscore(text[ptr]):
                ptr += 1
            mention_end = ptr
            mention_size = mention_end - mention_begin
            if mention_size < 3 or mention_size > 32:
                continue
            command_end = ptr

        next_code = 0
        if ptr != end:
            _, next_code = next_utf8_unsafe(text, ptr)
        if _is_word_character(next_code) or next_code in _COMMAND_NEIGHBORS:
            continue
        result.append((command_begin - 1, command_end))
    return result


# Ported from td/telegram/MessageEntity.cpp, is_hashtag_letter().
def _is_hashtag_letter(c: int) -> tuple[bool, int]:
    """Return whether the code point `c` may stand in a hashtag, and its category."""
    category = get_unicode_simple_category(c)
    if c in (0x5F, 0x200C, 0xB7) or 0xD80 <= c <= 0xDFF:
        return True, category
    return category in (CATEGORY.DECIMAL_NUMBER, CATEGORY.LETTER), category


# Ported from td/telegram/MessageEntity.cpp, match_hashtags().
def _match_hashtags(text: bytes) -> list[Span]:  # noqa: PLR0912  # mirrors upstream
    result = []
    end = len(text)
    ptr = 0
    while True:
        ptr = text.find(b"#", ptr)
        if ptr == -1:
            break

        if ptr != 0:
            _, prev = next_utf8_unsafe(text, prev_utf8_unsafe(text, ptr))
            if _is_hashtag_letter(prev)[0]:
                ptr += 1
                continue
        ptr += 1
        hashtag_begin = ptr
        hashtag_size = 0
        hashtag_end = None
        was_letter = False
        while ptr != end:
            next_ptr, code = next_utf8_unsafe(text, ptr)
            is_letter, category = _is_hashtag_letter(code)
            if not is_letter:
                break
            ptr = next_ptr

            if hashtag_size == 255:
                hashtag_end = ptr
            if hashtag_size != 256:
                was_letter |= category == CATEGORY.LETTER
                hashtag_size += 1
        if hashtag_end is None:
            hashtag_end = ptr
        if hashtag_size < 1:
            continue
        if hashtag_end == ptr and ptr != end and text[ptr] == 0x40:  # '@'
            username_end = ptr + 1
            while (
                username_end != end
                and username_end - ptr < 33
                and _is_alpha_digit_or_underscore(text[username_end])
            ):
                username_end += 1
            length = username_end - ptr - 1
            if length >= 3:
                ptr = username_end
                hashtag_end = username_end
        if ptr != end and text[ptr] == 0x23:  # '#'
            continue
        if not was_letter:
            continue
        result.append((hashtag_begin - 1, hashtag_end))
    return result


# Ported from td/telegram/MessageEntity.cpp, match_cashtags().
def _match_cashtags(text: bytes) -> list[Span]:  # noqa: PLR0912  # mirrors upstream
    result = []
    end = len(text)
    ptr = 0
    while True:
        ptr = text.find(b"$", ptr)
        if ptr == -1:
            break

        if ptr != 0:
            _, prev = next_utf8_unsafe(text, prev_utf8_unsafe(text, ptr))
            if _is_hashtag_letter(prev)[0] or prev == 0x24:  # '$'
                ptr += 1
                continue

        ptr += 1
        cashtag_begin = ptr
        if end - ptr >= 5 and text[ptr : ptr + 5] == b"1INCH":
            ptr += 5
        else:
            while ptr != end and 0x41 <= text[ptr] <= 0x5A:  # 'A' to 'Z'
                ptr += 1
        cashtag_end = ptr
        cashtag_size = cashtag_end - cashtag_begin
        if cashtag_size < 1 or cashtag_size > 8:
            continue
        if ptr != end and text[ptr] == 0x40:  # '@'
            username_end = ptr + 1
            while username_end != end and _is_alpha_digit_or_underscore(
                text[username_end]
            ):
                username_end += 1
            length = username_end - ptr - 1
            if 3 <= length <= 32:
                cashtag_end = username_end
                ptr = username_end
        if cashtag_end != end:
            _, code = next_utf8_unsafe(text, ptr)
            if _is_hashtag_letter(code)[0] or code == 0x24:  # '$'
                continue

        result.append((cashtag_begin - 1, cashtag_end))
    return result


# Ported from td/telegram/MessageEntity.cpp, match_bank_card_numbers().
def _match_bank_card_numbers(text: bytes) -> list[Span]:  # noqa: PLR0912  # mirrors upstream
    result = []
    end = len(text)
    ptr = 0
    while True:
        while ptr != end and not is_digit(text[ptr]):
            ptr += 1
        if ptr == end:
            break
        if ptr != 0:
            _, prev = next_utf8_unsafe(text, prev_utf8_unsafe(text, ptr))
            if (
                prev in (0x2E, 0x2C, 0x2B, 0x2D, 0x5F)  # '.', ',', '+', '-', '_'
                or get_unicode_simple_category(prev) == CATEGORY.LETTER
            ):
                while ptr != end and (is_digit(text[ptr]) or text[ptr] in b" -"):
                    ptr += 1
                continue

        card_number_begin = ptr
        digit_count = 0
        while ptr != end and (is_digit(text[ptr]) or text[ptr] in b" -"):
            if (
                text[ptr] == 0x20  # ' '
                and 16 <= digit_count <= 19
                and digit_count == ptr - card_number_begin
            ):
                # continuous card number
                break
            digit_count += is_digit(text[ptr])
            ptr += 1
        if digit_count < 13 or digit_count > 19:
            continue

        card_number_end = ptr
        while not is_digit(text[card_number_end - 1]):
            card_number_end -= 1
        card_number_size = card_number_end - card_number_begin
        if card_number_size > 2 * digit_count - 1:
            continue
        if card_number_end != end:
            _, next_code = next_utf8_unsafe(text, card_number_end)
            if (
                next_code in (0x2D, 0x5F)  # '-', '_'
                or get_unicode_simple_category(next_code) == CATEGORY.LETTER
            ):
                continue

        result.append((card_number_begin, card_number_end))
    return result


# Ported from td/telegram/MessageEntity.cpp, match_ton_addresses().
def _match_ton_addresses(text: bytes) -> list[Span]:
    result = []
    end = len(text)
    ptr = 0
    while True:
        while ptr != end and not is_base64any_character(text[ptr]):
            ptr += 1
        if ptr == end:
            break
        ton_address_begin = ptr
        while ptr != end and is_base64any_character(text[ptr]):
            ptr += 1

        if check_ton_address(text[ton_address_begin:ptr]) is not None:
            continue
        result.append((ton_address_begin, ptr))
    return result


# Ported from td/telegram/MessageEntity.cpp, is_url_unicode_symbol().
def _is_url_unicode_symbol(c: int) -> bool:
    if 0x2000 <= c <= 0x206F:  # General Punctuation
        # Zero Width Non-Joiner/Joiner and various dashes
        return c in (0x200C, 0x200D) or 0x2010 <= c <= 0x2015
    return get_unicode_simple_category(c) != CATEGORY.SEPARATOR


# Ported from td/telegram/MessageEntity.cpp, is_url_path_symbol().
def _is_url_path_symbol(c: int) -> bool:
    if c in (0x0A, 0x3C, 0x3E, 0x22, 0xAB, 0xBB):  # '\n', '<', '>', '"', '«', '»'
        return False
    return _is_url_unicode_symbol(c)


# Ported from td/telegram/MessageEntity.cpp, match_tg_urls().
def _match_tg_urls(text: bytes) -> list[Span]:  # noqa: PLR0912  # mirrors upstream
    result = []
    end = len(text)
    ptr = 0
    while end - ptr > 5:
        ptr = text.find(b":", ptr)
        if ptr == -1:
            break

        url_begin = None
        if end - ptr >= 3 and text[ptr + 1 : ptr + 3] == b"//":
            if ptr >= 2 and text[ptr - 2 : ptr].lower() == b"tg":
                url_begin = ptr - 2
            elif ptr >= 3 and text[ptr - 3 : ptr].lower() == b"ton":
                url_begin = ptr - 3
            elif ptr >= 7 and text[ptr - 7 : ptr].lower() == b"tonsite":
                url_begin = ptr - 3
        if url_begin is None:
            ptr += 1
            continue

        ptr += 3
        domain_begin = ptr
        while (
            ptr != end
            and ptr - domain_begin != 253
            and _is_alpha_digit_or_underscore_or_minus(text[ptr])
        ):
            ptr += 1
        if ptr == domain_begin:
            continue

        if ptr != end and text[ptr] in b"/?#":
            path_end_ptr = ptr + 1
            while path_end_ptr != end:
                next_ptr, code = next_utf8_unsafe(text, path_end_ptr)
                if not _is_url_path_symbol(code):
                    break
                path_end_ptr = next_ptr
            while (
                path_end_ptr > ptr + 1 and text[path_end_ptr - 1] in _BAD_PATH_END_CHARS
            ):
                path_end_ptr -= 1
            if text[ptr] == 0x2F or path_end_ptr > ptr + 1:  # '/'
                ptr = path_end_ptr

        result.append((url_begin, ptr))
    return result


# Ported from td/telegram/MessageEntity.cpp, is_protocol_symbol in match_urls().
def _is_protocol_symbol(c: int) -> bool:
    if c < 0x80:
        # do not allow dots in the protocol
        return _is_alpha_digit(c) or c in (0x2B, 0x2D)  # '+', '-'
    # add unicode letters and digits to later discard protocol as invalid
    return get_unicode_simple_category(c) != CATEGORY.SEPARATOR


# Ported from td/telegram/MessageEntity.cpp, is_user_data_symbol in match_urls(), the
# characters it refuses, '«' and '»' among them.
_NOT_USER_DATA_SYMBOLS = frozenset(b"\n/[]{}()'`<>\"@\xab\xbb")


# Ported from td/telegram/MessageEntity.cpp, is_user_data_symbol in match_urls().
def _is_user_data_symbol(c: int) -> bool:
    if c in _NOT_USER_DATA_SYMBOLS:
        return False
    return _is_url_unicode_symbol(c)


# Ported from td/telegram/MessageEntity.cpp, is_domain_symbol in match_urls().
def _is_domain_symbol(c: int) -> bool:
    if c < 0xC0:
        return c == 0x2E or _is_alpha_digit_or_underscore_or_minus(c) or c == 0x7E
    return _is_url_unicode_symbol(c)


# Ported from td/telegram/MessageEntity.cpp, match_urls().
def _match_urls(text: bytes) -> list[Span]:  # noqa: PLR0912, PLR0915  # mirrors upstream
    """Return the spans that may be links or email addresses, for checks to follow.

    The C++ moves the start of the text it searches past each candidate; `begin` holds
    where that text starts now.
    """
    result = []
    begin = 0
    end = len(text)
    while True:
        dot = text.find(b".", begin)
        if dot == -1 or dot + 1 == end:
            break
        if text[dot + 1] == 0x20:  # ' '
            # fast path
            begin = dot + 2
            continue

        domain_begin_ptr = dot
        while domain_begin_ptr != begin:
            domain_begin_ptr = prev_utf8_unsafe(text, domain_begin_ptr)
            next_ptr, code = next_utf8_unsafe(text, domain_begin_ptr)
            if not _is_domain_symbol(code):
                domain_begin_ptr = next_ptr
                break

        last_at_ptr = None
        domain_end_ptr = dot
        while domain_end_ptr != end:
            next_ptr, code = next_utf8_unsafe(text, domain_end_ptr)
            if code == 0x40:  # '@'
                last_at_ptr = domain_end_ptr
            elif not _is_domain_symbol(code):
                break
            domain_end_ptr = next_ptr

        if last_at_ptr is not None:
            while domain_begin_ptr != begin:
                domain_begin_ptr = prev_utf8_unsafe(text, domain_begin_ptr)
                next_ptr, code = next_utf8_unsafe(text, domain_begin_ptr)
                if not _is_user_data_symbol(code):
                    domain_begin_ptr = next_ptr
                    break

        url_end_ptr = domain_end_ptr
        if url_end_ptr != end and text[url_end_ptr] == 0x3A:  # ':'
            port_end_ptr = url_end_ptr + 1

            while port_end_ptr != end and is_digit(text[port_end_ptr]):
                port_end_ptr += 1

            port_begin_ptr = url_end_ptr + 1
            while (
                port_begin_ptr != port_end_ptr and text[port_begin_ptr] == 0x30
            ):  # '0'
                port_begin_ptr += 1
            if (
                port_begin_ptr != port_end_ptr
                and port_end_ptr - port_begin_ptr <= 5
                and int(text[port_begin_ptr:port_end_ptr]) <= 65535
            ):
                url_end_ptr = port_end_ptr

        if url_end_ptr != end and text[url_end_ptr] in b"/?#":
            path_end_ptr = url_end_ptr + 1
            while path_end_ptr != end:
                next_ptr, code = next_utf8_unsafe(text, path_end_ptr)
                if not _is_url_path_symbol(code):
                    break
                path_end_ptr = next_ptr
            while (
                path_end_ptr > url_end_ptr + 1
                and text[path_end_ptr - 1] in _BAD_PATH_END_CHARS
            ):
                path_end_ptr -= 1
            if text[url_end_ptr] == 0x2F or path_end_ptr > url_end_ptr + 1:  # '/'
                url_end_ptr = path_end_ptr
        while url_end_ptr > dot + 1 and text[url_end_ptr - 1] == 0x2E:  # '.'
            url_end_ptr -= 1

        is_bad = False
        url_begin_ptr = domain_begin_ptr
        if url_begin_ptr != begin and text[url_begin_ptr - 1] == 0x40:  # '@'
            if last_at_ptr is not None:
                is_bad = True
            user_data_begin_ptr = url_begin_ptr - 1
            while user_data_begin_ptr != begin:
                user_data_begin_ptr = prev_utf8_unsafe(text, user_data_begin_ptr)
                next_ptr, code = next_utf8_unsafe(text, user_data_begin_ptr)
                if not _is_user_data_symbol(code):
                    user_data_begin_ptr = next_ptr
                    break
            if user_data_begin_ptr == url_begin_ptr - 1:
                is_bad = True
            url_begin_ptr = user_data_begin_ptr

        if url_begin_ptr != begin:
            prefix = text[begin:url_begin_ptr]
            if len(prefix) >= 6 and prefix.endswith(b"://"):
                protocol_begin_ptr = url_begin_ptr - 3
                while protocol_begin_ptr != begin:
                    protocol_begin_ptr = prev_utf8_unsafe(text, protocol_begin_ptr)
                    next_ptr, code = next_utf8_unsafe(text, protocol_begin_ptr)
                    if not _is_protocol_symbol(code):
                        protocol_begin_ptr = next_ptr
                        break
                protocol = text[protocol_begin_ptr : url_begin_ptr - 3].lower()
                if protocol.endswith(b"http") and protocol != b"shttp":
                    url_begin_ptr = url_begin_ptr - 7
                elif protocol.endswith(b"https"):
                    url_begin_ptr = url_begin_ptr - 8
                elif protocol.endswith(b"ftp") and protocol not in (b"tftp", b"sftp"):
                    url_begin_ptr = url_begin_ptr - 6
                elif protocol.endswith(b"tonsite"):
                    url_begin_ptr = url_begin_ptr - 10
                else:
                    is_bad = True
            else:
                prefix_back = prev_utf8_unsafe(text, url_begin_ptr)
                _, code = next_utf8_unsafe(text, prefix_back)
                # A link follows no word character, '/', '#', or '@'.
                if _is_word_character(code) or code in (0x2F, 0x23, 0x40):
                    is_bad = True

        if not is_bad:
            if url_end_ptr > dot + 1:
                result.append((url_begin_ptr, url_end_ptr))
            while url_end_ptr != end and text[url_end_ptr] == 0x2E:  # '.'
                url_end_ptr += 1
        else:
            while text[url_end_ptr - 1] != 0x2E:  # '.'
                url_end_ptr -= 1

        if url_end_ptr <= dot:
            url_end_ptr = dot + 1
        begin = url_end_ptr

    return result


# Ported from td/telegram/MessageEntity.cpp, is_valid_bank_card().
def _is_valid_bank_card(text: bytes) -> bool:
    """Return whether the digits of `text` form a bank card number TDLib accepts.

    `text` holds 13 to 19 digits, as `_match_bank_card_numbers` finds them. The Luhn
    check comes first, then the length that the card brand of the first digits takes.
    """
    digits = [c - 0x30 for c in text if is_digit(c)]
    digit_count = len(digits)

    # Luhn algorithm
    total = 0
    for i in range(digit_count, 0, -1):
        digit = digits[i - 1]
        if (digit_count - i) % 2 == 0:
            total += digit
        else:
            total += 2 * digit if digit < 5 else 2 * digit - 9
    if total % 10 != 0:
        return False

    prefix1 = digits[0]
    prefix2 = prefix1 * 10 + digits[1]
    prefix3 = prefix2 * 10 + digits[2]
    prefix4 = prefix3 * 10 + digits[3]
    if prefix1 == 4:
        # Visa
        return digit_count in (13, 16, 18, 19)
    if 51 <= prefix2 <= 55 or 2221 <= prefix4 <= 2720:
        # mastercard
        return digit_count == 16
    if prefix2 in (34, 37):
        # American Express
        return digit_count == 15
    if prefix2 in (62, 81):
        # UnionPay
        return digit_count >= 16
    if 2200 <= prefix4 <= 2204:
        # MIR
        return digit_count == 16
    return True  # skip length check


# Ported from td/telegram/MessageEntity.cpp, is_email_address().
def is_email_address(text: bytes) -> bool:  # noqa: PLR0911, PLR0912  # mirrors upstream
    """Return whether `text` is an email address, as TDLib reads one.

    Before the `@`, up to 11 parts split by `.` or `+`: letters, digits, `_`, and `-`,
    at most 26 a part and 1 to 35 in the last. After it, 2 to 7 labels split by `.`:
    letters, digits, `_`, and `-`, under 31 a label, starting and ending with a letter
    or digit, and last a label of 2 to 8 letters.
    """
    userdata, _, domain = text.partition(b"@")
    if not domain:
        return False

    prev = 0
    userdata_part_count = 0
    for i, c in enumerate(userdata):
        if c in b".+":
            if i - prev >= 27:
                return False
            userdata_part_count += 1
            prev = i + 1
        elif not _is_alpha_digit_or_underscore_or_minus(c):
            return False
    userdata_part_count += 1
    if userdata_part_count >= 12:
        return False
    last_part_length = len(userdata) - prev
    if last_part_length == 0 or last_part_length >= 36:
        return False

    domain_parts = domain.split(b".")
    if len(domain_parts) <= 1 or len(domain_parts) > 7:
        return False
    if len(domain_parts[-1]) <= 1 or len(domain_parts[-1]) >= 9:
        return False
    if not all(is_alpha(c) for c in domain_parts[-1]):
        return False
    for part in domain_parts[:-1]:
        if not part or len(part) >= 31:
            return False
        if not all(_is_alpha_digit_or_underscore_or_minus(c) for c in part):
            return False
        if not _is_alpha_digit(part[0]):
            return False
        if not _is_alpha_digit(part[-1]):
            return False

    return True


# Ported from td/telegram/MessageEntity.cpp, tlds in is_common_tld(). Kept in rows of
# one string, since ruff format would give each TLD a line of its own.
_COMMON_TLDS = frozenset(
    """
    aaa aarp abb abbott abbvie abc able abogado abudhabi ac academy accenture accountant
    accountants aco actor ad ads adult ae aeg aero aetna af afl africa ag agakhan agency
    ai aig airbus airforce airtel akdn al alibaba alipay allfinanz allstate ally alsace
    alstom am amazon americanexpress americanfamily amex amfam amica amsterdam analytics
    android anquan anz ao aol apartments app apple aq aquarelle ar arab aramco archi
    army arpa art arte as asda asia associates at athleta attorney au auction audi
    audible audio auspost author auto autos aw aws ax axa az azure ba baby baidu banamex
    band bank bar barcelona barclaycard barclays barefoot bargains baseball basketball
    bauhaus bayern bb bbc bbt bbva bcg bcn bd be beats beauty beer bentley berlin best
    bestbuy bet bf bg bh bharti bi bible bid bike bing bingo bio biz bj black
    blackfriday blockbuster blog bloomberg blue bm bms bmw bn bnpparibas bo boats
    boehringer bofa bom bond boo book booking bosch bostik boston bot boutique box br
    bradesco bridgestone broadway broker brother brussels bs bt build builders business
    buy buzz bv bw by bz bzh ca cab cafe cal call calvinklein cam camera camp canon
    capetown capital capitalone car caravan cards care career careers cars casa case
    cash casino cat catering catholic cba cbn cbre cc cd center ceo cern cf cfa cfd cg
    ch chanel channel charity chase chat cheap chintai christmas chrome church ci
    cipriani circle cisco citadel citi citic city ck cl claims cleaning click clinic
    clinique clothing cloud club clubmed cm cn co coach codes coffee college cologne com
    commbank community company compare computer comsec condos construction consulting
    contact contractors cooking cool coop corsica country coupon coupons courses cpa cr
    credit creditcard creditunion cricket crown crs cruise cruises cu cuisinella cv cw
    cx cy cymru cyou cz dabur dad dance data date dating datsun day dclk dds de deal
    dealer deals degree delivery dell deloitte delta democrat dental dentist desi design
    dev dhl diamonds diet digital direct directory discount discover dish diy dj dk dm
    dnp do docs doctor dog domains dot download drive dtv dubai dunlop dupont durban
    dvag dvr dz earth eat ec eco edeka edu education ee eg email emerck energy engineer
    engineering enterprises epson equipment er ericsson erni es esq estate et eu
    eurovision eus events exchange expert exposed express extraspace fage fail fairwinds
    faith family fan fans farm farmers fashion fast fedex feedback ferrari ferrero fi
    fidelity fido film final finance financial fire firestone firmdale fish fishing fit
    fitness fj fk flickr flights flir florist flowers fly fm fo foo food football ford
    forex forsale forum foundation fox fr free fresenius frl frogans frontier ftr
    fujitsu fun fund furniture futbol fyi ga gal gallery gallo gallup game games gap
    garden gay gb gbiz gd gdn ge gea gent genting george gf gg ggee gh gi gift gifts
    gives giving gl glass gle global globo gm gmail gmbh gmo gmx gn godaddy gold
    goldpoint golf goo goodyear goog google gop got gov gp gq gr grainger graphics
    gratis green gripe grocery group gs gt gu gucci guge guide guitars guru gw gy hair
    hamburg hangout haus hbo hdfc hdfcbank health healthcare help helsinki here hermes
    hiphop hisamitsu hitachi hiv hk hkt hm hn hockey holdings holiday homedepot
    homegoods homes homesense honda horse hospital host hosting hot hotels hotmail house
    how hr hsbc ht hu hughes hyatt hyundai ibm icbc ice icu id ie ieee ifm ikano il im
    imamat imdb immo immobilien in inc industries infiniti info ing ink institute
    insurance insure int international intuit investments io ipiranga iq ir irish is
    ismaili ist istanbul it itau itv jaguar java jcb je jeep jetzt jewelry jio jll jm
    jmp jnj jo jobs joburg jot joy jp jpmorgan jprs juegos juniper kaufen kddi ke
    kerryhotels kerrylogistics kerryproperties kfh kg kh ki kia kids kim kindle kitchen
    kiwi km kn koeln komatsu kosher kp kpmg kpn kr krd kred kuokgroup kw ky kyoto kz la
    lacaixa lamborghini lamer lancaster land landrover lanxess lasalle lat latino
    latrobe law lawyer lb lc lds lease leclerc lefrak legal lego lexus lgbt li lidl life
    lifeinsurance lifestyle lighting like lilly limited limo lincoln link lipsy live
    living lk llc llp loan loans locker locus lol london lotte lotto love lpl
    lplfinancial lr ls lt ltd ltda lu lundbeck luxe luxury lv ly ma madrid maif maison
    makeup man management mango map market marketing markets marriott marshalls mattel
    mba mc mckinsey md me med media meet melbourne meme memorial men menu merckmsd mg mh
    miami microsoft mil mini mint mit mitsubishi mk ml mlb mls mm mma mn mo mobi mobile
    moda moe moi mom monash money monster mormon mortgage moscow moto motorcycles mov
    movie mp mq mr ms msd mt mtn mtr mu museum music mv mw mx my mz na nab nagoya name
    navy nba nc ne nec net netbank netflix network neustar new news next nextdirect
    nexus nf nfl ng ngo nhk ni nico nike nikon ninja nissan nissay nl no nokia norton
    now nowruz nowtv np nr nra nrw ntt nu nyc nz obi observer office okinawa olayan
    olayangroup ollo om omega one ong onion onl online ooo open oracle orange org
    organic origins osaka otsuka ott ovh pa page panasonic paris pars partners parts
    party pay pccw pe pet pf pfizer pg ph pharmacy phd philips phone photo photography
    photos physio pics pictet pictures pid pin ping pink pioneer pizza pk pl place play
    playstation plumbing plus pm pn pnc pohl poker politie porn post pr pramerica praxi
    press prime pro prod productions prof progressive promo properties property
    protection pru prudential ps pt pub pw pwc py qa qpon quebec quest racing radio re
    read realestate realtor realty recipes red redstone redumbrella rehab reise reisen
    reit reliance ren rent rentals repair report republican rest restaurant review
    reviews rexroth rich richardli ricoh ril rio rip ro rocks rodeo rogers room rs rsvp
    ru rugby ruhr run rw rwe ryukyu sa saarland safe safety sakura sale salon samsclub
    samsung sandvik sandvikcoromant sanofi sap sarl sas save saxo sb sbi sbs sc scb
    schaeffler schmidt scholarships school schule schwarz science scot sd se search seat
    secure security seek select sener services seven sew sex sexy sfr sg sh shangrila
    sharp shell shia shiksha shoes shop shopping shouji show si silk sina singles site
    sj sk ski skin sky skype sl sling sm smart smile sn sncf so soccer social softbank
    software sohu solar solutions song sony soy spa space sport spot sr srl ss st stada
    staples star statebank statefarm stc stcgroup stockholm storage store stream studio
    study style su sucks supplies supply support surf surgery suzuki sv swatch swiss sx
    sy sydney systems sz tab taipei talk taobao target tatamotors tatar tattoo tax taxi
    tc tci td tdk team tech technology tel temasek tennis teva tf tg th thd theater
    theatre tiaa tickets tienda tips tires tirol tj tjmaxx tjx tk tkmaxx tl tm tmall tn
    to today tokyo ton tools top toray toshiba total tours town toyota toys tr trade
    trading training travel travelers travelersinsurance trust trv tt tube tui tunes
    tushu tv tvs tw tz ua ubank ubs ug uk unicom university uno uol ups us uy uz va
    vacations vana vanguard vc ve vegas ventures verisign vermögensberater
    vermögensberatung versicherung vet vg vi viajes video vig viking villas vin vip
    virgin visa vision viva vivo vlaanderen vn vodka volvo vote voting voto voyage vu
    wales walmart walter wang wanggou watch watches weather weatherchannel webcam weber
    website wed wedding weibo weir wf whoswho wien wiki williamhill win windows wine
    winners wme wolterskluwer woodside work works world wow ws wtc wtf xbox xerox xihuan
    xin ελ ευ бг бел дети ею католик ком мкд мон москва онлайн орг рус рф сайт срб укр
    қаз հայ ישראל קום ابوظبي ارامكو الاردن البحرين الجزائر السعودية العليان المغرب
    امارات ایران بارت بازار بيتك بھارت تونس سودان سورية شبكة عراق عرب عمان فلسطين قطر
    كاثوليك كوم مصر مليسيا موريتانيا موقع همراه پاکستان ڀارت कॉम नेट भारत भारतम् भारोत
    संगठन বাংলা ভারত ভাৰত ਭਾਰਤ ભારત ଭାରତ இந்தியா இலங்கை சிங்கப்பூர் భారత్ ಭಾರತ ഭാരതം ලංකා คอม
    ไทย ລາວ გე みんな アマゾン クラウド グーグル コム ストア セール ファッション
    ポイント 世界 中信 中国 中國 中文网 亚马逊 企业 佛山 信息 健康 八卦 公司 公益 台湾
    台灣 商城 商店 商标 嘉里 嘉里大酒店 在线 大拿 天主教 娱乐 家電 广东 微博 慈善 我爱你
    手机 招聘 政务 政府 新加坡 新闻 时尚 書籍 机构 淡马锡 游戏 澳門 点看 移动 组织机构
    网址 网店 网站 网络 联通 谷歌 购物 通販 集团 電訊盈科 飞利浦 食品 餐厅 香格里拉 香港
    닷넷 닷컴 삼성 한국 xxx xyz yachts yahoo yamaxun yandex ye yodobashi yoga yokohama
    you youtube yt yun za zappos zara zero zip zm zone zuerich zw
""".encode().split()  # noqa: RUF001  # TLDs in Cyrillic and other scripts
)


# Ported from td/telegram/MessageEntity.cpp, is_common_tld().
def _is_common_tld(text: bytes) -> bool:
    if all(0x61 <= c <= 0x7A for c in text):  # 'a' to 'z'
        # fast path
        return text in _COMMON_TLDS
    lowered = utf8_to_lower(text)
    if lowered != text and utf8_substr(lowered, 1) == utf8_substr(text, 1):
        return False
    return lowered in _COMMON_TLDS


# Ported from td/telegram/MessageEntity.cpp, fix_url().
def _fix_url(url: bytes) -> bytes:  # noqa: PLR0911, PLR0912, PLR0915  # mirrors upstream
    """Return `url` cut to the link TDLib keeps of it, or empty if it keeps none.

    A path stops before a bracket that closes more than it opened and before trailing
    punctuation. The domain needs two or more labels, a `teiegram.org` lookalike is
    refused, and an IPv4 address is kept; otherwise the domain needs a letter, a top
    level domain of two or more characters, and, without a protocol, one of TDLib's
    common top level domains.
    """
    full_url = url
    rest = url

    has_protocol = False
    rest_begin = rest[:10].lower()
    if rest_begin.startswith((b"http://", b"https://", b"ftp://", b"tonsite://")):
        pos = rest.find(b":")
        rest = rest[pos + 3 :]
        has_protocol = True
    domain_end = len(rest)
    for delimiter in b"/?#":
        position = rest.find(bytes([delimiter]))
        if position != -1:
            domain_end = min(domain_end, position)
    domain = rest[:domain_end]
    path = rest[domain_end:]

    at_pos = domain.find(b"@")
    if at_pos != -1:
        domain = domain[at_pos + 1 :]
    colon_pos = domain.rfind(b":")
    if colon_pos != -1:
        domain = domain[:colon_pos]

    if len(domain) == 12 and domain[0] in b"tT" and domain.lower() == b"teiegram.org":
        return b""

    balance = [0, 0, 0]
    path_pos = 0
    while path_pos < len(path):
        match path[path_pos]:
            case 0x28:  # '('
                balance[0] += 1
            case 0x5B:  # '['
                balance[1] += 1
            case 0x7B:  # '{'
                balance[2] += 1
            case 0x29:  # ')'
                balance[0] -= 1
            case 0x5D:  # ']'
                balance[1] -= 1
            case 0x7D:  # '}'
                balance[2] -= 1
        if balance[0] < 0 or balance[1] < 0 or balance[2] < 0:
            break
        path_pos += 1
    while path_pos > 0 and path[path_pos - 1] in _BAD_PATH_END_CHARS:
        path_pos -= 1
    full_url = full_url[: len(full_url) - (len(path) - path_pos)]

    prev = 0
    domain_part_count = 0
    has_non_digit = False
    is_ipv4 = True
    for i in range(len(domain) + 1):
        if i == len(domain) or domain[i] == 0x2E:  # '.'
            part_size = i - prev
            if part_size == 0 or part_size >= 64 or domain[i - 1] == 0x2D:  # '-'
                return b""
            if is_ipv4:
                if part_size > 3:
                    is_ipv4 = False
                if part_size == 3 and (
                    domain[prev] >= 0x33  # '3'
                    or (
                        domain[prev] == 0x32  # '2'
                        and (
                            domain[prev + 1] >= 0x36  # '6'
                            or (domain[prev + 1] == 0x35 and domain[prev + 2] >= 0x36)
                        )
                    )
                ):
                    is_ipv4 = False
                if domain[prev] == 0x30 and part_size >= 2:  # '0'
                    is_ipv4 = False

            domain_part_count += 1
            if i != len(domain):
                prev = i + 1
        elif not is_digit(domain[i]):
            is_ipv4 = False
            has_non_digit = True
    if domain_part_count == 1:
        return b""

    if is_ipv4 and domain_part_count == 4:
        return full_url

    if not has_non_digit:
        return b""

    tld = domain[prev:]
    if utf8_length(tld) <= 1:
        return b""

    if tld.startswith(b"xn--"):
        if len(tld) <= 5:
            return b""
        if not all(_is_alpha_digit(c) for c in tld[4:]):
            return b""
    else:
        if b"_" in tld:
            return b""
        if b"-" in tld:
            return b""

        if not has_protocol and not _is_common_tld(tld):
            return b""

    prev -= 1
    while prev > 0:
        prev -= 1
        if domain[prev] == 0x5F:  # '_'
            return b""
        if domain[prev] == 0x2E:  # '.'
            break

    return full_url


# Ported from td/telegram/MessageEntity.cpp, valid_usernames in
# get_valid_short_usernames().
_VALID_SHORT_USERNAMES = frozenset((b"gif", b"nft", b"pic", b"ufc", b"vid"))


# Ported from td/telegram/MessageEntity.cpp, find_mentions().
def find_mentions(text: bytes) -> tuple[Span, ...]:
    """Return the mentions in `text`, such as `@username`.

    A mention is `@` and 2 to 32 letters, digits, and underscores, outside a word, and
    one of 2 or 3 characters only when TDLib lists it as a valid short username.
    """
    return tuple(
        (begin, end)
        for begin, end in _match_mentions(text)
        if end - begin - 1 >= 4
        or text[begin + 1 : end].lower() in _VALID_SHORT_USERNAMES
    )


# Ported from td/telegram/MessageEntity.cpp, find_bot_commands().
def find_bot_commands(text: bytes) -> tuple[Span, ...]:
    """Return the bot commands in `text`, such as `/start` or `/start@bot`.

    A command is `/` and 1 to 64 letters, digits, and underscores, then optionally `@`
    and a username of 3 to 32 of them, outside a word and next to no `/`, `<`, or `>`.
    """
    return tuple(_match_bot_commands(text))


# Ported from td/telegram/MessageEntity.cpp, find_hashtags().
def find_hashtags(text: bytes) -> tuple[Span, ...]:
    """Return the hashtags in `text`, such as `#tag` or `#tag@channel`.

    A hashtag is `#` and the first 256 of its hashtag letters, with a letter among them,
    then optionally `@` and a username of 3 to 32 characters; it starts after no
    hashtag letter and ends before no `#`.
    """
    return tuple(_match_hashtags(text))


# Ported from td/telegram/MessageEntity.cpp, find_cashtags().
def find_cashtags(text: bytes) -> tuple[Span, ...]:
    """Return the cashtags in `text`, such as `$USD` or `$USD@exchange`.

    A cashtag is `$` and 1 to 8 capital letters or `1INCH`, then optionally `@` and a
    username of 3 to 32 characters, with no hashtag letter or `$` on either side.
    """
    return tuple(_match_cashtags(text))


# Ported from td/telegram/MessageEntity.cpp, find_bank_card_numbers().
def find_bank_card_numbers(text: bytes) -> tuple[Span, ...]:
    """Return the bank card numbers in `text`.

    A number is 13 to 19 digits that spaces and hyphens may separate, which pass the
    Luhn check and the length rules of the card brand its first digits name.
    """
    return tuple(
        span
        for span in _match_bank_card_numbers(text)
        if _is_valid_bank_card(text[span[0] : span[1]])
    )


# Ported from td/telegram/MessageEntity.cpp, find_ton_addresses().
def find_ton_addresses(text: bytes) -> tuple[Span, ...]:
    """Return the TON addresses in `text`: runs of base64 characters that are valid."""
    return tuple(_match_ton_addresses(text))


# Ported from td/telegram/MessageEntity.cpp, find_tg_urls().
def find_tg_urls(text: bytes) -> tuple[Span, ...]:
    """Return the links in `text` of the `tg`, `ton`, and `tonsite` schemes."""
    return tuple(_match_tg_urls(text))


# Ported from td/telegram/MessageEntity.cpp, find_urls().
def find_urls(text: bytes) -> tuple[tuple[Span, bool], ...]:
    """Return the links and email addresses in `text`, each with whether it is an email.

    An email address may follow `mailto:`, which its span leaves out, and a link keeps
    what `fix_url()` leaves of it.
    """
    result = []
    for begin, end in _match_urls(text):
        url = text[begin:end]
        if is_email_address(url):
            result.append(((begin, end), True))
        elif url.startswith(b"mailto:") and is_email_address(url[7:]):
            result.append(((begin + 7, end), True))
        else:
            fixed = _fix_url(url)
            if fixed:
                result.append(((begin, begin + len(fixed)), False))
    return tuple(result)


# Ported from td/telegram/MessageEntity.cpp, fix_entity_offsets().
def _fix_entity_offsets(
    text: bytes, entities: Sequence[MessageEntity]
) -> list[MessageEntity]:
    """Return `entities` sorted, without intersections, in UTF-16 code units of `text`.

    The entities come with their bounds in bytes, each at the start of a character.
    """
    if not entities:
        return []

    fixed = _remove_intersecting_entities(_sort_entities(entities))

    end = len(text)
    ptr = 0
    utf16_pos = 0
    result = []
    for entity in fixed:
        cnt = 2
        entity_begin = entity.offset
        entity_end = entity.offset + entity.length
        offset = entity.offset
        length = entity.length

        if entity_begin == ptr:
            cnt -= 1
            offset = utf16_pos

        while ptr != end and cnt > 0:
            # A character of 4 bytes takes a surrogate pair.
            utf16_pos += 1 + (text[ptr] >= 0xF0)
            ptr, _ = next_utf8_unsafe(text, ptr)

            if entity_begin == ptr:
                cnt -= 1
                offset = utf16_pos
            elif entity_end == ptr:
                cnt -= 1
                length = utf16_pos - offset
        result.append(replace(entity, offset=offset, length=length))
    return result


# Ported from td/telegram/MessageEntity.cpp, find_entities(), for skip_media_timestamps
# set.
def find_entities(text: bytes, *, skip_bot_commands: bool) -> tuple[MessageEntity, ...]:
    """Return the entities TDLib adds to `text` on its own, in UTF-16 code units.

    The entities come sorted, and one that intersects an entity before it in TDLib's
    order is dropped. A bot skips media timestamps, so none is looked for, and
    `skip_bot_commands` skips bot commands. `text` must be valid UTF-8.
    """
    entities: list[MessageEntity] = []

    def add_entities(entity_type: int, spans: Iterable[Span]) -> None:
        entities.extend(
            MessageEntity(entity_type, begin, end - begin) for begin, end in spans
        )

    add_entities(TYPE.MENTION, find_mentions(text))
    if not skip_bot_commands:
        add_entities(TYPE.BOT_COMMAND, find_bot_commands(text))
    add_entities(TYPE.HASHTAG, find_hashtags(text))
    add_entities(TYPE.CASHTAG, find_cashtags(text))
    # Upstream finds no phone numbers yet.
    add_entities(TYPE.BANK_CARD_NUMBER, find_bank_card_numbers(text))
    add_entities(TYPE.TON_ADDRESS, find_ton_addresses(text))
    add_entities(TYPE.URL, find_tg_urls(text))
    for (begin, end), is_email in find_urls(text):
        entity_type = TYPE.EMAIL_ADDRESS if is_email else TYPE.URL
        entities.append(MessageEntity(entity_type, begin, end - begin))

    return tuple(_fix_entity_offsets(text, entities))
