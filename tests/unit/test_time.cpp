#include <gtest/gtest.h>
#include "cex/time.hpp"

TEST(Time, Monotonic) {
  auto a = cex::now_ns();
  auto b = cex::now_ns();
  EXPECT_LE(a, b);
}
