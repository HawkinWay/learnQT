#!/usr/bin/env bash
set -euo pipefail

cmake --build build -j
echo "----------------------------"
./build/HelloQT5