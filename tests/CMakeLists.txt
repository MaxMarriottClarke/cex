include(${CMAKE_SOURCE_DIR}/external/Deps.cmake)
enable_testing()

add_executable(unit_time unit/test_time.cpp)
target_link_libraries(unit_time PRIVATE cex_util gtest_main)
add_test(NAME unit_time COMMAND $<TARGET_FILE:unit_time>)

add_executable(bench_update perf/bench_update.cpp)
target_link_libraries(bench_update PRIVATE cex_util nanobench)

# NEW: place test/bench executables in the top-level build dir
set_target_properties(unit_time bench_update
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
