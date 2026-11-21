import pytest

from tdlib_oracle.tdutils.unicode import (
    CATEGORY,
    get_unicode_simple_category,
    unicode_to_lower,
)


@pytest.mark.parametrize(
    ("code", "category"),
    [
        (0x61, CATEGORY.LETTER),  # a
        (0x37, CATEGORY.DECIMAL_NUMBER),  # 7
        (0x20, CATEGORY.SEPARATOR),  # space
        (0x5F, CATEGORY.UNKNOWN),  # underscore
        (0x0430, CATEGORY.LETTER),  # Cyrillic small a
        (0x0663, CATEGORY.DECIMAL_NUMBER),  # Arabic-Indic digit three
        (0x00BD, CATEGORY.NUMBER),  # vulgar fraction one half
        (0x00A0, CATEGORY.SEPARATOR),  # no-break space
        (0x2028, CATEGORY.SEPARATOR),  # line separator
        (0x0301, CATEGORY.UNKNOWN),  # combining acute accent
        (0x1D49C, CATEGORY.LETTER),  # mathematical script capital A
        (0x20000, CATEGORY.LETTER),  # the last code point of the blocks of 128
        (0x20001, CATEGORY.LETTER),  # the first code point of the blocks of 65,536
        (0xE0001, CATEGORY.UNKNOWN),  # language tag
        (0x10FFFF, CATEGORY.UNKNOWN),  # the last code point
    ],
)
def test_get_unicode_simple_category_reads_the_tables(code: int, category: int) -> None:
    assert get_unicode_simple_category(code) == category


@pytest.mark.parametrize(
    ("code", "lower"),
    [
        (0x41, 0x61),  # A, from the table
        (0x61, 0x61),  # a
        (0x0130, 0x69),  # capital I with dot above, to i
        (0x1E00, 0x1E01),  # a range that sets the lowest bit
        (0x1E01, 0x1E01),
        (0x1E9E, 0xDF),  # capital sharp s, a range of one code point
        (0x10400, 0x10428),  # Deseret, a range that shifts its code points
        (0x10FFFF, 0x10FFFF),
    ],
)
def test_unicode_to_lower_gives_the_lowercase_form(code: int, lower: int) -> None:
    assert unicode_to_lower(code) == lower


def test_unicode_to_lower_gives_zero_past_the_last_code_point() -> None:
    assert unicode_to_lower(0x110000) == 0
