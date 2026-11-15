#!/usr/bin/env bash
#
# upstream-pin.yml runs this each week, so a telegram-bot-api commit newer than
# BOT_API_COMMIT, or a td submodule other than TDLIB_COMMIT, fails the run
# instead of going unnoticed. In CI, gh reads the GitHub API with GH_TOKEN.
set -euo pipefail

init=src/tdlib_oracle/__init__.py
bot_api=$(sed -n 's/^BOT_API_COMMIT = "\(.*\)"$/\1/p' "$init")
tdlib=$(sed -n 's/^TDLIB_COMMIT = "\(.*\)"$/\1/p' "$init")
if [ -z "$bot_api" ] || [ -z "$tdlib" ]; then
  echo "::error::$init holds no BOT_API_COMMIT or TDLIB_COMMIT line"
  exit 1
fi

# td is read at the commit just returned, so a push between the two requests
# cannot pair one commit with another's submodule.
newest=$(gh api repos/tdlib/telegram-bot-api/commits/HEAD --jq .sha)
td=$(gh api "repos/tdlib/telegram-bot-api/contents/td?ref=$newest" --jq .sha)

status=0
if [ "$bot_api" != "$newest" ]; then
  echo "::error::BOT_API_COMMIT is $bot_api; telegram-bot-api's newest commit is $newest"
  status=1
fi
if [ "$tdlib" != "$td" ]; then
  echo "::error::TDLIB_COMMIT is $tdlib; the td submodule of $newest is $td"
  status=1
fi
exit "$status"
