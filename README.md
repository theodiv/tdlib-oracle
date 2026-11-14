# TDLib Oracle

Catch Telegram's refusals and silent edits before sending.

[![License: MIT AND BSL-1.0](https://img.shields.io/badge/dynamic/toml?url=https://raw.githubusercontent.com/theodiv/tdlib-oracle/main/pyproject.toml&query=$.project.license&style=flat-square&label=License&color=yellow)](https://github.com/theodiv/tdlib-oracle/blob/main/LICENSE)
[![Python: 3.11+](https://img.shields.io/python/required-version-toml?tomlFilePath=https://raw.githubusercontent.com/theodiv/tdlib-oracle/main/pyproject.toml&style=flat-square&label=Python)](https://www.python.org/downloads/)
[![CI](https://img.shields.io/github/actions/workflow/status/theodiv/tdlib-oracle/ci.yml?branch=main&style=flat-square&label=CI)](https://github.com/theodiv/tdlib-oracle/actions/workflows/ci.yml)

---

## Status

Pre-release: TDLib Oracle is in development and nothing is published. The first
release is `0.1.0`; the [changelog](https://github.com/theodiv/tdlib-oracle/blob/main/CHANGELOG.md)
records every change until then.

## Overview

TDLib Oracle tells a test whether the Telegram Bot API server would accept a
bot's plain message text and what it would keep, by running the text through the
server's own checks and TDLib's processing, ported from their code at a pinned
Bot API release. It serves the test suites of Telegram bots and of the libraries
that build their messages, with no token and no network request. Sending the
message stays with the caller.

## Features

- **The server's own refusals** — a refused text gets the Bot API's error
  description, word for word, such as `Bad Request: message is too long`.
- **The text Telegram keeps** — an accepted text comes back as the pinned code
  keeps it: `\r` dropped, other control characters turned into spaces, both
  ends trimmed.
- **Pinned to a Bot API release** — each step is ported from the code of the Bot
  API server and TDLib at the commits that `BOT_API_COMMIT` and
  `TDLIB_COMMIT` name.

## Example

```pycon
>>> from tdlib_oracle import check
>>> check("Total:\t42 \r\n").text
'Total: 42'
>>> check("\N{ZERO WIDTH SPACE}").refusal
Refusal(description='Bad Request: text must be non-empty', offset=None)
```

## Requirements

Python 3.11 or later. No runtime dependencies.

## Documentation

- [Library](https://github.com/theodiv/tdlib-oracle/blob/main/docs/library.md) —
  every public name, with its parameters, return value, and exceptions.
- [Behavior](https://github.com/theodiv/tdlib-oracle/blob/main/docs/behavior.md) —
  what happens to the input, step by step, and the limits on it.
- [Compatibility](https://github.com/theodiv/tdlib-oracle/blob/main/docs/compatibility.md) —
  what a release may change, and what stays stable.

## Contributing

Development setup, coding standards, and the pull request process are documented
in the [contributing guide](https://github.com/theodiv/tdlib-oracle/blob/main/CONTRIBUTING.md).

## Code of Conduct

Expectations for every participant are set in the
[code of conduct](https://github.com/theodiv/tdlib-oracle/blob/main/CODE_OF_CONDUCT.md).

## Changelog

Every change is recorded in the [changelog](https://github.com/theodiv/tdlib-oracle/blob/main/CHANGELOG.md).

## Security

The vulnerability reporting and disclosure process is documented in the
[security policy](https://github.com/theodiv/tdlib-oracle/blob/main/SECURITY.md).

---

Distributed under the [MIT License](https://github.com/theodiv/tdlib-oracle/blob/main/LICENSE)
and the [Boost Software License 1.0](https://github.com/theodiv/tdlib-oracle/blob/main/LICENSES/BSL-1.0.txt).
