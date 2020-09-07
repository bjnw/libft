#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset
# set -o noglob
# set -o xtrace

src_dirs="$(find -- * -type d -wholename 'src*' | tr $'\n' $' ')"
c_files="$(cd src && find -- * -type f -wholename '*.c' | tr $'\n' $' ')"

sed -E "
	s|%SRC_DIRS%|${src_dirs}|
	s|%C_FILES%|${c_files}|
" Makefile.skel
