import re

import tdlib_oracle
from tdlib_oracle import BOT_API_COMMIT, BOT_API_VERSION, TDLIB_COMMIT, __version__


def test_version_reads_release_or_release_candidate() -> None:
    assert re.fullmatch(r"\d+\.\d+\.\d+(?:rc\d+)?", __version__) is not None


def test_pin_names_a_bot_api_release_and_two_full_commit_hashes() -> None:
    assert re.fullmatch(r"\d+\.\d+", BOT_API_VERSION)
    assert re.fullmatch(r"[0-9a-f]{40}", BOT_API_COMMIT)
    assert re.fullmatch(r"[0-9a-f]{40}", TDLIB_COMMIT)


def test_all_names_exactly_the_public_surface() -> None:
    assert tdlib_oracle.__all__ == [
        "BOT_API_COMMIT",
        "BOT_API_VERSION",
        "TDLIB_COMMIT",
        "Entity",
        "Refusal",
        "Verdict",
        "check",
    ]
    assert all(hasattr(tdlib_oracle, name) for name in tdlib_oracle.__all__)
