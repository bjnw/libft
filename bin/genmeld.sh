#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset
# set -o noglob
# set -o xtrace

path="$1"

mkdir -p "$(dirname $path)"
echo > "$path"
find -- src -type f -wholename '*.c' -exec cat {} >> "$path" \;