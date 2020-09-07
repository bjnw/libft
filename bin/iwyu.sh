#!/bin/bash
set -o errexit -o pipefail -o nounset -o noglob
IFS=$'\t\n'

compiledb make
iwyu-tool -p . | iwyu-fix-includes --reorder --nosafe_headers
