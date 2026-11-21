import shlex
from collections.abc import Callable, Sequence
from dataclasses import dataclass, replace
from pathlib import Path
from typing import TypeVar

import pytest

from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_entity import TYPE, MessageEntity
from tests.support.harness import cached_build, run
from tests.support.texts import shrink

# An entity of a request or of a result: TDLib's own, or its API object, which a request
# may leave null.
Entity = MessageEntity | td_api.TextEntity | None

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


def _message_entity(entity: Entity) -> MessageEntity:
    if not isinstance(entity, MessageEntity):
        raise TypeError(f"a MessageEntity is needed here, not {entity!r}")
    return entity


def _text_entity(entity: Entity) -> td_api.TextEntity | None:
    if isinstance(entity, MessageEntity):
        raise TypeError(f"a TextEntity is needed here, not {entity!r}")
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
    """Return `entity`, then each API object its tie lets the pinned code hold instead.

    Each takes the type of an object of the tie, and the bounds of `entity`.
    """
    entity = _text_entity(entity)
    if entity is None:
        return [entity]
    return [entity] + [replace(entity, type=tie.type) for tie in entity.ties]


# The constructor of the object TDLib sends for each type of entity a user can set
# (td/telegram/MessageEntity.cpp, get_input_message_entities()).
_SENT_CONSTRUCTORS = {
    TYPE.BOLD: b"messageEntityBold",
    TYPE.ITALIC: b"messageEntityItalic",
    TYPE.UNDERLINE: b"messageEntityUnderline",
    TYPE.STRIKETHROUGH: b"messageEntityStrike",
    TYPE.SPOILER: b"messageEntitySpoiler",
    TYPE.CODE: b"messageEntityCode",
    TYPE.PRE: b"messageEntityPre",
    TYPE.PRE_CODE: b"messageEntityPre",
    TYPE.TEXT_URL: b"messageEntityTextUrl",
    TYPE.MENTION_NAME: b"inputMessageEntityMentionName",
    TYPE.CUSTOM_EMOJI: b"messageEntityCustomEmoji",
    TYPE.BLOCK_QUOTE: b"messageEntityBlockquote",
    TYPE.EXPANDABLE_BLOCK_QUOTE: b"messageEntityBlockquote",
    TYPE.FORMATTED_DATE: b"messageEntityFormattedDate",
}

# The flags of a formatted date that TDLib sends, each as a field of its own.
_SENT_DATE_FLAGS = 63


def _sent_entity_fields(entity: Entity) -> tuple[bytes, ...]:
    """Return the 6 fields the harness writes the object TDLib sends for `entity` in."""
    entity = _message_entity(entity)
    text = entity.argument if entity.type in (TYPE.PRE_CODE, TYPE.TEXT_URL) else b""
    number = 0
    flags = 0
    match entity.type:
        case TYPE.MENTION_NAME:
            number = entity.user_id
        case TYPE.CUSTOM_EMOJI:
            number = entity.custom_emoji_id
        case TYPE.EXPANDABLE_BLOCK_QUOTE:
            flags = 1
        case TYPE.FORMATTED_DATE:
            number = entity.date
            flags = entity.date_flags & _SENT_DATE_FLAGS
    return (
        _SENT_CONSTRUCTORS[entity.type],
        str(entity.offset).encode(),
        str(entity.length).encode(),
        text,
        str(number).encode(),
        str(flags).encode(),
    )


@dataclass(frozen=True)
class _Form:
    """A form the harness writes entities in.

    Attributes:
        request: The fields of an entity in a request, or `None` when no request holds
            entities in this form.
        response: The fields of an entity in a response.
        size: The number of fields `response` gives.
        ties: The entity, then each entity its tie lets the pinned code hold instead.
    """

    request: Callable[[Entity], list[bytes]] | None
    response: Callable[[Entity], tuple[bytes, ...]]
    size: int
    ties: Callable[[Entity], Sequence[Entity]]


# Each form of entity, by the name a test passes: TDLib's own entities, their API
# objects, and the objects TDLib sends to Telegram, which no request holds.
_FORMS = {
    "message": _Form(_entity_request, _entity_response, 7, _entity_ties),
    "api": _Form(
        lambda e: list(_text_entity_fields(e)),
        _text_entity_fields,
        9,
        _text_entity_ties,
    ),
    "sent": _Form(None, _sent_entity_fields, 6, _entity_ties),
}


def _pinned(
    harness: Path, function: str, requests: Sequence[_Request], form: _Form
) -> list[tuple[bytes, ...]]:
    if form.request is None:
        raise ValueError("no request holds entities in this form")
    request = form.request
    fields = [
        [
            text,
            *(str(arg).encode() for arg in args),
            *(field for entity in entities for field in request(entity)),
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
            form=_FORMS["message"],
        )

    return check


@pytest.fixture
def compare_entities(harness: Path) -> Callable[..., None]:
    """Return a check that the port matches the pinned code on cases with entities.

    The cases hold entities in the form `requests` names, and the port answers with
    entities in the form `answers` names: `message` for TDLib's own entities, `api` for
    their API objects, and `sent` for the objects TDLib sends to Telegram, which no
    request holds. At an entity the port marks as tied, any entity of its tie matches,
    since `std::sort` leaves their order to the C++ library. A differing case is shrunk
    before it fails the test: its text, its entities, and then its numeric arguments.
    """

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
