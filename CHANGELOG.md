# Changelog

All notable changes to TDLib Oracle are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed

- Include in the sdist the TDLib sources that the differential tests compile,
  under BSL-1.0.

## [0.1.0] - 2026-11-15

### Added

- Add `check`, which returns the pinned Bot API server's `Verdict` on a plain
  message text: the error description it refuses the text with, or the text it
  keeps after cleaning and trimming. `BOT_API_VERSION`, `BOT_API_COMMIT`, and
  `TDLIB_COMMIT` name the pin.

[Unreleased]: https://github.com/theodiv/tdlib-oracle/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/theodiv/tdlib-oracle/releases/tag/v0.1.0
