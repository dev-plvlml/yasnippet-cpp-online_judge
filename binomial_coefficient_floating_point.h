#ifndef BINOMIAL_COEFFICIENT_FLOATING_POINT_H_
#define BINOMIAL_COEFFICIENT_FLOATING_POINT_H_

template <typename T, typename FP = double>
T Comb(T n0, T k0) {
  FP eps = 0.005;
  if (k0 > n0) return 0;
  if (k0 > n0 - k0) {
    k0 = n0 - k0;
  }
  FP result = 1.0;
  for (FP k = 1.0, n = n0 - k0 + 1; k <= k0; ++k, ++n) {
    result *= n / k;
  }
  return result + eps;
}

#endif  // BINOMIAL_COEFFICIENT_FLOATING_POINT_H_
