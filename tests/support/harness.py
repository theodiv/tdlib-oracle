"""The pinned TDLib functions compiled into one program, and runs of that program.

The pinned sources in `tests/data/` and `harness.cpp` leave many symbols undefined. Each
undefined function becomes a stub that aborts with its name when called. A stand-in
value for a data symbol would change what the code does without a sign, so each
undefined data symbol gets the value upstream gives it, from `DATA_SYMBOLS`, and one
missing there stops the build.
"""

import os
import re
import shutil
import struct
import subprocess
import sys
from collections.abc import Sequence
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
from pathlib import Path


class HarnessError(Exception):
    """Raised when the harness cannot be built, or a run of it fails."""


@dataclass(frozen=True)
class DataSymbol:
    """The upstream definition of a data symbol the compiled sources leave undefined.

    Attributes:
        symbol: The mangled name of the symbol.
        ctype: The C++ type of the symbol.
        value: The value upstream gives the symbol, as a C++ expression.
        source: The file of tdlib/td that defines the symbol.
        line: The line of `source` that defines the symbol, as upstream writes it.
    """

    symbol: str
    ctype: str
    value: str
    source: str
    line: str


DATA_SYMBOLS = (
    # td::verbosity_actor; VERBOSITY_NAME(DEBUG) is 4 (tdutils/td/utils/logging.h).
    DataSymbol(
        symbol="_ZN2td15verbosity_actorE",
        ctype="int",
        value="14",
        source="tdactor/td/actor/impl/Scheduler.cpp",
        line="int VERBOSITY_NAME(actor) = VERBOSITY_NAME(DEBUG) + 10;",
    ),
)

# TDLib's Release flags, and the signed char of x86-64 servers.
_FLAGS = (
    "-std=c++17",
    "-O3",
    "-DNDEBUG",
    "-fno-omit-frame-pointer",
    "-fno-exceptions",
    "-fno-rtti",
    "-fsigned-char",
)

# TDLib's CMake writes td/utils/config.h: TDLib requires OpenSSL, and the Bot API
# server's build leaves every optional library out.
_CONFIG_H = """\
#pragma once

#define TD_HAVE_OPENSSL 1
#define TD_HAVE_ZLIB 0
#define TD_HAVE_CRC32C 0
#define TD_HAVE_COROUTINES 0
#define TD_HAVE_ABSL 0
#define TD_FD_DEBUG 0
"""

_STUBS_HEADER = """\
#include <cstdio>
#include <cstdlib>

namespace {

[[noreturn]] void stub(const char *name) {
  std::fprintf(stderr, "stub called: %s\\n", name);
  std::abort();
}

}  // namespace
"""

# In the C locale, GNU ld quotes an undefined symbol in a backtick and an apostrophe,
# and lld names it after a colon.
_UNDEFINED = re.compile(r"undefined (?:reference to `([^']+)'|symbol: (\S+))")

# A demangled function name ends with its parameter list and any qualifiers.
_FUNCTION = re.compile(r"\)(?: const| volatile| &&| &| noexcept)*$")


def _find_compiler() -> str:
    if sys.platform != "linux":
        raise HarnessError(f"the harness builds on Linux only, not on {sys.platform}")
    compiler = shutil.which("c++")
    if compiler is None:
        raise HarnessError("no c++ on PATH; the harness compiles the pinned sources")
    return compiler


def _compile(
    compiler: str,
    source: Path,
    output: Path,
    arguments: Sequence[str],
    env: dict[str, str],
) -> str | None:
    """Compile `source` into `output`; return the compiler's messages if it fails."""
    result = subprocess.run(
        [compiler, "-c", *_FLAGS, "-pipe", *arguments, "-o", str(output), str(source)],
        capture_output=True,
        check=False,
        encoding="utf-8",
        errors="replace",
        env=env,
    )
    if result.returncode != 0:
        return f"{source} does not compile:\n{result.stderr}"
    return None


def _link(
    compiler: str,
    objects: Sequence[Path],
    program: Path,
    arguments: Sequence[str],
    env: dict[str, str],
) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        [compiler, *arguments, "-pthread", "-o", str(program), *map(str, objects)],
        capture_output=True,
        check=False,
        encoding="utf-8",
        errors="replace",
        env=env,
    )


def _quote(text: str) -> str:
    """Return `text` as a C++ string literal."""
    escaped = text.replace("\\", "\\\\").replace('"', '\\"')
    return f'"{escaped}"'


def _stubs(symbols: Sequence[str], env: dict[str, str]) -> str:
    """Return C++ source that defines each of `symbols` as a stub or as its entry.

    A symbol that the demangler cannot read as a function counts as data, so it needs an
    entry in `DATA_SYMBOLS`.

    Raises:
        HarnessError: If a data symbol has no entry in `DATA_SYMBOLS`.
    """
    demangler = shutil.which("c++filt")
    if demangler is None:
        raise HarnessError("no c++filt on PATH; the harness reads symbols with it")
    names = subprocess.run(
        [demangler],
        input="".join(f"{symbol}\n" for symbol in symbols),
        capture_output=True,
        check=True,
        encoding="utf-8",
        errors="replace",
        env=env,
    ).stdout.splitlines()

    entries = {entry.symbol: entry for entry in DATA_SYMBOLS}
    lines = [_STUBS_HEADER]
    missing = []
    for index, (symbol, name) in enumerate(zip(symbols, names, strict=True)):
        label = _quote(symbol)
        entry = entries.get(symbol)
        if entry is not None:
            lines.append(
                f"{entry.ctype} data_{index} __asm__({label}) = {entry.value};"
            )
        elif symbol.startswith("_Z") and _FUNCTION.search(name):
            lines.append(f"void stub_{index}() __asm__({label});")
            lines.append(f"void stub_{index}() {{ stub({_quote(name)}); }}")
        else:
            missing.append(f"{name} ({symbol})")
    if missing:
        raise HarnessError(
            "data symbols without an entry in DATA_SYMBOLS: " + ", ".join(missing)
        )
    return "\n".join(lines) + "\n"


