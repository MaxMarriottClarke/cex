#include <nanobench.h>
#include "cex/time.hpp"

int main(){
  ankerl::nanobench::Bench bench;
  bench.minEpochIterations(5000).epochs(5).run("now_ns", []{
    auto t = cex::now_ns();
    ankerl::nanobench::doNotOptimizeAway(t);
  });
}
