import pytest

from tdlib_oracle.tdutils.algorithm import combine


@pytest.mark.parametrize(
    ("destination", "source", "combined"),
    [
        ([1, 2], [3], [1, 2, 3]),
        ([1], [2, 3], [2, 3, 1]),
        ([1], [2], [1, 2]),
        ([], [1], [1]),
        ([], [], []),
    ],
)
def test_combine_puts_the_longer_list_first_and_destination_first_when_as_long(
    destination: list[int], source: list[int], combined: list[int]
) -> None:
    assert combine(destination, source) == combined
