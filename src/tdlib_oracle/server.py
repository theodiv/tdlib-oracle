"""The pinned Bot API server's handling of a message text, and the verdict it gives.

`check` runs a text through the server's call order: the Bot API server's checks and the
parsing of the markup, then TDLib's processing, up to the entities TDLib sends with the
text. `Verdict`, `Refusal`, and `Entity`, the types of its result, are defined here too.
"""

import re
from collections.abc import Mapping
from dataclasses import dataclass, replace

from tdlib_oracle.botapi.client import (
    JsonEntity,
    get_error_description,
    get_input_message_text,
)
from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_content import get_input_message_content
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    MessageEntity,
    get_input_message_entities,
    get_text_entities_object,
)
from tdlib_oracle.tdlib.synchronous_requests import run_request

# The parse modes whose parsers are not ported yet, in lowercase, as the server compares
# parse modes.
_MARKDOWN_PARSE_MODES = (b"markdown", b"markdownv2")

# A bot names any valid user with no access hash (td/telegram/UserManager.cpp,
# UserManager::get_input_user()) and may use any custom emoji, so Telegram's backend
# decides whether these entities survive.
# Stands in for td/telegram/DialogManager.cpp,
# DialogManager::can_use_premium_custom_emoji_in_dialog().
_BACKEND_TYPES = frozenset({"text_mention", "custom_emoji"})

# The description of a refusal of the markup starts with this.
_PARSE_REFUSAL = "Bad Request: can't parse entities: "

# A refusal of the markup names the byte offset of what it refuses after this phrase. A
# tag name it quotes ends at a space, so the phrase is the parser's own.
_OFFSET = re.compile(r" at byte offset (\d+)", re.ASCII)


@dataclass(frozen=True)
class Refusal:
    """The pinned Bot API server's refusal of a text.

    Attributes:
        description: The error description the server returns, such
            as `Bad Request: message is too long`.
        offset: The byte offset the description names, or `None` when it names none.
    """

    description: str
    offset: int | None


@dataclass(frozen=True)
class Entity:
    """A formatting entity of the kept text, in the Bot API's `MessageEntity` form.

    Attributes:
        type: The entity type, in the Bot API's names, such as `bold` or `text_link`.
        offset: Where the entity starts, in UTF-16 code units.
        length: The length of the entity, in UTF-16 code units.
        url: The URL a `text_link` opens.
        user_id: The user a `text_mention` names.
        language: The programming language of a `pre` block.
        custom_emoji_id: The custom emoji a `custom_emoji` shows.
        unix_time: The Unix time a `date_time` shows.
        date_time_format: The format a `date_time` shows its time in.
        depends_on_backend: Whether Telegram's backend, not TDLib, decides if the
            entity survives.
        depends_on_build: Whether the C++ library the server is built with decides
            which of the entities that tie in TDLib's sort survives here, so another
            build may keep another entity with these bounds.
    """

    type: str
    offset: int
    length: int
    url: str | None = None
    user_id: int | None = None
    language: str | None = None
    custom_emoji_id: str | None = None
    unix_time: int | None = None
    date_time_format: str | None = None
    depends_on_backend: bool = False
    depends_on_build: bool = False


@dataclass(frozen=True)
class Verdict:
    """The pinned Bot API server's verdict on a text: its refusal or the text it keeps.

    `text` is `None` exactly when `accepted` is false, which is also exactly when
    `refusal` is set.

    Attributes:
        accepted: Whether the server accepts the text.
        text: The text the server keeps, or `None` when it refuses the text.
        entities: The formatting entities TDLib sends with the kept text, in the order
            it sends them.
        refusal: The server's refusal, or `None` when it accepts the text.
        depends_on_backend: Whether Telegram's backend decides if an entity survives.
        depends_on_build: Whether the C++ library the server is built with decides
            which entity survives somewhere.
    """

    accepted: bool
    text: str | None
    entities: tuple[Entity, ...]
    refusal: Refusal | None
    depends_on_backend: bool
    depends_on_build: bool = False


def _encode(text: object) -> bytes:
    """Return `text` as the bytes the server receives.

    Raises:
        TypeError: If `text` is neither `str` nor `bytes`.
    """
    if isinstance(text, str):
        return text.encode("utf-8", "surrogatepass")
    if isinstance(text, bytes):
        return text
    raise TypeError(f"text must be str or bytes, not {type(text).__name__}")


def _encode_parse_mode(parse_mode: object) -> bytes:
    """Return `parse_mode` as the bytes the server receives, empty for `None`.

    Raises:
        TypeError: If `parse_mode` is neither `str` nor `None`.
        ValueError: If `parse_mode` names a Markdown parse mode.
    """
    if parse_mode is None:
        return b""
    if not isinstance(parse_mode, str):
        raise TypeError(
            f"parse_mode must be str or None, not {type(parse_mode).__name__}"
        )
    encoded = parse_mode.encode("utf-8", "surrogatepass")
    if encoded.lower() in _MARKDOWN_PARSE_MODES:
        raise ValueError(f"parse_mode {parse_mode!r} is not supported yet")
    return encoded


