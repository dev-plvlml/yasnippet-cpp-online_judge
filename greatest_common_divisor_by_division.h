#ifndef GREATEST_COMMON_DIVISOR_BY_DIVISION_H_
#define GREATEST_COMMON_DIVISOR_BY_DIVISION_H_

#include <cstdlib>

template <typename T>
T GCD_ByDiv(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    T tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

#endif  // GREATEST_COMMON_DIVISOR_BY_DIVISION_H_
