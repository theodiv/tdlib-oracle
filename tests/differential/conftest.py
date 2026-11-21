import shlex
from collections.abc import Callable, Sequence
from dataclasses import replace
from pathlib import Path
from typing import TypeVar

import pytest

from tdlib_oracle.tdlib.message_entity import MessageEntity
from tests.support.harness import cached_build, run
from tests.support.texts import shrink

# The port's result for a text and the function's other arguments, in the fields the
# harness answers with.
Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]

# A text, as a tuple of units, and the function's other arguments.
Case = tuple[tuple[bytes, ...], tuple[int, ...]]

# The port's result for a text, the function's numeric arguments, and its entities: the
# fields the harness answers with before the entities, and the entities.
EntityPort = Callable[
    [bytes, tuple[int, ...], tuple[MessageEntity, ...]],
    tuple[tuple[bytes, ...], tuple[MessageEntity, ...]],
]

# A text, as a tuple of units, the function's numeric arguments, and its entities.
EntityCase = tuple[tuple[bytes, ...], tuple[int, ...], tuple[MessageEntity, ...]]

# A text, the function's numeric arguments, and its entities, as a request carries them.
_Request = tuple[bytes, tuple[int, ...], tuple[MessageEntity, ...]]

# The fields the harness answers an entity with.
_ENTITY_FIELDS = 7

_FIXED_SEEDS = (20261116, 20261117)

# Generous enough for a build with --coverage or the sanitizers; a run of the plain
# build takes seconds.
_TIMEOUT = 300.0

_Result = TypeVar("_Result")


@pytest.fixture(scope="session")
def harness(
    pytestconfig: pytest.Config, tmp_path_factory: pytest.TempPathFactory
) -> Path:
    """Return the compiled pinned TDLib functions.

    A build without `--harness-flags` is kept in `.pytest_cache/` until one of its
    inputs changes or `pytest --cache-clear` empties the cache, so later sessions
    skip it.
    """
    root = pytestconfig.rootpath
    td = root / "tests" / "data" / "td"
    tl = root / "tests" / "data" / "tl"
    sources = [
        *sorted(td.rglob("*.cpp")),
        *sorted(tl.rglob("*.cpp")),
        root / "tests" / "support" / "harness.cpp",
    ]
    # Each component of td other than td itself keeps its headers in a td/ directory.
    components = sorted(path for path in td.iterdir() if (path / "td").is_dir())
    flags = shlex.split(pytestconfig.getoption("harness_flags"))
    jobs: int | None = pytestconfig.getoption("harness_jobs")
    return cached_build(
        sources,
        [td, *components, tl],
        pytestconfig.cache.mkdir("harness"),
        tmp_path_factory.mktemp("harness"),
        flags=flags,
        jobs=jobs,
    )


@pytest.fixture
def seeds(pytestconfig: pytest.Config) -> tuple[int, ...]:
    """Return the seeds to draw texts from: `--differential-seed`, or the fixed ones."""
    seed: int | None = pytestconfig.getoption("differential_seed")
    return _FIXED_SEEDS if seed is None else (seed,)


@pytest.fixture
def count(pytestconfig: pytest.Config) -> int:
    """Return the number of texts to draw from each seed, `--differential-count`."""
    value: int = pytestconfig.getoption("differential_count")
    return value


def _entity_request(entity: MessageEntity) -> list[bytes]:
    head = (entity.type, entity.offset, entity.length)
    tail = (entity.user_id, entity.custom_emoji_id, entity.date, entity.date_flags)
    return [
        *(str(number).encode() for number in head),
        entity.argument,
        *(str(number).encode() for number in tail),
    ]


def _entity_response(entity: MessageEntity) -> tuple[bytes, ...]:
    head = (entity.type, entity.offset, entity.length)
    tail = (entity.user_id, entity.custom_emoji_id)
    return (
        *(str(number).encode() for number in head),
        entity.argument,
        *(str(number).encode() for number in tail),
        f"date {entity.date} with flags {entity.date_flags}".encode(),
    )


def _pinned(
    harness: Path, function: str, requests: Sequence[_Request]
) -> list[tuple[bytes, ...]]:
    fields = [
        [
            text,
            *(str(arg).encode() for arg in args),
            *(field for entity in entities for field in _entity_request(entity)),
        ]
        for text, args, entities in requests
    ]
    return run(harness, function, fields, timeout=_TIMEOUT)