def _offset(description: str) -> int | None:
    """Return the byte offset a refusal's `description` names, or `None` if none."""
    if not description.startswith(_PARSE_REFUSAL):
        return None
    match = _OFFSET.search(description, len(_PARSE_REFUSAL))
    return None if match is None else int(match[1])


def _string(members: Mapping[str, bytes | int], name: str) -> str | None:
    value = members.get(name)
    return value.decode("utf-8", "replace") if isinstance(value, bytes) else None


def _integer(members: Mapping[str, bytes | int], name: str) -> int | None:
    value = members.get(name)
    return value if isinstance(value, int) else None


def _as_sent(entity: MessageEntity) -> MessageEntity:
    """Return `entity` as TDLib sends it.

    TDLib sends a pre block in `messageEntityPre`, whose empty language stands for none,
    so a pre block whose language is empty goes as one without a language, which is how
    TDLib reads it back.
    """
    # Stands in for td/telegram/MessageEntity.cpp, get_input_message_entities(const
    # UserManager *user_manager, const vector<MessageEntity> &entities, const char
    # *source), the object it sends a pre block in.
    # Stands in for td/telegram/MessageEntity.cpp, get_message_entities(const
    # UserManager *user_manager, vector<tl_object_ptr<telegram_api::MessageEntity>>
    # &&server_entities, const char *source), its read of that object.
    if entity.type == TYPE.PRE_CODE and not entity.argument:
        return replace(entity, type=TYPE.PRE)
    return entity


def _entity(text_entity: td_api.TextEntity) -> Entity:
    """Return the API object `text_entity` as the Bot API server writes it, marked.

    The server writes the user a mention names as an object of the user's details, of
    which only the ID is certain, so the ID stands for it.
    """
    members = dict(JsonEntity(text_entity).store())
    entity_type = _string(members, "type") or ""
    return Entity(
        type=entity_type,
        offset=text_entity.offset,
        length=text_entity.length,
        url=_string(members, "url"),
        user_id=_integer(members, "user"),
        language=_string(members, "language"),
        custom_emoji_id=_string(members, "custom_emoji_id"),
        unix_time=_integer(members, "unix_time"),
        date_time_format=_string(members, "date_time_format"),
        depends_on_backend=entity_type in _BACKEND_TYPES,
        depends_on_build=bool(text_entity.ties),
    )


def check(text: str | bytes, *, parse_mode: str | None = None) -> Verdict:
    """Return the pinned Bot API server's verdict on a bot's message text.

    A `str` stands for what a client sends: it is encoded as UTF-8, and a surrogate code
    point keeps its 3-byte form, which the server refuses as invalid UTF-8. `bytes`
    stand for the field as the server receives it. Options are keyword-only, so a new
    option never changes the meaning of an existing call.

    Args:
        text: The message text.
        parse_mode: The markup of the text: `HTML` in any letter case is parsed, and
            `None`, an empty string, or `none` in any letter case parses nothing; any
            other name gets the server's refusal.

    Raises:
        TypeError: If `text` is neither `str` nor `bytes`, or `parse_mode` is neither
            `str` nor `None`.
        ValueError: If `parse_mode` is `Markdown` or `MarkdownV2` in any letter case,
            whose parsers no release ports yet.
    """
    data = _encode(text)
    mode = _encode_parse_mode(parse_mode)

    # Client::execute() reaches run_request() through these, which pass the request on.
    # Stands in for td/telegram/ClientActor.cpp, ClientActor::execute().
    # Stands in for td/telegram/Td.cpp, Td::static_request().
    formatted_text = get_input_message_text(data, mode, execute=run_request)
    result = (
        formatted_text
        if isinstance(formatted_text, Failure)
        else get_input_message_content(formatted_text)
    )

    if isinstance(result, Failure):
        description = get_error_description(result)
        return Verdict(
            accepted=False,
            text=None,
            entities=(),
            refusal=Refusal(description=description, offset=_offset(description)),
            depends_on_backend=False,
        )

    # The entities TDLib sends with the text, once the message goes out.
    # Stands in for td/telegram/MessagesManager.cpp, SendMessageQuery::send().
    sending = get_input_message_entities(result.entities)
    sent = get_text_entities_object(tuple(_as_sent(entity) for entity in sending))
    entities = tuple(_entity(entity) for entity in sent)
    return Verdict(
        accepted=True,
        text=result.text.decode("utf-8", "replace"),
        entities=entities,
        refusal=None,
        depends_on_backend=any(entity.depends_on_backend for entity in entities),
        depends_on_build=any(entity.depends_on_build for entity in entities),
    )
