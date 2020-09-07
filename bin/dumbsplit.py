#!/bin/python

import sys
from os import path
import re

RE_STDHEADER = re.compile(r'(?:^/\*.{76}\*/\n){11}\n', re.MULTILINE)
RE_INCLUDE = re.compile(r'(?:^\s*#\s*include.+\n+)+', re.MULTILINE)
RE_DECLARATIONS = re.compile(r'(?:^\s*(?://|/\*).+\n+)*(?:^[\w ]+\t+\**(?P<name>\w+)\(.+?\)(?=;\n))', re.MULTILINE)
RE_DEFINITIONS = re.compile(r'(?:^\s*(?://|/\*).+\n+)*(?:^[\w ]+\t+\**(?P<name>\w+)(?:.|\n)+?\n}\n)', re.MULTILINE)
RE_INDENTEDNAME = re.compile(r'^(int\t|[\w ]+)\t+')
RE_INDENTEDHEADER = re.compile(r'^\s*#\s+include', re.MULTILINE)
RE_FILE = re.compile(r'\w+\.[ch]\s+(?=:\+:)')


# TODO overwrite?
def dumbsplit(source):
    """look ma i’m splitting"""

    print(f'{source}:')

    with open(source, 'r') as f:
        text = f.read()

    stdheader = RE_STDHEADER.search(text)
    include = RE_INCLUDE.search(text)

    declarations = source.endswith('.h')
    re_extract = RE_DECLARATIONS if declarations else RE_DEFINITIONS

    functions = re_extract.finditer(text)
    workdir = path.dirname(path.abspath(source))
    for match in functions:
        body = match.group()
        name = match.group('name')

        file = f'{name}.c'
        out = path.join(workdir, file)
        with open(out, 'w') as f:
            print(f'\t{file}')

            if stdheader:
                f.write(RE_FILE.sub(file.ljust(51), stdheader.group()))

            if include:
                f.write(RE_INDENTEDHEADER.sub('#include', include.group()))

            if declarations:
                header = path.basename(source)
                f.write(f'#include "{header}"\n\n')

            f.write(RE_INDENTEDNAME.sub(r'\1\t', body))

            if declarations:
                f.write('\n{\n}\n')


if __name__ == '__main__':
    if len(sys.argv) == 1:
        print(f'usage: {sys.argv[0]} path/to/source.c [other/source.h ...]')
        sys.exit(2)

    for arg in sys.argv[1:]:
        if arg.endswith('.c') or arg.endswith('.h'):
            dumbsplit(arg)
        else:
            print('error: .c/.h files only')
