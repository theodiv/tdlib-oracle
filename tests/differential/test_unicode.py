from collections.abc import Callable

import pytest

from tdlib_oracle.tdutils.unicode import get_unicode_simple_category, unicode_to_lower

pytestmark = pytest.mark.differential

Compare = Callable[..., None]


def test_get_unicode_simple_category_gives_the_pinned_category_of_each_code_point(
    compare: Compare,
) -> None:
    cases = [((), (code,)) for code in range(0x10FFFF + 1)]
    compare(
        "get_unicode_simple_category",
        lambda text, args: (str(get_unicode_simple_category(args[0])).encode(),),
        cases,
        seed=None,
        by_bytes=False,
    )


def test_unicode_to_lower_gives_the_pinned_form_of_each_code_point(
    compare: Compare,
) -> None:
    # One past the last code point, as TDLib's own test of unicode_to_lower() goes.
    cases = [((), (code,)) for code in range(0x110000 + 1)]
    compare(
        "unicode_to_lower",
        lambda text, args: (str(unicode_to_lower(args[0])).encode(),),
        cases,
        seed=None,
        by_bytes=False,
    )
