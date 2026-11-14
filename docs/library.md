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

## `Refusal`

The pinned Bot API server's refusal of a text.

- `description` — the error description the server returns, such
  as `Bad Request: message is too long`.
- `offset` — the byte offset the description names, or `None` when it
  names none.

## `Verdict`

The pinned Bot API server's verdict on a text: its refusal, or the text
it keeps.

- `accepted` — whether the server accepts the text.
- `text` — the text the server keeps, or `None` when it refuses the text.
- `entities` — the formatting entities of the kept text, as `Entity` values;
  empty, since a plain text carries none.
- `refusal` — the server's refusal as a `Refusal`, or `None` when it accepts
  the text.
- `depends_on_backend` — whether Telegram's backend decides if an entity of the
  kept text survives.

## `check`

```python
check(text: str | bytes) -> Verdict
```

Runs a bot's message text through the pinned Bot API server's checks and
TDLib's processing.

- `text` — the message text. A `str` stands for what a client sends and is
  encoded as UTF-8, with a surrogate code point kept in its 3-byte form; `bytes`
  stand for the field as the server receives it.

Returns the `Verdict`. Raises `TypeError` when `text` is neither `str`
nor `bytes`.

```pycon
>>> from tdlib_oracle import check
>>> check("Total:\t42 \r\n")
Verdict(accepted=True, text='Total: 42', entities=(), refusal=None, depends_on_backend=False)
>>> check("\N{ZERO WIDTH SPACE}")
Verdict(accepted=False, text=None, entities=(), refusal=Refusal(description='Bad Request: text must be non-empty', offset=None), depends_on_backend=False)
```

## Constants

- `BOT_API_COMMIT` — the commit of `tdlib/telegram-bot-api` whose verdicts TDLib
  Oracle reproduces.
- `BOT_API_VERSION` — the Bot API release of that commit.
- `TDLIB_COMMIT` — the commit of `tdlib/td` that `BOT_API_COMMIT` builds.
