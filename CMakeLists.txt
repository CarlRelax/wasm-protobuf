cmake_minimum_required(VERSION 3.10)
project(wasm_protobuf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_C_COMPILER emcc)
set(CMAKE_CXX_COMPILER em++)
set(CMAKE_EXECUTABLE_SUFFIX ".js")

list(APPEND INCLUDE_PATH 
    ${CMAKE_SOURCE_DIR}/protobuf/src
    ${CMAKE_SOURCE_DIR}/proto
    ${CMAKE_SOURCE_DIR}/emsdk/upstream/emscripten/cache/sysroot/include
)
include_directories(${INCLUDE_PATH})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/wasm_output)

add_executable(wasm_protobuf main.cpp proto/person.pb.cc)

target_link_libraries(${PROJECT_NAME} protobuf ${CMAKE_SOURCE_DIR}/protobuf/src/.libs/libprotobuf.a ${CMAKE_SOURCE_DIR}/protobuf/src/.libs/libprotobuf-lite.a)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 17
    LINK_FLAGS "-s ENVIRONMENT=web -s MODULARIZE=1 -s EXPORT_NAME=\'Decoder\' -s EXPORTE_ES6=1"
)
target_link_options(${PROJECT_NAME} PRIVATE 
    "SHELL:--bind"
)