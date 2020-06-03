#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset
# set -o noglob
# set -o xtrace

cc=$1
cflags=$2
lib=$3

find test -name '*.out' -delete
find test -name '*.c' -exec $cc $cflags {} $lib -o {}.out \;
cd test
find . -name '*.out' -print -exec {} \;
