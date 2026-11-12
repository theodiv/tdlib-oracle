# Security Policy

## Supported Versions

Only the latest released version of TDLib Oracle receives security fixes. Older
releases are not patched.

## Reporting a Vulnerability

Report vulnerabilities privately; never open a public issue for one.

- **GitHub private vulnerability reporting** (preferred): open a draft advisory
  on the [security advisories page](https://github.com/theodiv/tdlib-oracle/security/advisories/new).
- **Email**: `theodiv@gmail.com`.

## Disclosure Process

1. The maintainer acknowledges the report within **72 hours**.
2. The maintainer confirms or declines the report and assesses its severity
   within **7 days** of receiving it.
3. The fix is developed and tested in the advisory's temporary private fork.
4. Disclosure is coordinated with the reporter, targeting **30 days** from
   confirmation; complex issues may take longer.
5. The patched release and the advisory are published together.
6. The advisory credits the reporter unless anonymity is requested.

## Out of Scope

- The behavior of the Telegram Bot API server itself: the requests it accepts
  and the errors it returns. Report it on the
  [telegram-bot-api tracker](https://github.com/tdlib/telegram-bot-api/issues).
- The behavior of TDLib itself: how it parses, fixes, and checks formatted text.
  Report it on the [TDLib tracker](https://github.com/tdlib/td/issues).
- The caller's own files and code: the text, entities, and test suites the
  caller writes.
