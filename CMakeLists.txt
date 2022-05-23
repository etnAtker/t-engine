cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

project(t-engine)

include_directories("${PROJECT_SOURCE_DIR}/framework/common")
include_directories("${PROJECT_SOURCE_DIR}/framework/interface")

add_subdirectory(framework)
add_subdirectory(empty)
