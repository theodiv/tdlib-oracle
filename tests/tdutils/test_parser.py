import pytest

from tdlib_oracle.tdutils.parser import read_till_nofail


@pytest.mark.parametrize(
    ("data", "pos", "characters", "span"),
    [
        (b"http://a.b", 0, b":/?#@[]", (0, 4)),
        (b"a.b/c?d", 0, b"/?#", (0, 3)),
        (b"a.b/c?d", 4, b"/?#", (4, 5)),
        (b"a.b", 0, b"/?#", (0, 3)),
        (b"a.b", 3, b"/?#", (3, 3)),
        (b"", 0, b"/?#", (0, 0)),
    ],
)
def test_read_till_nofail_reads_up_to_the_first_of_the_characters_or_the_end(
    data: bytes, pos: int, characters: bytes, span: tuple[int, int]
) -> None:
    assert read_till_nofail(data, pos, characters) == span
