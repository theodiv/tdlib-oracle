import ast
from pathlib import Path

import pytest

from tdlib_oracle.tdlib import message_entity

_PACKAGE = "tdlib_oracle.tdlib.message_entity"


def _imported_modules(path: Path) -> list[str]:
    modules = []
    for node in ast.walk(ast.parse(path.read_bytes())):
        if isinstance(node, ast.ImportFrom) and node.module:
            modules.append(node.module)
        elif isinstance(node, ast.Import):
            modules.extend(alias.name for alias in node.names)
    return modules


def test_all_lists_exactly_the_names_the_package_imports(
    pytestconfig: pytest.Config,
) -> None:
    init = pytestconfig.rootpath / "src" / "tdlib_oracle" / "tdlib" / "message_entity"
    tree = ast.parse((init / "__init__.py").read_bytes())
    imported = [
        alias.name
        for node in tree.body
        if isinstance(node, ast.ImportFrom)
        for alias in node.names
    ]
    assert sorted(message_entity.__all__) == sorted(imported)


def test_no_module_outside_the_package_imports_its_sections(
    pytestconfig: pytest.Config,
) -> None:
    root = pytestconfig.rootpath
    package = root / "src" / "tdlib_oracle" / "tdlib" / "message_entity"
    imports = [
        f"{path.relative_to(root)}: {module}"
        for top in ("src", "tests")
        for path in sorted((root / top).rglob("*.py"))
        if package not in path.parents
        for module in _imported_modules(path)
        if module.startswith(f"{_PACKAGE}.")
    ]
    assert imports == []
