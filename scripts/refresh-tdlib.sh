#!/usr/bin/env bash
#
# Rewrites tests/data/td/ and tests/data/tl/ from a tdlib/td checkout at
# TDLIB_COMMIT, so the differential tests compile the pinned code: the
# translation units below, every file they and tests/support/harness.cpp
# include, and the TL sources that TDLib's generator writes. Run it at each
# re-pin, from the repository root; it reaches no network.
set -euo pipefail

td=${1:?usage: scripts/refresh-tdlib.sh <td checkout>}
td=$(cd "$td" && pwd)

init=src/tdlib_oracle/__init__.py
commit=$(sed -n 's/^TDLIB_COMMIT = "\(.*\)"$/\1/p' "$init")
if [ -z "$commit" ]; then
  echo "error: $init holds no TDLIB_COMMIT line" >&2
  exit 1
fi
if [ "$(git -C "$td" rev-parse HEAD)" != "$commit" ]; then
  echo "error: $td is not at TDLIB_COMMIT $commit" >&2
  exit 1
fi
if [ -n "$(git -C "$td" status --porcelain --untracked-files=no)" ]; then
  echo "error: $td has local changes" >&2
  exit 1
fi

# The translation units the harness compiles: the code that the plain-text path,
# entity fixing, and entity finding run, and every tdutils source that defines
# a symbol they reference, so no tdutils function they call is ever a stub.
# Sources that need the OpenSSL headers stay out, except crypto.cpp, which the
# harness compiles without OpenSSL for crc16().
units=(
  td/telegram/FormattedDate.cpp
  td/telegram/MessageEntity.cpp
  td/telegram/misc.cpp
  td/telegram/TonWalletManager.cpp
  tdutils/td/utils/base64.cpp
  tdutils/td/utils/buffer.cpp
  tdutils/td/utils/check.cpp
  tdutils/td/utils/crypto.cpp
  tdutils/td/utils/ExitGuard.cpp
  tdutils/td/utils/FlatHashTable.cpp
  tdutils/td/utils/Hints.cpp
  tdutils/td/utils/logging.cpp
  tdutils/td/utils/misc.cpp
  tdutils/td/utils/port/Clocks.cpp
  tdutils/td/utils/port/detail/NativeFd.cpp
  tdutils/td/utils/port/FileFd.cpp
  tdutils/td/utils/port/PollFlags.cpp
  tdutils/td/utils/port/sleep.cpp
  tdutils/td/utils/port/Stat.cpp
  tdutils/td/utils/port/StdStreams.cpp
  tdutils/td/utils/port/thread_local.cpp
  tdutils/td/utils/StackAllocator.cpp
  tdutils/td/utils/Status.cpp
  tdutils/td/utils/StringBuilder.cpp
  tdutils/td/utils/Time.cpp
  tdutils/td/utils/translit.cpp
  tdutils/td/utils/TsCerr.cpp
  tdutils/td/utils/unicode.cpp
  tdutils/td/utils/utf8.cpp
)
# The generated TL sources define the virtual tables of the TL classes that
# the units above use, which no stand-in could give.
generated_units=(
  td/telegram/secret_api.cpp
  td/telegram/td_api_0.cpp
  td/telegram/td_api_1.cpp
  td/telegram/td_api_2.cpp
  td/telegram/td_api_3.cpp
  td/telegram/td_api_4.cpp
  td/telegram/td_api_5.cpp
  td/telegram/td_api_6.cpp
  td/telegram/td_api_7.cpp
  td/telegram/td_api_8.cpp
  td/telegram/td_api_9.cpp
  td/telegram/telegram_api_0.cpp
  td/telegram/telegram_api_1.cpp
  td/telegram/telegram_api_2.cpp
  td/telegram/telegram_api_3.cpp
  td/telegram/telegram_api_4.cpp
  td/telegram/telegram_api_5.cpp
  td/telegram/telegram_api_6.cpp
  td/telegram/telegram_api_7.cpp
  td/telegram/telegram_api_8.cpp
  td/telegram/telegram_api_9.cpp
)

tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

# tl-parser turns each TL scheme into a .tlo file, and generate_common writes
# the C++ sources from those, as TDLib's CMake build does.
gen=$td/td/generate
cc -O2 -o "$tmp/tl-parser" "$gen/tl-parser/crc32.c" "$gen/tl-parser/tlc.c" \
  "$gen/tl-parser/tl-parser.c" -lm
c++ -O2 -std=c++17 -I"$td/tdtl" -I"$gen" -o "$tmp/generate_common" \
  "$gen/generate_common.cpp" "$gen/tl_writer_cpp.cpp" "$gen/tl_writer_h.cpp" \
  "$gen/tl_writer_hpp.cpp" "$gen/tl_writer_jni_cpp.cpp" \
  "$gen/tl_writer_jni_h.cpp" "$gen/tl_writer_td.cpp" "$td"/tdtl/td/tl/*.cpp
auto=$tmp/auto
mkdir -p "$auto/tlo" "$auto/td/telegram"
for scheme in telegram_api secret_api e2e_api td_api; do
  "$tmp/tl-parser" -e "$auto/tlo/$scheme.tlo" "$gen/scheme/$scheme.tl"
done
# generate_common names each file it writes on stderr, so its output is shown
# only when it fails.
log=$tmp/generate_common.log
if ! (cd "$auto" && "$tmp/generate_common") > "$log" 2>&1; then
  cat "$log" >&2
  exit 1
fi

# td/utils/config.h comes from TDLib's CMake, so -MG lists it without reading
# it; the harness writes its own.
includes=(-I"$td" -I"$auto")
for component in tdutils tdactor tdnet tddb tdtl tde2e; do
  includes+=(-I"$td/$component")
done
sources=("${units[@]/#/$td/}" "${generated_units[@]/#/$auto/}"
  tests/support/harness.cpp)
: > "$tmp/files"
for source in "${sources[@]}"; do
  c++ -std=c++17 -MM -MG "${includes[@]}" "$source" |
    sed 's/\\$//' | tr ' ' '\n' | grep -v -e ':$' -e '^$' >> "$tmp/files"
done

rm -rf tests/data/td tests/data/tl
mkdir -p tests/data/td tests/data/tl
sort -u "$tmp/files" | while read -r file; do
  case $file in
    "$td"/*) target=tests/data/td/${file#"$td"/} ;;
    "$auto"/*) target=tests/data/tl/${file#"$auto"/} ;;
    *) continue ;;
  esac
  mkdir -p "$(dirname "$target")"
  cp "$file" "$target"
  chmod 644 "$target"
done
printf '%s\n' "$commit" > tests/data/td/COMMIT
