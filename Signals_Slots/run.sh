#!/usr/bin/env bash
set -euo pipefail

cmake --build cmake-build-debug -j
echo "----------------------------"
./cmake-build-debug/HelloQT2