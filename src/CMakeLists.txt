# src/CMakeLists.txt
include(${CMAKE_SOURCE_DIR}/external/Deps.cmake)
include(CheckCXXSourceCompiles)

# ---- library with utils -------------------------------------------------------
add_library(cex_util
  util/log.cpp
  util/metrics_null.cpp
  util/tracing.cpp
  core/time.cpp
  core/id.cpp
  core/book.cpp  
)

target_include_directories(cex_util PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cex_util PUBLIC cex_opts spdlog::spdlog_header_only)

# Prefer std::format with spdlog when the toolchain supports it
set(CEX_CHECK_STD_FORMAT
"#include <format>
int main(){ auto s = std::format(\"{}\", 1); (void)s; }")
check_cxx_source_compiles("${CEX_CHECK_STD_FORMAT}" CEX_HAVE_STD_FORMAT)

if (CEX_HAVE_STD_FORMAT)
  message(STATUS "std::format available -> enabling SPDLOG_USE_STD_FORMAT")
  target_compile_definitions(cex_util PUBLIC SPDLOG_USE_STD_FORMAT=1)
else()
  message(STATUS "std::format NOT available -> using spdlog bundled fmt")
endif()

# ---- main exe ----------------------------------------------------------------
add_executable(cex_main main/cex_main.cpp)
target_link_libraries(cex_main PRIVATE cex_util)


# ---- Apply sanitizers to src targets (executables + libs) ----
EnableProjectSanitizers(${SANITIZE_KIND}
  cex_main
  cex_util
)