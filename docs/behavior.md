# Behavior

TDLib Oracle runs a bot's plain message text through the steps that the Telegram
Bot API server and TDLib take before the message is sent, ported from their code
at the commits that `BOT_API_COMMIT` and `TDLIB_COMMIT` name. The result is the
verdict: the server's refusal, or the text it keeps. Everything else links here
for what a result means.

## Processing

The steps run in this order:

| #   | Step                                                                                                                                                                                                                                         | Result                                                   |
| --- | ---                                                                                                                                                                                                                                          | ---                                                      |
| 1   | Encoding: a `str` becomes UTF-8, a surrogate code point in its 3-byte form; `bytes` stay as they are                                                                                                                                         | The text as the server receives it                       |
| 2   | Bot API server: the text is empty                                                                                                                                                                                                            | Refused: `Bad Request: message text is empty`            |
| 3   | Bot API server: the text is over 32,768 bytes                                                                                                                                                                                                | Refused: `Bad Request: text is too long`                 |
| 4   | TDLib: the text is not valid UTF-8                                                                                                                                                                                                           | Refused: `Bad Request: strings must be encoded in UTF-8` |
| 5   | TDLib cleans the text: `\r`, U+2028 to U+202E, and the combining marks U+030A, U+0333, and U+033F are dropped; every other control character but `\n` becomes a space; in a run of U+200E and U+200F marks, each but the last becomes U+200C | The cleaned text                                         |
| 6   | TDLib: nothing but spaces and line feeds is left                                                                                                                                                                                             | Refused: `Bad Request: text must be non-empty`           |
| 7   | TDLib trims spaces and line feeds from both ends                                                                                                                                                                                             | The kept text                                            |
| 8   | TDLib: nothing but blank characters is left: spaces, line feeds, U+00A0, U+1680, U+180E, U+2000 to U+200F, U+202F, U+205F, U+2800, U+3000, U+FEFF, U+FFFC, and the tag characters U+E0000 to U+E007F                                         | Refused: `Bad Request: text must be non-empty`           |
| 9   | TDLib: the kept text is over 4,096 code points                                                                                                                                                                                               | Refused: `Bad Request: message is too long`              |

## Limits

| Limit                                | Value             | Past it                                     |
| ---                                  | ---               | ---                                         |
| Text size, as the server receives it | 32,768 bytes      | Refused: `Bad Request: text is too long`    |
| Length of the kept text              | 4,096 code points | Refused: `Bad Request: message is too long` |

## Guarantees

- `check` returns a verdict for every `str` or `bytes` text, malformed or not,
  and raises `TypeError` for any other type.
- A verdict is the pinned code's answer. TDLib's own tests of its cleaning,
  trimming, and UTF-8 check pass against TDLib Oracle.
- `check` sends nothing over the network and needs no token.
- Time and memory grow linearly with the length of the text.

Threats and how to report them: [`SECURITY.md`](../SECURITY.md).

## Out of Scope

- Sending the message or any other network access — the caller's own Bot API
  client sends it.
- Conversion from other formats into Telegram markup — the caller's formatter
  produces the text that `check` takes.
- The rules Telegram's backend applies after TDLib, its limit values included —
  a send to Telegram itself meets them.
- User accounts, whose limits and entity handling differ from a bot's — a user
  client built on TDLib gets TDLib's answer directly.
