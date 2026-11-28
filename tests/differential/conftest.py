import shlex
from collections.abc import Callable, Sequence
from dataclasses import dataclass, replace
from pathlib import Path
from typing import TypeVar

import pytest

from tdlib_oracle.tdlib import td_api, telegram_api
from tdlib_oracle.tdlib.message_entity import MessageEntity
from tests.support.harness import cached_build, run
from tests.support.texts import shrink

# An entity of a request or of a result: TDLib's own, its API object, which a request
# may leave null, or the object Telegram's API holds it in.
Entity = MessageEntity | td_api.TextEntity | telegram_api.MessageEntity | None

# The port's result for a text and the function's other arguments, in the fields the
# harness answers with.
Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]

# A text, as a tuple of units, and the function's other arguments.
Case = tuple[tuple[bytes, ...], tuple[int, ...]]

# The port's result for a text, the function's numeric arguments, and its entities: the
# fields the harness answers with before the entities, and the entities.
EntityPort = Callable[
    [bytes, tuple[int, ...], tuple[Entity, ...]],
    tuple[tuple[bytes, ...], tuple[Entity, ...]],
]

# A text, as a tuple of units, the function's numeric arguments, and its entities.
EntityCase = tuple[tuple[bytes, ...], tuple[int, ...], tuple[Entity, ...]]

# A text, the function's numeric arguments, and its entities, as a request carries them.
_Request = tuple[bytes, tuple[int, ...], tuple[Entity, ...]]

_FIXED_SEEDS = (20261116, 20261117)

# Generous enough for a build with --coverage or the sanitizers; a run of the plain
# build takes seconds.
_TIMEOUT = 300.0

_Result = TypeVar("_Result")


@pytest.fixture(scope="session")
def harness(
    pytestconfig: pytest.Config, tmp_path_factory: pytest.TempPathFactory
) -> Path:
    """Return the compiled pinned TDLib functions."""
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


def _message_entity(entity: Entity) -> MessageEntity:
    if not isinstance(entity, MessageEntity):
        raise TypeError(f"a MessageEntity is needed here, not {entity!r}")
    return entity


def _text_entity(entity: Entity) -> td_api.TextEntity | None:
    if entity is not None and not isinstance(entity, td_api.TextEntity):
        raise TypeError(f"a TextEntity is needed here, not {entity!r}")
    return entity


def _sent_entity(entity: Entity) -> telegram_api.MessageEntity:
    if entity is None or isinstance(entity, MessageEntity | td_api.TextEntity):
        raise TypeError(f"an object of Telegram's API is needed here, not {entity!r}")
    return entity


def _entity_request(entity: Entity) -> list[bytes]:
    entity = _message_entity(entity)
    head = (entity.type, entity.offset, entity.length)
    tail = (entity.user_id, entity.custom_emoji_id, entity.date, entity.date_flags)
    return [
        *(str(number).encode() for number in head),
        entity.argument,
        *(str(number).encode() for number in tail),
    ]


def _entity_response(entity: Entity) -> tuple[bytes, ...]:
    entity = _message_entity(entity)
    head = (entity.type, entity.offset, entity.length)
    tail = (entity.user_id, entity.custom_emoji_id)
    return (
        *(str(number).encode() for number in head),
        entity.argument,
        *(str(number).encode() for number in tail),
        f"date {entity.date} with flags {entity.date_flags}".encode(),
    )


