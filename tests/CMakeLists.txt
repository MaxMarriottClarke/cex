include(${CMAKE_SOURCE_DIR}/external/Deps.cmake)

add_executable(unit_time unit/test_time.cpp)
target_link_libraries(unit_time PRIVATE cex_util gtest_main)

# Robust: use generator expression to the built binary
add_test(NAME unit_time COMMAND $<TARGET_FILE:unit_time>)

add_executable(bench_update perf/bench_update.cpp)
target_link_libraries(bench_update PRIVATE cex_util nanobench)
