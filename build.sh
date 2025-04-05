#!/usr/bin/bash
set -e

# Configurable renderer backend, default is SDL2
# Usage: ./build.sh [RENDER_BACKEND]
RENDER_BACKEND=${1:-SDL2}

echo "Building LitePM with renderer backend: $RENDER_BACKEND"

mkdir -p build
cd build
cmake .. -DRENDER_BACKEND=$RENDER_BACKEND
make -j$(nproc)
