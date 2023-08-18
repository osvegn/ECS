#!/bin/bash
cd submodules/vector
cmake -B build
cmake --build build
cd ../Criterion
meson build
ninja -C build
