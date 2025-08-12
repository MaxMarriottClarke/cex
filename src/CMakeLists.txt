include(${CMAKE_SOURCE_DIR}/external/Deps.cmake)

add_library(cex_util
  util/log.cpp
  util/metrics_null.cpp
  util/tracing.cpp
  core/time.cpp
  core/id.cpp
)
target_include_directories(cex_util PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cex_util PUBLIC cex_opts spdlog::spdlog_header_only)

# Fix spdlog + clang 20 issue by using std::format
target_compile_definitions(cex_util PUBLIC SPDLOG_USE_STD_FORMAT=1)

add_executable(cex_main main/cex_main.cpp)
target_link_libraries(cex_main PRIVATE cex_util)
