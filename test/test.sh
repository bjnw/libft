#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset
# set -o noglob
# set -o xtrace

cc=$1
cflags=$2
lib=$3

$cc $cflags test/list.c $lib -o test/list.out
cd test
./list.out
