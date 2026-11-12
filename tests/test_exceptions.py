from tdlib_oracle.exceptions import TDLibOracleError


def test_root_error_is_an_exception_but_not_an_argument_error() -> None:
    assert issubclass(TDLibOracleError, Exception)
    assert not issubclass(TDLibOracleError, (TypeError, ValueError))
