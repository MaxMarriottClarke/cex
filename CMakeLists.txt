cmake_minimum_required(VERSION 3.26)
project(cex LANGUAGES CXX)

include(CTest)
enable_testing()


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Common warnings/flags
add_library(cex_opts INTERFACE)
target_compile_options(cex_opts INTERFACE
  -Wall -Wextra -Wpedantic -Wconversion -fno-omit-frame-pointer)

add_subdirectory(src)
add_subdirectory(tests)
