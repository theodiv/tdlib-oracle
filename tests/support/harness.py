"""The pinned TDLib functions compiled into one program, and runs of that program."""

import hashlib
import os
import platform
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
    """The upstream definition of a data symbol the compiled sources leave undefined."""

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
    # td::verbosity_notifications; VERBOSITY_NAME(INFO) is
    # 3 (tdutils/td/utils/logging.h).
    DataSymbol(
        symbol="_ZN2td23verbosity_notificationsE",
        ctype="int",
        value="3",
        source="td/telegram/NotificationManager.cpp",
        line="int VERBOSITY_NAME(notifications) = VERBOSITY_NAME(INFO);",
    ),
    # td::verbosity_td_requests; VERBOSITY_NAME(INFO) is 3 (tdutils/td/utils/logging.h).
    DataSymbol(
        symbol="_ZN2td21verbosity_td_requestsE",
        ctype="int",
        value="3",
        source="td/telegram/Td.cpp",
        line="int VERBOSITY_NAME(td_requests) = VERBOSITY_NAME(INFO);",
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

#define TD_HAVE_OPENSSL {openssl}
#define TD_HAVE_ZLIB 0
#define TD_HAVE_CRC32C 0
#define TD_HAVE_COROUTINES 0
#define TD_HAVE_ABSL 0
#define TD_FD_DEBUG 0
"""

# tdutils builds without OpenSSL when CMake finds none (tdutils/CMakeLists.txt). Built
# so, crypto.cpp and Slice.cpp need no OpenSSL headers: crypto.cpp still defines
# crc16(), which lies outside its OpenSSL code, and Slice.cpp clears memory with a loop
# of its own in place of OPENSSL_cleanse(); every other source needs no more than
# tdutils' declarations of that code.
_WITHOUT_OPENSSL = ("/tdutils/td/utils/crypto.cpp", "/tdutils/td/utils/Slice.cpp")

# The memory one compile may take, a little above the peak of the heaviest source,
# LinkManager.cpp: under 1 GiB with the Release flags, under 2 GiB with sanitizers.
_COMPILE_MEMORY = 1 << 30
_SANITIZED_COMPILE_MEMORY = 2 << 30

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


def compile_jobs(flags: Sequence[str], meminfo: str) -> int:
    """Return how many sources a build with `flags` compiles at once.

    It gives at least one, and without a `MemAvailable` line the cores alone decide.
    """
    cores = os.cpu_count() or 1
    match = re.search(r"^MemAvailable:\s+(\d+) kB$", meminfo, re.MULTILINE)
    if match is None:
        return cores
    sanitized = any(flag.startswith("-fsanitize") for flag in flags)
    budget = _SANITIZED_COMPILE_MEMORY if sanitized else _COMPILE_MEMORY
    return max(1, min(cores, int(match[1]) * 1024 // budget))


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

    A stand-in value for a data symbol would change what the code does without a sign,
    so a symbol that the demangler cannot read as a function takes the value of its
    entry in `DATA_SYMBOLS`, and one without an entry stops the build.
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
    jobs: int | None = None,
) -> Path:
    """Compile `sources` into one program in `directory`, and return its path.

    The compiler gets only `PATH`, to find the assembler and the linker, and `TMPDIR`,
    so that its temporary files stay in `directory`.
    """
    compiler = _find_compiler()
    env = {"PATH": os.environ.get("PATH", os.defpath), "TMPDIR": str(directory)}
    includes = {}
    for openssl in (0, 1):
        config = directory / f"config-{openssl}"
        (config / "td" / "utils").mkdir(parents=True)
        (config / "td" / "utils" / "config.h").write_text(
            _CONFIG_H.format(openssl=openssl), encoding="ascii"
        )
        includes[openssl] = [f"-I{path}" for path in (*include_dirs, config)]

    if jobs is None:
        try:
            meminfo = Path("/proc/meminfo").read_text(encoding="ascii")
        except OSError:
            meminfo = ""
        jobs = compile_jobs(flags, meminfo)

    objects = directory / "objects"
    objects.mkdir()
    units = [
        (
            source,
            objects / f"{index:03d}-{source.stem}.o",
            includes[0 if source.as_posix().endswith(_WITHOUT_OPENSSL) else 1],
        )
        for index, source in enumerate(sources)
    ]
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        errors = pool.map(
            lambda unit: _compile(compiler, unit[0], unit[1], [*flags, *unit[2]], env),
            units,
        )
        messages = [message for message in errors if message is not None]
    if messages:
        raise HarnessError("\n".join(messages))

    program = directory / "harness"
    compiled = [output for _, output, _ in units]
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


def _fingerprint(
    compiler: str, sources: Sequence[Path], include_dirs: Sequence[Path]
) -> str:
    """Return the key that `cached_build` names the program after.

    The tools run with `PATH` alone, as `build` runs the compiler, so a version text
    translated for the caller's locale leaves the key as it is.
    """
    digest = hashlib.sha256()

    def add(label: str, data: bytes) -> None:
        digest.update(f"{label}\0{len(data)}\0".encode())
        digest.update(data)

    add("harness.py", Path(__file__).read_bytes())
    add("machine", platform.machine().encode())

    # The first include directory that holds a header wins, and the objects link in
    # the order of the sources.
    add("sources", "\0".join(map(str, sources)).encode())
    add("include_dirs", "\0".join(map(str, include_dirs)).encode())

    linker = shutil.which("ld")
    if linker is None:
        raise HarnessError("no ld on PATH; the compiler links the harness with it")

    # ldd reports the version of the C library, whose headers the sources include.
    libc = shutil.which("ldd")
    if libc is None:
        raise HarnessError(
            "no ldd on PATH; the harness reads the C library's version with it"
        )

    env = {"PATH": os.environ.get("PATH", os.defpath)}
    for tool in (compiler, linker, libc):
        version = subprocess.run(
            [tool, "--version"], capture_output=True, check=True, env=env
        )
        add(tool, version.stdout)

    files = set(sources)
    for directory in include_dirs:
        files.update(path for path in directory.rglob("*") if path.is_file())
    for path in sorted(files):
        add(str(path), path.read_bytes())

    return digest.hexdigest()[:16]


def cached_build(
    sources: Sequence[Path],
    include_dirs: Sequence[Path],
    cache: Path,
    scratch: Path,
    *,
    flags: Sequence[str] = (),
    jobs: int | None = None,
) -> Path:
    """Return the program `build` makes of `sources`, from `cache` when it holds one.

    A build takes minutes, yet the program changes only with its inputs, so `cache`
    keeps it under a key over them, which leaves out `jobs`, since the program does not
    depend on it. A build with `flags` is always fresh and leaves `cache` alone, since a
    coverage build writes its counts beside its objects, which a cached program no
    longer has.
    """
    if flags:
        return build(sources, include_dirs, scratch, flags=flags, jobs=jobs)

    key = _fingerprint(_find_compiler(), sources, include_dirs)
    program = cache / f"harness-{key}"
    if program.is_file():
        return program

    built = build(sources, include_dirs, scratch, jobs=jobs)

    # The copy takes a temporary name, so a half-copied program never carries the
    # key's name, and a failed copy leaves nothing behind.
    partial = cache / f"partial-{os.getpid()}"
    try:
        shutil.copy2(built, partial)
        partial.replace(program)
    finally:
        partial.unlink(missing_ok=True)

    for old in cache.glob("harness-*"):
        if old != program:
            old.unlink(missing_ok=True)

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

    The program flushes each response before it reads the next request, so a failure
    names the request it gave no response to.
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
