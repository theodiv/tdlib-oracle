"""The pinned Bot API server's handling of a message text, and the verdict it gives.

`check` runs a text through the server's call order: the Bot API server's checks, then
TDLib's processing. `Verdict`, `Refusal`, and `Entity`, the types of its result, are
defined here too.
"""

from dataclasses import dataclass

from tdlib_oracle.botapi.checks import get_input_message_text
from tdlib_oracle.botapi.descriptions import get_error_description
from tdlib_oracle.tdlib.content import get_input_message_content
from tdlib_oracle.text.failure import Failure


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


@dataclass(frozen=True)
class Verdict:
    """The pinned Bot API server's verdict on a text: its refusal or the text it keeps.

    `text` is `None` exactly when `accepted` is false, which is also exactly when
    `refusal` is set.

    Attributes:
        accepted: Whether the server accepts the text.
        text: The text the server keeps, or `None` when it refuses the text.
        entities: The formatting entities of the kept text.
        refusal: The server's refusal, or `None` when it accepts the text.
        depends_on_backend: Whether Telegram's backend decides if an entity survives.
    """

    accepted: bool
    text: str | None
    entities: tuple[Entity, ...]
    refusal: Refusal | None
    depends_on_backend: bool


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


def check(text: str | bytes) -> Verdict:
    """Return the pinned Bot API server's verdict on a bot's message text.

    A `str` stands for what a client sends: it is encoded as UTF-8, and a surrogate code
    point keeps its 3-byte form, which the server refuses as invalid UTF-8. `bytes`
    stand for the field as the server receives it.

    Raises:
        TypeError: If `text` is neither `str` nor `bytes`.
    """
    result = get_input_message_text(_encode(text))
    if not isinstance(result, Failure):
        result = get_input_message_content(result)

    if isinstance(result, Failure):
        # No refusal of a plain text names a byte offset.
        refusal = Refusal(description=get_error_description(result), offset=None)
        return Verdict(
            accepted=False,
            text=None,
            entities=(),
            refusal=refusal,
            depends_on_backend=False,
        )

    return Verdict(
        accepted=True,
        text=result.decode("utf-8", "replace"),
        entities=(),
        refusal=None,
        depends_on_backend=False,
    )