def build(
    sources: Sequence[Path],
    include_dirs: Sequence[Path],
    directory: Path,
    *,
    flags: Sequence[str] = (),
) -> Path:
    """Compile `sources` into one program in `directory`, and return its path.

    The sources compile in parallel with TDLib's Release flags and `-fsigned-char`, then
    `flags`, such as `--coverage`. A first link names the symbols they leave undefined,
    and their stubs join the second. The compiler gets only `PATH`, to find the
    assembler and the linker, and `TMPDIR`, so that its temporary files stay in
    `directory`.

    Raises:
        HarnessError: If the system is not Linux, `c++` is not on `PATH`, a source does
            not compile, the link fails, or a data symbol has no entry in
            `DATA_SYMBOLS`.
    """
    compiler = _find_compiler()
    env = {"PATH": os.environ.get("PATH", os.defpath), "TMPDIR": str(directory)}
    config = directory / "config" / "td" / "utils"
    config.mkdir(parents=True)
    (config / "config.h").write_text(_CONFIG_H, encoding="ascii")
    includes = [f"-I{path}" for path in (*include_dirs, directory / "config")]

    objects = directory / "objects"
    objects.mkdir()
    jobs = [
        (source, objects / f"{index:03d}-{source.stem}.o")
        for index, source in enumerate(sources)
    ]
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 1) as pool:
        errors = pool.map(
            lambda job: _compile(compiler, job[0], job[1], [*flags, *includes], env),
            jobs,
        )
        messages = [message for message in errors if message is not None]
    if messages:
        raise HarnessError("\n".join(messages))

    program = directory / "harness"
    compiled = [output for _, output in jobs]
    result = _link(compiler, compiled, program, [*flags, "-Wl,--no-demangle"], env)
    if result.returncode == 0:
        return program
    undefined = sorted(
        {match[0] or match[1] for match in _UNDEFINED.findall(result.stderr)}
    )
    if not undefined:
        raise HarnessError(f"the harness does not link:\n{result.stderr}")

    stubs = directory / "stubs.cpp"
    stubs.write_text(_stubs(undefined, env), encoding="utf-8")
    message = _compile(compiler, stubs, objects / "stubs.o", flags, env)
    if message is not None:
        raise HarnessError(message)
    result = _link(compiler, [*compiled, objects / "stubs.o"], program, flags, env)
    if result.returncode != 0:
        raise HarnessError(f"the harness does not link:\n{result.stderr}")
    return program


def _encode(fields: Sequence[bytes]) -> bytes:
    sizes = (struct.pack("<I", len(field)) + field for field in fields)
    return struct.pack("<I", len(fields)) + b"".join(sizes)


def _decode(data: bytes) -> list[tuple[bytes, ...]]:
    """Return the complete responses at the start of `data`."""
    responses: list[tuple[bytes, ...]] = []
    position = 0
    while position + 4 <= len(data):
        (count,) = struct.unpack_from("<I", data, position)
        cursor = position + 4
        fields = []
        for _ in range(count):
            if cursor + 4 > len(data):
                return responses
            (size,) = struct.unpack_from("<I", data, cursor)
            cursor += 4
            if cursor + size > len(data):
                return responses
            fields.append(data[cursor : cursor + size])
            cursor += size
        responses.append(tuple(fields))
        position = cursor
    return responses


def _show(fields: Sequence[bytes]) -> str:
    """Return `fields` for a message, each cut to its first 200 bytes."""
    shown = (
        repr(field) if len(field) <= 200 else f"{field[:200]!r}... ({len(field)} bytes)"
        for field in fields
    )
    return ", ".join(shown)


def _failure(
    function: str,
    requests: Sequence[Sequence[bytes]],
    answered: int,
    reason: str,
    stderr: bytes,
) -> str:
    output = stderr.decode("utf-8", "replace")
    if answered < len(requests):
        return (
            f"{function} gave no response to request {answered} of {len(requests)},"
            f" {_show(requests[answered])}: {reason}\n{output}"
        )
    return f"{function} ended with {reason} after its last response\n{output}"


def run(
    program: Path,
    function: str,
    requests: Sequence[Sequence[bytes]],
    *,
    timeout: float,
) -> list[tuple[bytes, ...]]:
    """Run `function` of `program` on each of `requests`, and return each response.

    The program runs with an empty environment. It flushes each response before it
    reads the next request, so a failure names the request it gave no response to.

    Raises:
        HarnessError: If the program crashes, runs past `timeout` seconds, or exits with
            an error.
    """
    payload = b"".join(_encode(request) for request in requests)
    try:
        result = subprocess.run(
            [str(program), function],
            input=payload,
            capture_output=True,
            check=False,
            env={},
            timeout=timeout,
        )
    except subprocess.TimeoutExpired as error:
        answered = len(_decode(error.stdout or b""))
        reason = f"no response within {timeout:g} s"
        raise HarnessError(
            _failure(function, requests, answered, reason, error.stderr or b"")
        ) from error

    responses = _decode(result.stdout)
    if result.returncode != 0 or len(responses) != len(requests):
        reason = f"exit status {result.returncode}"
        raise HarnessError(
            _failure(function, requests, len(responses), reason, result.stderr)
        )
    return responses
