cmake_minimum_required(VERSION 3.16)

project(VTM VERSION 1.0.5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build unit tests" ON)

add_subdirectory(VirtualTuringMachine/)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
