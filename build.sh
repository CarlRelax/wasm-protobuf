#!/bin/bash

root=`pwd`
cd ${root}/emsdk

# Initialize EMSDK environment
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
cd ${root}

# Cleanup old build
if [ -e build ]; then
    rm -rf build
fi

if [ -e wasm_output ]; then
    rm -rf wasm_output
fi

mkdir build
cd build

# Build wasm
emcmake cmake ..
emmake make -j8
