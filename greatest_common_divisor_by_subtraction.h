#ifndef GREATEST_COMMON_DIVISOR_BY_SUBTRACTION_H_
#define GREATEST_COMMON_DIVISOR_BY_SUBTRACTION_H_

#include <algorithm>
#include <cmath>

template <typename T>
T GCD_BySub(T a, T b) {
  a = std::abs(a);
  b = std::abs(b);
  while (a != 0 && b != 0) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return std::max(a, b);
}

#endif  // GREATEST_COMMON_DIVISOR_BY_SUBTRACTION_H_
