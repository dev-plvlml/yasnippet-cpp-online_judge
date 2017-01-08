#ifndef BINOMIAL_COEFFICIENT_FLOATING_POINT_H_
#define BINOMIAL_COEFFICIENT_FLOATING_POINT_H_

#include <cmath>

template <typename T, typename FP = double>
T FComb(T n, T k) {
  if (k > n) return 0;
  if (k > n - k) {
    k = n - k;
  }
  FP result = 1.0;
  for (FP ki = 1.0, ni = n - k + 1; ki <= k; ++ki, ++ni) {
    result *= ni / ki;
  }
  return std::round(result);
}

#endif  // BINOMIAL_COEFFICIENT_FLOATING_POINT_H_
