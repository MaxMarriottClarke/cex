#pragma once
#include <atomic>
namespace cex {
struct OrderId { uint64_t v; };
inline OrderId next_order_id() {
  static std::atomic<uint64_t> ctr{1};
  return {ctr.fetch_add(1, std::memory_order_relaxed)};
}
}
