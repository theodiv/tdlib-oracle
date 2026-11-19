"""Entity lists for the differential tests, drawn from a seed."""

import random

from tdlib_oracle.tdlib.entities import TYPE, MessageEntity

# The values each kind of entity tells apart: an empty argument or not, user IDs on both
# sides of each bound of a valid one, a custom emoji ID of zero or not, and dates of
# zero, below it, or after it, with flags for different parts of a date.
_ARGUMENTS = (b"", b"a", b"t.me")
_USER_IDS = (0, 1, 7, (1 << 40) - 1, 1 << 40, -1)
_CUSTOM_EMOJI_IDS = (0, 1, -1, 5)
_DATES = (0, -1, 1, 1_700_000_000)
_DATE_FLAGS = (0, 1, 6, 16)

# Offsets and lengths far outside any text: around TDLib's bound of 1,000,000, and at
# the ends of a 32-bit integer.
_FAR_BOUNDS = (-1, 1_000_000, 1_000_001, -(1 << 31), (1 << 31) - 1)

# Lists longer than this leave libstdc++'s insertion sort, which keeps ties in order.
_INSERTION_SORT_SIZE = 16


def _draw_bound(rng: random.Random, limit: int, *, far: bool) -> int:
    if far and rng.random() < 0.05:
        return rng.choice(_FAR_BOUNDS)
    return rng.randint(0, limit)


def draw_entities(
    rng: random.Random, utf16_length: int, *, max_count: int = 30
) -> tuple[MessageEntity, ...]:
    """Return entities for a text of `utf16_length` UTF-16 code units, drawn with `rng`.

    Each list takes its types, offsets, and lengths from a few of each, so that entities
    nest, overlap, touch, and tie as often as they stand apart, and a fifth of the lists
    hold more than 16 entities, where libstdc++'s `std::sort` may reorder ties. Every
    type draws values valid and invalid. Three lists in four keep each entity within
    the text, since one entity past its end refuses the whole text; in the others,
    entities may start or end past the end, and now and then a bound falls far outside.
    """
    types = rng.sample(range(TYPE.SIZE), rng.randint(1, 6))
    leaves = rng.random() < 0.25
    limit = utf16_length + 1 if leaves else utf16_length
    offsets = [_draw_bound(rng, limit, far=leaves) for _ in range(rng.randint(1, 4))]
    lengths = [_draw_bound(rng, limit, far=leaves) for _ in range(rng.randint(1, 4))]
    if rng.random() < 0.2:
        count = rng.randint(_INSERTION_SORT_SIZE + 1, max_count)
    else:
        count = rng.randint(0, 8)

    entities = []
    for _ in range(count):
        offset = rng.choice(offsets)
        length = rng.choice(lengths)
        if not leaves:
            length = min(length, utf16_length - offset)
        entities.append(
            MessageEntity(
                rng.choice(types),
                offset,
                length,
                rng.choice(_ARGUMENTS),
                rng.choice(_USER_IDS),
                rng.choice(_CUSTOM_EMOJI_IDS),
                rng.choice(_DATES),
                rng.choice(_DATE_FLAGS),
            )
        )
    return tuple(entities)
