#include "cex/book.hpp"

namespace cex {
    
bool apply_delta(Book& b, const Delta& d) noexcept {
  const int i = d.level;

  // Fast bounds check that also handles negatives.
  if (static_cast<unsigned>(i) >= static_cast<unsigned>(DEPTH)) return false;

  const std::size_t ui = static_cast<std::size_t>(i);

  if (d.side == Side::Bid) {
    b.bid_p[ui] = d.price;
    b.bid_q[ui] = d.qty;
    return i == 0;
  } else {
    b.ask_p[ui] = d.price;
    b.ask_q[ui] = d.qty;
    return i == 0;
  }
}


int decide(const Book& b) noexcept {
    const double bp = b.bid_p[0];
    const double ap = b.ask_p[0];

    if (bp <= 0.0 || ap <= 0.0) return 0;

    const double mid = (bp + ap) * 0.5;
    const double spread = (ap - bp) /mid;

    if (spread < 0.0005) return -1;
    if (spread > 0.0020) return +1;
    return 0;
}
}