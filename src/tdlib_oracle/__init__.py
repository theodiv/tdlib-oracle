"""Telegram Bot API message validator for HTML and MarkdownV2, ported from TDLib.

Public surface
--------------
- `check`: the pinned Bot API server's verdict on a bot's message text.
- `Verdict`: what `check` returns: the server's refusal, or the text it keeps.
- `Refusal`: the error description the server refuses a text with.
- `Entity`: a formatting entity of the kept text, in the Bot API's form.
- `BOT_API_VERSION`: the Bot API release whose server the verdicts reproduce.
- `BOT_API_COMMIT`: the pinned commit of `tdlib/telegram-bot-api`.
- `TDLIB_COMMIT`: the pinned commit of `tdlib/td`.
"""

from tdlib_oracle.server import Entity, Refusal, Verdict, check

__version__ = "0.0.0"
BOT_API_VERSION = "10.4"
BOT_API_COMMIT = "7232881b39dfcd048a0d569f1983c5184249ee05"
TDLIB_COMMIT = "c8828d50f5eac2fc7089ce1089d7ce9095c61b5e"

__all__ = [
    "BOT_API_COMMIT",
    "BOT_API_VERSION",
    "TDLIB_COMMIT",
    "Entity",
    "Refusal",
    "Verdict",
    "check",
]
