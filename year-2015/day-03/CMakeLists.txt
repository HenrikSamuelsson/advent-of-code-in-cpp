cmake_minimum_required(VERSION 3.0.0)
project(AoC-year-2015-day-03 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(AoC-year-2015-day-03 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
