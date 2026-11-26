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

__version__ = "0.3.0"
BOT_API_VERSION = "10.5"
BOT_API_COMMIT = "5df614c91dab8662cfbb24a501ec89949fdcfebb"
TDLIB_COMMIT = "f10611ee1f03f91ddae8185483a1ccfd3d664668"

__all__ = [
    "BOT_API_COMMIT",
    "BOT_API_VERSION",
    "TDLIB_COMMIT",
    "Entity",
    "Refusal",
    "Verdict",
    "check",
]