def _entity_ties(entity: Entity) -> Sequence[Entity]:
    """Return `entity`, then each entity its tie lets the pinned code hold in its place.

    Each takes the type and value of an entity of the tie, and the bounds of `entity`,
    since those of the tie are the ones the entities had when the sort met them.
    """
    entity = _message_entity(entity)
    return [entity] + [
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


def _constructor(value: object) -> bytes:
    """Return the name of the TL constructor that the API object `value` stands for."""
    name = type(value).__name__
    return (name[0].lower() + name[1:]).encode()


def _precision_field(precision: td_api.DateTimePartPrecision | None) -> bytes:
    match precision:
        case td_api.DateTimePartPrecisionNone():
            return b"none"
        case td_api.DateTimePartPrecisionShort():
            return b"short"
        case td_api.DateTimePartPrecisionLong():
            return b"long"
        case None:
            return b""


def _formatting_type_fields(
    formatting_type: td_api.DateTimeFormattingType | None,
) -> tuple[bytes, ...]:
    match formatting_type:
        case td_api.DateTimeFormattingTypeRelative():
            return (b"relative", b"", b"", b"0")
        case td_api.DateTimeFormattingTypeAbsolute():
            return (
                b"absolute",
                _precision_field(formatting_type.time_precision),
                _precision_field(formatting_type.date_precision),
                b"1" if formatting_type.show_day_of_week else b"0",
            )
        case None:
            return (b"", b"", b"", b"0")


def _text_entity_fields(entity: Entity) -> tuple[bytes, ...]:
    """Return an entity's API object in the 9 fields the harness reads and writes."""
    entity = _text_entity(entity)
    if entity is None:
        return (b"", b"0", b"0", b"", b"0", *_formatting_type_fields(None))
    text = b""
    number = 0
    formatting_type: td_api.DateTimeFormattingType | None = None
    match entity.type:
        case td_api.TextEntityTypePreCode():
            text = entity.type.language
        case td_api.TextEntityTypeTextUrl():
            text = entity.type.url
        case td_api.TextEntityTypeMentionName():
            number = entity.type.user_id
        case td_api.TextEntityTypeCustomEmoji():
            number = entity.type.custom_emoji_id
        case td_api.TextEntityTypeMediaTimestamp():
            number = entity.type.media_timestamp
        case td_api.TextEntityTypeDateTime():
            number = entity.type.unix_time
            formatting_type = entity.type.formatting_type
    name = b"null" if entity.type is None else _constructor(entity.type)
    return (
        name,
        str(entity.offset).encode(),
        str(entity.length).encode(),
        text,
        str(number).encode(),
        *_formatting_type_fields(formatting_type),
    )


def _text_entity_ties(entity: Entity) -> Sequence[Entity]:
    """Return `entity`, then each API object of its tie the pinned code may hold."""
    entity = _text_entity(entity)
    if entity is None:
        return [entity]
    return [entity] + [replace(entity, type=tie.type) for tie in entity.ties]


def _sent_entity_fields(entity: Entity) -> tuple[bytes, ...]:
    """Return an object of Telegram's API in the 6 fields the harness reads and writes.

    The fields are the constructor, the offset, and the length; the language or the
    link; the user, the custom emoji, or the date; and whether a blockquote is
    collapsed, or the parts a date shows, as `FormattedDate`'s flags.
    """
    entity = _sent_entity(entity)
    text = b""
    number = 0
    flags = 0
    match entity:
        case telegram_api.MessageEntityPre():
            text = entity.language
        case telegram_api.MessageEntityTextUrl():
            text = entity.url
        case telegram_api.InputMessageEntityMentionName(
            user_id=telegram_api.InputUser() as user
        ):
            number = user.user_id
        case telegram_api.MessageEntityMentionName():
            number = entity.user_id
        case telegram_api.MessageEntityCustomEmoji():
            number = entity.document_id
        case telegram_api.MessageEntityBlockquote():
            flags = int(entity.collapsed)
        case telegram_api.MessageEntityFormattedDate():
            number = entity.date
            parts = (
                entity.relative,
                entity.short_time,
                entity.long_time,
                entity.short_date,
                entity.long_date,
                entity.day_of_week,
            )
            flags = sum(1 << bit for bit, part in enumerate(parts) if part)
    return (
        _constructor(entity),
        str(entity.offset).encode(),
        str(entity.length).encode(),
        text,
        str(number).encode(),
        str(flags).encode(),
    )


def _sent_entity_ties(entity: Entity) -> Sequence[Entity]:
    """Return `entity`, then each object its tie lets the pinned code hold instead."""
    entity = _sent_entity(entity)
    return [entity] + [
        replace(tie, offset=entity.offset, length=entity.length) for tie in entity.ties
    ]


@dataclass(frozen=True)
class _Form:
    """A form the harness writes entities in."""

    request: Callable[[Entity], list[bytes]]
    response: Callable[[Entity], tuple[bytes, ...]]
    size: int
    ties: Callable[[Entity], Sequence[Entity]]


# Each form of entity, by the name a test passes: TDLib's own entities, their API
# objects, and the objects of Telegram's API that TDLib sends and reads back.
_FORMS = {
    "message": _Form(_entity_request, _entity_response, 7, _entity_ties),
    "api": _Form(
        lambda e: list(_text_entity_fields(e)),
        _text_entity_fields,
        9,
        _text_entity_ties,
    ),
    "sent": _Form(
        lambda e: list(_sent_entity_fields(e)),
        _sent_entity_fields,
        6,
        _sent_entity_ties,
    ),
}


def _pinned(
    harness: Path, function: str, requests: Sequence[_Request], form: _Form
) -> list[tuple[bytes, ...]]:
    fields = [
        [
            text,
            *(str(arg).encode() for arg in args),
            *(field for entity in entities for field in form.request(entity)),
        ]
        for text, args, entities in requests
    ]
    return run(harness, function, fields, timeout=_TIMEOUT)


def _matches_entities(
    ours: tuple[tuple[bytes, ...], tuple[Entity, ...]],
    theirs: tuple[bytes, ...],
    form: _Form,
) -> bool:
    """Return whether the harness answered as the port did, ties allowed for."""
    fields, entities = ours
    size = len(fields) + form.size * len(entities)
    if theirs[: len(fields)] != fields or len(theirs) != size:
        return False
    for index, entity in enumerate(entities):
        start = len(fields) + form.size * index
        answer = theirs[start : start + form.size]
        if all(form.response(candidate) != answer for candidate in form.ties(entity)):
            return False
    return True


def _shrink_case(
    harness: Path,
    function: str,
    port: Callable[[bytes, tuple[int, ...], tuple[Entity, ...]], _Result],
    matches: Callable[[_Result, tuple[bytes, ...]], bool],
    case: EntityCase,
    *,
    by_bytes: bool,
    form: _Form,
) -> EntityCase:
    def differs(requests: list[_Request]) -> list[bool]:
        pinned = _pinned(harness, function, requests, form)
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
    port: Callable[[bytes, tuple[int, ...], tuple[Entity, ...]], _Result],
    matches: Callable[[_Result, tuple[bytes, ...]], bool],
    cases: Sequence[EntityCase],
    *,
    seed: int | None,
    by_bytes: bool,
    form: _Form,
) -> None:
    requests = [(b"".join(units), args, entities) for units, args, entities in cases]
    pinned = _pinned(harness, function, requests, form)
    for index, (request, result) in enumerate(zip(requests, pinned, strict=True)):
        if matches(port(*request), result):
            continue

        # A differing case is shrunk first, so the failure shows the smallest case found
        # that still differs.
        small_units, small_args, small_entities = _shrink_case(
            harness, function, port, matches, cases[index], by_bytes=by_bytes, form=form
        )
        text = b"".join(small_units)
        (shrunk,) = _pinned(
            harness, function, [(text, small_args, small_entities)], form
        )
        origin = "a fixed case" if seed is None else f"seed {seed}"
        shown = f" and entities {small_entities!r}" if small_entities else ""
        pytest.fail(
            f"{function} differs on {origin}, case {index}, shrunk to {text!r}"
            f" with arguments {small_args}{shown}: the port gives"
            f" {port(text, small_args, small_entities)!r}, the pinned code {shrunk!r}"
        )


