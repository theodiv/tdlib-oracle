import errno
import os
import re
import sys
from collections.abc import Sequence
from pathlib import Path

import pytest

from tests.support.harness import HarnessError, build, cached_build, run

pytestmark = pytest.mark.differential

# Answers each request with its first field, except three: "crash" calls a function
# that nothing defines, "hang" sleeps for an hour, and "verbosity" asks for the value of
# a data symbol that nothing defines either.
_ECHO = r"""
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <string>
#include <thread>
#include <vector>

namespace td {
extern int verbosity_actor;
}
void missing_function(int);

static bool read_size(std::uint32_t &size) {
  unsigned char bytes[4];
  if (std::fread(bytes, 1, 4, stdin) != 4) {
    return false;
  }
  size = bytes[0] | bytes[1] << 8 | bytes[2] << 16 | std::uint32_t{bytes[3]} << 24;
  return true;
}

static void write_size(std::uint32_t size) {
  unsigned char bytes[4];
  for (int i = 0; i < 4; i++) {
    bytes[i] = static_cast<unsigned char>(size >> (8 * i));
  }
  std::fwrite(bytes, 1, 4, stdout);
}

int main() {
  std::uint32_t count;
  while (read_size(count)) {
    std::vector<std::string> fields(count);
    for (auto &field : fields) {
      std::uint32_t size;
      read_size(size);
      field.resize(size);
      std::fread(&field[0], 1, size, stdin);
    }
    auto answer = fields[0];
    if (answer == "crash") {
      missing_function(1);
    }
    if (answer == "hang") {
      std::this_thread::sleep_for(std::chrono::hours(1));
    }
    if (answer == "verbosity") {
      answer = std::to_string(td::verbosity_actor);
    }
    write_size(1);
    write_size(answer.size());
    std::fwrite(answer.data(), 1, answer.size(), stdout);
    std::fflush(stdout);
  }
}
"""


def _build(directory: Path, source: str) -> Path:
    path = directory / "program.cpp"
    path.write_text(source, encoding="utf-8")
    output = directory / "build"
    output.mkdir()
    return build([path], [], output)


def _write(path: Path, text: str) -> Path:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path


def _directory(path: Path) -> Path:
    path.mkdir()
    return path


def _entries(directory: Path) -> list[str]:
    return sorted(path.name for path in directory.iterdir())


def _write_tool(path: Path, version: str) -> None:
    descriptor = os.open(path, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o700)
    os.fchmod(descriptor, 0o700)
    with open(descriptor, "w", encoding="utf-8") as tool:
        tool.write(f"#!/bin/sh\necho '{version}'\n")


# Writes the bytes of the sources as the program, except for a source that holds
# "broken", which fails as a source that does not compile.
def _fake_build(
    sources: Sequence[Path],
    include_dirs: Sequence[Path],
    directory: Path,
    *,
    flags: Sequence[str] = (),
) -> Path:
    text = b"".join(source.read_bytes() for source in sources)
    if b"broken" in text:
        raise HarnessError("program.cpp does not compile")

    program = directory / "harness"
    program.write_bytes(text)
    return program


