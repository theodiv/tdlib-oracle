import sys
from pathlib import Path

import pytest

from tests.support.harness import HarnessError, build, run

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