@pytest.fixture
def compare(harness: Path) -> Callable[..., None]:
    """Return a check that the port gives the pinned code's result on each case."""

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
            form=_FORMS["message"],
        )

    return check


@pytest.fixture
def compare_entities(harness: Path) -> Callable[..., None]:
    """Return a check that the port matches the pinned code on cases with entities."""

    def check(
        function: str,
        port: EntityPort,
        cases: Sequence[EntityCase],
        *,
        seed: int | None,
        by_bytes: bool,
        requests: str = "message",
        answers: str = "message",
    ) -> None:
        answered = _FORMS[answers]
        _check(
            harness,
            function,
            port,
            lambda ours, theirs: _matches_entities(ours, theirs, answered),
            cases,
            seed=seed,
            by_bytes=by_bytes,
            form=_FORMS[requests],
        )

    return check


@pytest.fixture
def compare_by(harness: Path) -> Callable[..., None]:
    """Return a check that `matches` finds the port's result in each pinned answer."""

    def check(
        function: str,
        port: Callable[[bytes, tuple[int, ...]], _Result],
        matches: Callable[[_Result, tuple[bytes, ...]], bool],
        cases: Sequence[Case],
        *,
        seed: int | None,
        by_bytes: bool,
    ) -> None:
        _check(
            harness,
            function,
            lambda text, args, entities: port(text, args),
            matches,
            [(units, args, ()) for units, args in cases],
            seed=seed,
            by_bytes=by_bytes,
            form=_FORMS["message"],
        )

    return check
