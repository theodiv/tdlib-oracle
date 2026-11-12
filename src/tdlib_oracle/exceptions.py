"""Exception hierarchy rooted at `TDLibOracleError`."""


class TDLibOracleError(Exception):
    """Root of the exceptions the package defines.

    Each exception class the package defines derives from it, so one `except` clause
    catches them all.
    """
