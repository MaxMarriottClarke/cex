#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
namespace cex {
void init_logging(){
  auto lg = spdlog::stdout_color_mt("cex");
  spdlog::set_default_logger(lg);
  spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%e [%^%l%$] %v");
  spdlog::info("logging ready");
}
}
