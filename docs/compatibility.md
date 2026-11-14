# Compatibility

What callers can rely on across releases.

## Versioning

Releases follow Semantic Versioning. Before 1.0.0, a minor release may break a
covered surface, and its changelog entry says so with **Breaking:**; a patch
release never breaks. From 1.0.0, only a major release breaks, after a minor
release has deprecated what it removes: the old form keeps working and warns,
naming its replacement and the release that removes it. A security fix may break
a surface in a patch release, and its changelog entry names the old and the
new behavior.

## What Is Covered

- Every name in `tdlib_oracle.__all__`, with its parameters and return values.
- The behavior these pages describe.

## What Is Not Covered

- Names that start with `_`, and behavior these pages do not describe.
- The wording of exception messages.
- Development releases (`.devN`) and release candidates (`rcN`).

## Verdicts

Verdicts follow the pin. A release that moves `BOT_API_COMMIT` and
`TDLIB_COMMIT` to a newer Bot API server may change any verdict; it is a minor
release, and its changelog lists each change. A verdict that moves toward the
pinned code's answer is a fix, in a patch release.

## Python Versions

TDLib Oracle supports Python 3.11 through 3.15. A minor release may drop a
Python version after its end of life, and its changelog entry names it.
