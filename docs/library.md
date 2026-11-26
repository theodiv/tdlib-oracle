# Library

Every name in `tdlib_oracle.__all__`, with its parameters, return value, and
exceptions. What a result means: [Behavior](behavior.md).

## `Entity`

A formatting entity of the kept text, in the Bot API's `MessageEntity` form.

- `type` — the entity type, in the Bot API's names, such as `bold`
  or `text_link`.
- `offset` — where the entity starts, in UTF-16 code units.
- `length` — the length of the entity, in UTF-16 code units.
- `url` — the URL a `text_link` opens; default `None`.
- `user_id` — the user a `text_mention` names; default `None`.
- `language` — the programming language of a `pre` block; default `None`.
- `custom_emoji_id` — the custom emoji a `custom_emoji` shows; default `None`.
- `unix_time` — the Unix time a `date_time` shows; default `None`.
- `date_time_format` — the format a `date_time` shows its time in;
  default `None`.
- `depends_on_backend` — whether Telegram's backend, not TDLib, decides if the
  entity survives; default `False`.
- `depends_on_build` — whether the C++ library the server is built with decides
  which of the entities that tie in TDLib's sort survives here, so another build
  may keep another entity with these bounds; default `False`.

## `Refusal`

The pinned Bot API server's refusal of a text.

- `description` — the error description the server returns, such
  as `Bad Request: message is too long`.
- `offset` — the byte offset the description names, in the text as the server
  receives it, or `None` when it names none.

## `Verdict`

The pinned Bot API server's verdict on a text: its refusal, or the text
it keeps.

- `accepted` — whether the server accepts the text.
- `text` — the text the server keeps, or `None` when it refuses the text.
- `entities` — the formatting entities TDLib sends with the kept text, as
  `Entity` values, in the order it sends them; empty for a plain text.
- `refusal` — the server's refusal as a `Refusal`, or `None` when it accepts
  the text.
- `depends_on_backend` — whether Telegram's backend decides if an entity of the
  kept text survives.
- `depends_on_build` — whether the C++ library the server is built with decides
  which entity survives somewhere in the text; default `False`.

## `check`

```python
check(text: str | bytes, *, parse_mode: str | None = None) -> Verdict
```

Runs a bot's message text through the pinned Bot API server's checks and
TDLib's processing.

- `text` — the message text. A `str` stands for what a client sends and is
  encoded as UTF-8, with a surrogate code point kept in its 3-byte form; `bytes`
  stand for the field as the server receives it.
- `parse_mode` — the markup of the text: `HTML`, `MarkdownV2`, or `Markdown` in
  any letter case parses it, and `None`, an empty string, or `none` in any
  letter case parses nothing; any other name gets the server's refusal;
  default `None`.

Returns the `Verdict`. Raises `TypeError` when `text` is neither `str` nor
`bytes`, or `parse_mode` is neither `str` nor `None`.

```pycon
>>> from tdlib_oracle import check
>>> check("Total:\t42 \r\n")
Verdict(accepted=True, text='Total: 42', entities=(), refusal=None, depends_on_backend=False, depends_on_build=False)
>>> check("\N{ZERO WIDTH SPACE}")
Verdict(accepted=False, text=None, entities=(), refusal=Refusal(description='Bad Request: text must be non-empty', offset=None), depends_on_backend=False, depends_on_build=False)
>>> check("<b>Total:</b> 42", parse_mode="HTML").entities
(Entity(type='bold', offset=0, length=6, url=None, user_id=None, language=None, custom_emoji_id=None, unix_time=None, date_time_format=None, depends_on_backend=False, depends_on_build=False),)
>>> check("<b>Total:</i> 42", parse_mode="HTML").refusal
Refusal(description='Bad Request: can\'t parse entities: Unmatched end tag at byte offset 9, expected "</b>", found "</i>"', offset=9)
>>> check("Total: 42.", parse_mode="MarkdownV2").refusal
Refusal(description="Bad Request: can't parse entities: Character '.' is reserved and must be escaped with the preceding '\\'", offset=None)
```

## Constants

- `BOT_API_COMMIT` — the commit of `tdlib/telegram-bot-api` whose verdicts TDLib
  Oracle reproduces.
- `BOT_API_VERSION` — the Bot API release of that commit.
- `TDLIB_COMMIT` — the commit of `tdlib/td` that `BOT_API_COMMIT` builds.
