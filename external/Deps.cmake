include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

# Logging
CPMAddPackage("gh:gabime/spdlog#v1.13.0")

# Testing
CPMAddPackage("gh:google/googletest#v1.14.0")

# Microbench
CPMAddPackage("gh:martinus/nanobench#v4.3.11")
