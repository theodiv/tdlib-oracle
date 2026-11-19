import shlex
from collections.abc import Callable, Sequence
from pathlib import Path

import pytest

from tests.support.harness import cached_build, run
from tests.support.texts import shrink

# The port's result for a text and the function's other arguments, in the fields the
# harness answers with.
Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]

# A text, as a tuple of units, and the function's other arguments.
Case = tuple[tuple[bytes, ...], tuple[int, ...]]

_FIXED_SEEDS = (20261116, 20261117)

# Generous enough for a build with --coverage or the sanitizers; a run of the plain
# build takes seconds.
_TIMEOUT = 300.0


@pytest.fixture(scope="session")
def harness(
    pytestconfig: pytest.Config, tmp_path_factory: pytest.TempPathFactory
) -> Path:
    """Return the compiled pinned TDLib functions.

    A build without `--harness-flags` is kept in `.pytest_cache/` until one of its
    inputs changes or `pytest --cache-clear` empties the cache, so later sessions
    skip it.
    """
    root = pytestconfig.rootpath
    td = root / "tests" / "data" / "td"
    tl = root / "tests" / "data" / "tl"
    sources = [
        *sorted(td.rglob("*.cpp")),
        *sorted(tl.rglob("*.cpp")),
        root / "tests" / "support" / "harness.cpp",
    ]
    # Each component of td other than td itself keeps its headers in a td/ directory.
    components = sorted(path for path in td.iterdir() if (path / "td").is_dir())
    flags = shlex.split(pytestconfig.getoption("harness_flags"))
    return cached_build(
        sources,
        [td, *components, tl],
        pytestconfig.cache.mkdir("harness"),
        tmp_path_factory.mktemp("harness"),
        flags=flags,
    )


@pytest.fixture
def seeds(pytestconfig: pytest.Config) -> tuple[int, ...]:
    """Return the seeds to draw texts from: `--differential-seed`, or the fixed ones."""
    seed: int | None = pytestconfig.getoption("differential_seed")
    return _FIXED_SEEDS if seed is None else (seed,)


@pytest.fixture
def count(pytestconfig: pytest.Config) -> int:
    """Return the number of texts to draw from each seed, `--differential-count`."""
    value: int = pytestconfig.getoption("differential_count")
    return value


def _pinned(
    harness: Path, function: str, cases: Sequence[tuple[bytes, tuple[int, ...]]]
) -> list[tuple[bytes, ...]]:
    requests = [[text, *(str(arg).encode() for arg in args)] for text, args in cases]
    return run(harness, function, requests, timeout=_TIMEOUT)


def _shrink_case(
    harness: Path,
    function: str,
    port: Port,
    units: tuple[bytes, ...],
    args: tuple[int, ...],
    *,
    by_bytes: bool,
) -> Case:
    def fails(candidates: list[tuple[bytes, ...]]) -> list[bool]:
        texts = [b"".join(candidate) for candidate in candidates]
        pinned = _pinned(harness, function, [(text, args) for text in texts])
        return [
            port(text, args) != result
            for text, result in zip(texts, pinned, strict=True)
        ]

    units = shrink(units, fails, by_bytes=by_bytes)
    text = b"".join(units)
    for position in range(len(args)):
        while args[position] > 0:
            values = sorted({0, args[position] // 2, args[position] - 1})
            candidates = [
                (*args[:position], value, *args[position + 1 :]) for value in values
            ]
            pinned = _pinned(harness, function, [(text, other) for other in candidates])
            smaller = [
                other
                for other, result in zip(candidates, pinned, strict=True)
                if port(text, other) != result
            ]
            if not smaller:
                break
            args = smaller[0]
    return units, args


@pytest.fixture
def compare(harness: Path) -> Callable[..., None]:
    """Return a check that the port gives the pinned code's result on each case.

    A differing case is shrunk before it fails the test, its text and then its numeric
    arguments, so the failure shows the smallest case found that still differs.
    """

    def check(
        function: str,
        port: Port,
        cases: Sequence[Case],
        *,
        seed: int | None,
        by_bytes: bool,
    ) -> None:
        texts = [(b"".join(units), args) for units, args in cases]
        pinned = _pinned(harness, function, texts)
        for index, ((units, args), result) in enumerate(
            zip(cases, pinned, strict=True)
        ):
            if port(b"".join(units), args) == result:
                continue
            small_units, small_args = _shrink_case(
                harness, function, port, units, args, by_bytes=by_bytes
            )
            text = b"".join(small_units)
            (shrunk,) = _pinned(harness, function, [(text, small_args)])
            origin = "a fixed case" if seed is None else f"seed {seed}"
            pytest.fail(
                f"{function} differs on {origin}, case {index}, shrunk to {text!r}"
                f" with arguments {small_args}: the port gives"
                f" {port(text, small_args)!r}, the pinned code {shrunk!r}"
            )

    return check
