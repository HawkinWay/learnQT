#!/usr/bin/env bash
set -euo pipefail

rm -rf build/
cmake -B build/ -S .