import pytest


def pytest_addoption(parser: pytest.Parser) -> None:
    """Register the options of the differential tests."""
    group = parser.getgroup("differential", "differential tests")
    group.addoption(
        "--harness-flags",
        default="",
        help="compiler flags appended to the harness build, such as '--coverage -O0'",
    )
    group.addoption(
        "--harness-jobs",
        type=int,
        default=None,
        help="sources the harness build compiles at once"
        " (default: what the cores and the available memory allow)",
    )
    group.addoption(
        "--differential-seed",
        type=int,
        default=None,
        help="draw the generated texts from this seed instead of the fixed seeds",
    )
    group.addoption(
        "--differential-count",
        type=int,
        default=10_000,
        help="number of texts drawn from each seed (default: 10000)",
    )
