from tdlib_oracle.runtime.cstring import byte_at


def test_byte_at_reads_each_byte_then_zero_from_the_end_on() -> None:
    assert [byte_at(b"ab", index) for index in range(4)] == [0x61, 0x62, 0, 0]


def test_byte_at_reads_a_bytearray() -> None:
    assert byte_at(bytearray(b"\xff"), 0) == 0xFF