def _matches_entities(
    ours: tuple[tuple[bytes, ...], tuple[MessageEntity, ...]],
    theirs: tuple[bytes, ...],
) -> bool:
    """Return whether the harness answered as the port did, ties allowed for."""
    fields, entities = ours
    size = len(fields) + _ENTITY_FIELDS * len(entities)
    if theirs[: len(fields)] != fields or len(theirs) != size:
        return False
    for index, entity in enumerate(entities):
        start = len(fields) + _ENTITY_FIELDS * index
        answer = theirs[start : start + _ENTITY_FIELDS]
        candidates = [entity] + [
            replace(
                entity,
                type=tie.type,
                argument=tie.argument,
                user_id=tie.user_id,
                custom_emoji_id=tie.custom_emoji_id,
                date=tie.date,
                date_flags=tie.date_flags,
            )
            for tie in entity.ties
        ]
        if all(_entity_response(candidate) != answer for candidate in candidates):
            return False
    return True


def _shrink_case(
    harness: Path,
    function: str,
    port: Callable[[bytes, tuple[int, ...], tuple[MessageEntity, ...]], _Result],
    matches: Callable[[_Result, tuple[bytes, ...]], bool],
    case: EntityCase,
    *,
    by_bytes: bool,
) -> EntityCase:
    def differs(requests: list[_Request]) -> list[bool]:
        pinned = _pinned(harness, function, requests)
        return [
            not matches(port(*request), result)
            for request, result in zip(requests, pinned, strict=True)
        ]

    units, args, entities = case
    units = shrink(
        units,
        lambda candidates: differs(
            [(b"".join(candidate), args, entities) for candidate in candidates]
        ),
        by_bytes=by_bytes,
    )
    text = b"".join(units)

    while entities:
        removals = [
            entities[:index] + entities[index + 1 :] for index in range(len(entities))
        ]
        flagged = [
            removal
            for removal, failed in zip(
                removals,
                differs([(text, args, removal) for removal in removals]),
                strict=True,
            )
            if failed
        ]
        if not flagged:
            break
        entities = flagged[0]

    for position in range(len(args)):
        while args[position] > 0:
            values = sorted({0, args[position] // 2, args[position] - 1})
            candidates = [
                (*args[:position], value, *args[position + 1 :]) for value in values
            ]
            smaller = [
                other
                for other, failed in zip(
                    candidates,
                    differs([(text, other, entities) for other in candidates]),
                    strict=True,
                )
                if failed
            ]
            if not smaller:
                break
            args = smaller[0]
    return units, args, entities


def _check(
    harness: Path,
    function: str,
    port: Callable[[bytes, tuple[int, ...], tuple[MessageEntity, ...]], _Result],
    matches: Callable[[_Result, tuple[bytes, ...]], bool],
    cases: Sequence[EntityCase],
    *,
    seed: int | None,
    by_bytes: bool,
) -> None:
    requests = [(b"".join(units), args, entities) for units, args, entities in cases]
    pinned = _pinned(harness, function, requests)
    for index, (request, result) in enumerate(zip(requests, pinned, strict=True)):
        if matches(port(*request), result):
            continue
        small_units, small_args, small_entities = _shrink_case(
            harness, function, port, matches, cases[index], by_bytes=by_bytes
        )
        text = b"".join(small_units)
        (shrunk,) = _pinned(harness, function, [(text, small_args, small_entities)])
        origin = "a fixed case" if seed is None else f"seed {seed}"
        shown = f" and entities {small_entities!r}" if small_entities else ""
        pytest.fail(
            f"{function} differs on {origin}, case {index}, shrunk to {text!r}"
            f" with arguments {small_args}{shown}: the port gives"
            f" {port(text, small_args, small_entities)!r}, the pinned code {shrunk!r}"
        )


@pytest.fixture
def compare(harness: Path) -> Callable[..., None]:
    """Return a check that the port gives the pinned code's result on each case.

    A differing case is shrunk before it fails the test, its text and then its numeric
    arguments, so the failure shows the smallest case found that still differs.
    """

    def check(
        function: str,
        port: Port,
        cases: Sequence[Case],
        *,
        seed: int | None,
        by_bytes: bool,
    ) -> None:
        _check(
            harness,
            function,
            lambda text, args, entities: port(text, args),
            lambda ours, theirs: ours == theirs,
            [(units, args, ()) for units, args in cases],
            seed=seed,
            by_bytes=by_bytes,
        )

    return check


@pytest.fixture
def compare_entities(harness: Path) -> Callable[..., None]:
    """Return a check that the port matches the pinned code on cases with entities.

    At an entity the port marks as tied, any entity of its tie matches, since
    `std::sort` leaves their order to the C++ library. A differing case is shrunk
    before it fails the test: its text, its entities, and then its numeric arguments.
    """

    def check(
        function: str,
        port: EntityPort,
        cases: Sequence[EntityCase],
        *,
        seed: int | None,
        by_bytes: bool,
    ) -> None:
        _check(
            harness,
            function,
            port,
            _matches_entities,
            cases,
            seed=seed,
            by_bytes=by_bytes,
        )

    return check
