#include "cex/log.hpp"
#include "cex/metrics.hpp"
#include "cex/time.hpp"
#include <spdlog/spdlog.h>

int main() {
  cex::init_logging();
  cex::start_metrics(9464); // no-op for now
  spdlog::info("boot t={} ns", cex::now_ns());
  return 0;
}
