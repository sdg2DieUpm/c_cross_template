#!/bin/bash
cd build || { echo "Failed to change directory to cmake-build folder. Run build.sh before tests"; exit; }
ctest --output-on-failure
