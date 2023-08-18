#!/bin/bash
cd submodules/vector
cmake -B build
cmake --build build

if [ "$1" == "TESTING" ]; then
    cd ../Criterion
    meson build
    ninja -C build
fi

