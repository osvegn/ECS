#!/bin/bash

cmake -B build -DCMAKE_BUILD_TYPE=Debug -DTESTING=ON
cmake --build build
cd build
ctest --output-on-failure
./tests/functional/ecs_functional_tests