# A c++, an ld, and an ldd that only print their versions, which a test can change, and
# a build that compiles nothing.
@pytest.fixture
def fake_toolchain(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> Path:
    tools = _directory(tmp_path / "bin")
    _write_tool(tools / "c++", "c++ 1.0")
    _write_tool(tools / "ld", "ld 1.0")
    _write_tool(tools / "ldd", "ldd 1.0")
    monkeypatch.setenv("PATH", str(tools))
    monkeypatch.setattr("tests.support.harness.build", _fake_build)
    return tools


def test_an_undefined_data_symbol_gets_the_value_its_entry_states(
    tmp_path: Path,
) -> None:
    program = _build(tmp_path, _ECHO)
    assert run(program, "echo", [[b"verbosity"], [b"a"]], timeout=60) == [
        (b"14",),
        (b"a",),
    ]


def test_a_called_stub_aborts_and_the_failure_names_its_function_and_request(
    tmp_path: Path,
) -> None:
    program = _build(tmp_path, _ECHO)
    with pytest.raises(HarnessError) as raised:
        run(program, "echo", [[b"a"], [b"crash"], [b"b"]], timeout=60)
    message = str(raised.value)
    assert "no response to request 1 of 3, b'crash'" in message
    assert "stub called: missing_function(int)" in message


def test_a_request_that_runs_past_the_timeout_is_named(tmp_path: Path) -> None:
    program = _build(tmp_path, _ECHO)
    with pytest.raises(HarnessError, match=r"request 1 of 2, b'hang': no response"):
        run(program, "echo", [[b"a"], [b"hang"]], timeout=2)


def test_a_data_symbol_without_an_entry_stops_the_build(tmp_path: Path) -> None:
    source = "namespace td { extern int missing_value; }\n"
    source += "int main() { return td::missing_value; }\n"
    named = (
        r"without an entry in DATA_SYMBOLS: "
        r"td::missing_value \(_ZN2td13missing_valueE\)"
    )
    with pytest.raises(HarnessError, match=named):
        _build(tmp_path, source)


def test_a_source_that_does_not_compile_stops_the_build(tmp_path: Path) -> None:
    with pytest.raises(HarnessError, match=r"program\.cpp does not compile"):
        _build(tmp_path, "int main( {\n")


def test_the_build_names_a_missing_compiler(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    monkeypatch.setattr("tests.support.harness.shutil.which", lambda name: None)
    with pytest.raises(HarnessError, match=r"^no c\+\+ on PATH"):
        _build(tmp_path, _ECHO)


def test_the_build_names_a_system_other_than_linux(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    monkeypatch.setattr(sys, "platform", "darwin")
    with pytest.raises(HarnessError, match=r"on Linux only, not on darwin$"):
        _build(tmp_path, _ECHO)


def test_the_same_inputs_reuse_the_cached_program_without_building(
    tmp_path: Path,
) -> None:
    source = _write(tmp_path / "program.cpp", _ECHO)
    cache = _directory(tmp_path / "cache")
    first = cached_build([source], [], cache, _directory(tmp_path / "scratch0"))

    scratch = _directory(tmp_path / "scratch1")
    program = cached_build([source], [], cache, scratch)
    assert program == first
    assert program.parent == cache
    assert re.fullmatch(r"harness-[0-9a-f]{16}", program.name)
    assert _entries(scratch) == []
    assert run(program, "echo", [[b"a"]], timeout=60) == [(b"a",)]


@pytest.mark.parametrize(
    "changed",
    ["source", "header", "source-order", "include-order", "compiler", "linker", "libc"],
)
def test_a_changed_input_builds_again_and_replaces_the_cached_program(
    tmp_path: Path, fake_toolchain: Path, changed: str
) -> None:
    sources = [
        _write(tmp_path / "main.cpp", "int main() {}\n"),
        _write(tmp_path / "other.cpp", "int other() { return 0; }\n"),
    ]
    # Both directories hold td/config.h, so their order decides which one a build reads.
    include_dirs = [tmp_path / "include", tmp_path / "config"]
    header = _write(include_dirs[0] / "td" / "config.h", "#define VALUE 1\n")
    _write(include_dirs[1] / "td" / "config.h", "#define VALUE 2\n")
    cache = _directory(tmp_path / "cache")
    first = cached_build(
        sources, include_dirs, cache, _directory(tmp_path / "scratch0")
    )

    match changed:
        case "source":
            _write(sources[0], "int main() { return 1; }\n")
        case "header":
            _write(header, "#define VALUE 3\n")
        case "source-order":
            sources.reverse()
        case "include-order":
            include_dirs.reverse()
        case "compiler":
            _write_tool(fake_toolchain / "c++", "c++ 2.0")
        case "linker":
            _write_tool(fake_toolchain / "ld", "ld 2.0")
        case "libc":
            _write_tool(fake_toolchain / "ldd", "ldd 2.0")

    scratch = _directory(tmp_path / "scratch1")
    program = cached_build(sources, include_dirs, cache, scratch)
    assert program != first
    assert _entries(scratch) == ["harness"]
    assert program.read_bytes() == (scratch / "harness").read_bytes()
    assert _entries(cache) == [program.name]


@pytest.mark.usefixtures("fake_toolchain")
def test_a_build_with_flags_is_always_fresh_and_leaves_the_cache_alone(
    tmp_path: Path,
) -> None:
    source = _write(tmp_path / "program.cpp", "int main() {}\n")
    cache = _directory(tmp_path / "cache")
    cached = cached_build([source], [], cache, _directory(tmp_path / "scratch"))
    inode = cached.stat().st_ino

    for index in range(2):
        scratch = _directory(tmp_path / f"coverage{index}")
        program = cached_build([source], [], cache, scratch, flags=["--coverage"])
        assert program.parent == scratch
    assert _entries(cache) == [cached.name]
    assert cached.stat().st_ino == inode


@pytest.mark.usefixtures("fake_toolchain")
def test_a_failed_build_leaves_the_cache_as_it_was(tmp_path: Path) -> None:
    source = _write(tmp_path / "program.cpp", "int main() {}\n")
    cache = _directory(tmp_path / "cache")
    cached = cached_build([source], [], cache, _directory(tmp_path / "scratch0"))
    inode = cached.stat().st_ino

    _write(source, "broken\n")
    with pytest.raises(HarnessError, match=r"does not compile"):
        cached_build([source], [], cache, _directory(tmp_path / "scratch1"))
    assert _entries(cache) == [cached.name]
    assert cached.stat().st_ino == inode


@pytest.mark.usefixtures("fake_toolchain")
def test_a_copy_that_fails_partway_leaves_no_temporary_file(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    def copy_half(source: Path, destination: Path) -> None:
        data = source.read_bytes()
        destination.write_bytes(data[: len(data) // 2])
        raise OSError(errno.ENOSPC, os.strerror(errno.ENOSPC))

    monkeypatch.setattr("tests.support.harness.shutil.copy2", copy_half)
    source = _write(tmp_path / "program.cpp", "int main() {}\n")
    cache = _directory(tmp_path / "cache")
    with pytest.raises(OSError, match=os.strerror(errno.ENOSPC)):
        cached_build([source], [], cache, _directory(tmp_path / "scratch"))
    assert _entries(cache) == []


@pytest.mark.parametrize("tool", ["ld", "ldd"])
def test_the_cached_build_names_a_missing_tool(
    tmp_path: Path, fake_toolchain: Path, tool: str
) -> None:
    (fake_toolchain / tool).unlink()
    source = _write(tmp_path / "program.cpp", "int main() {}\n")
    cache = _directory(tmp_path / "cache")
    with pytest.raises(HarnessError, match=rf"^no {tool} on PATH"):
        cached_build([source], [], cache, _directory(tmp_path / "scratch"))
