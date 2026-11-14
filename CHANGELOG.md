# Changelog

All notable changes to TDLib Oracle are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Add `check`, which returns the pinned Bot API server's `Verdict` on a plain
  message text: the error description it refuses the text with, or the text it
  keeps after cleaning and trimming. `BOT_API_VERSION`, `BOT_API_COMMIT`, and
  `TDLIB_COMMIT` name the pin.
