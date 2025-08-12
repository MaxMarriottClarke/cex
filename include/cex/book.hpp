#pragma once
#include <array>
#include <cstdint>

namespace cex {
constexpr int DEPTH = 50;

struct Book {
    std::array<double, DEPTH> bid_p{};
    std::array<double, DEPTH> bid_q{};
    std::array<double, DEPTH> ask_p{};
    std::array<double, DEPTH> ask_q{};
};

enum class Side : uint8_t { Bid = 0, Ask = 1};

struct Delta {
    Side side;
    int level;
    double price;
    double qty;
};
// Returns true if level 0 (top-of-book) changed.
bool apply_delta(Book& b, const Delta& d) noexcept;

// Toy decision: -1 sell, 0 hold, +1 buy.
int decide(const Book& b) noexcept;
}