#include <nanobench.h>
#include "cex/book.hpp"
#include <vector>
#include <random>
#include <cstddef>

int main(){
  using namespace cex;

  Book b{};
  std::mt19937_64 rng(42);
  std::uniform_int_distribution<int> L(0, DEPTH - 1);
  std::uniform_real_distribution<double> P(1000.0, 2000.0);
  std::uniform_real_distribution<double> Q(0.001, 1.0);

  // Pre-generate a ring of deltas so RNG cost isn't in the timed body.
  constexpr std::size_t N = 1u << 16;
  std::vector<Delta> ds;
  ds.reserve(N);
  for (std::size_t i = 0; i < N; i++) {
    ds.push_back(Delta{ (rng() & 1) ? Side::Bid : Side::Ask, L(rng), P(rng), Q(rng)});
  }
  std::size_t idx = 0;
  const std::size_t mask = N - 1;

  ankerl::nanobench::Bench bench;
  bench.minEpochIterations(20000).epochs(5).run("update->decide", [&]{
    const Delta& d = ds[idx & mask];
    ++idx;

    apply_delta(b, d);
    int s = decide(b);
    ankerl::nanobench::doNotOptimizeAway(s);
  });


}
