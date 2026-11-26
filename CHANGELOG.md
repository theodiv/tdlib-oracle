# Changelog

All notable changes to TDLib Oracle are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.3.0] - 2026-11-26

### Added

- Accept `MarkdownV2` and `Markdown`, in any letter case, as the `parse_mode` of
  `check`: an accepted verdict lists the entities TDLib sends, and a refusal of
  the markup names its byte offset when its description does. Previously, both
  raised `ValueError`.

### Changed

- Move the pin to Bot API 10.5: `BOT_API_VERSION` reads `10.5` instead of
  `10.4`, and `BOT_API_COMMIT` and `TDLIB_COMMIT` name the server's commit and
  the TDLib commit it builds; every verdict stays the same.
- Point a release's docs links, in its PyPI description and its `Documentation`
  URL, at its own tag; the installed code and every other link stay the same.
  Previously, they opened the docs on `main`, which can describe features the
  release lacks.

### Fixed

- Show a `pre` entity without a `language` when cleaning removes every character
  of its language, as the Bot API does, such as for
  `<pre><code class="language-&#x202b;">x</code></pre>`. Previously, its
  `language` was an empty string.

## [0.2.0] - 2026-11-23

### Added

- Add the `parse_mode` keyword to `check`: in the HTML parse mode, an accepted
  verdict lists the entities TDLib sends, `depends_on_backend` marking those
  Telegram's backend decides, and a refusal of the markup names its byte offset.
  `Markdown` and `MarkdownV2` raise `ValueError` until a later release.
- Add `depends_on_build` to `Verdict` and `Entity`, which marks an entity that
  the C++ library of the server's build picks from a tie in TDLib's sort.

### Changed

- Ship the package alone in the sdist, with `pyproject.toml`, `README.md`, and
  the license texts; what installs from it stays the same. Previously, it
  carried every file of the repository, the tests included.
- Check a plain message text in about half the time; every verdict stays
  the same.

## [0.1.0] - 2026-11-15

### Added

- Add `check`, which returns the pinned Bot API server's `Verdict` on a plain
  message text: the error description it refuses the text with, or the text it
  keeps after cleaning and trimming. `BOT_API_VERSION`, `BOT_API_COMMIT`, and
  `TDLIB_COMMIT` name the pin.

[Unreleased]: https://github.com/theodiv/tdlib-oracle/compare/v0.3.0...HEAD
[0.3.0]: https://github.com/theodiv/tdlib-oracle/compare/v0.2.0...v0.3.0
[0.2.0]: https://github.com/theodiv/tdlib-oracle/compare/v0.1.0...v0.2.0
[0.1.0]: https://github.com/theodiv/tdlib-oracle/releases/tag/v0.1.0
