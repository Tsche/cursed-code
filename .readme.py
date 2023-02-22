#!/usr/bin/env python3

from pathlib import Path
from string import Template

TEMPLATE = Template("""\
# Cursed Code
## $name
$description

### Directories
$dirs

### Files
$files
""")

ROW = Template("* [$name]($link) ")


def discover(path):
    directories = []
    files = []
    for entry in path.iterdir():
        if entry.name.startswith('.'):
            continue

        # blacklist
        if entry.name in ("README.md", "CNAME"):
            continue

        if entry.is_dir():
            directories.append(entry)
            yield from discover(entry)
            continue

        files.append(entry.relative_to(path))

    yield path, directories, files


def main():
    root = Path('.')

    for folder, directories, files in discover(root):
        description = ""

        if (readme := Path("README")) in files:
            files.remove(readme)

            with open(folder / readme, 'r', encoding='utf-8') as file:
                description = file.read()

        dirs = '\n'.join([ROW.substitute(name=file.name, link=file.relative_to(folder))
                          for file in directories])

        rows = '\n'.join([ROW.substitute(name=file.name, link=file)
                          for file in files])

        readme = TEMPLATE.substitute(name=folder.name,
                                     description=description,
                                     dirs=dirs,
                                     files=rows)

        with open(folder / 'README.md', 'w', encoding='utf-8') as file:
            file.write(readme)


if __name__ == "__main__":
    main()
