#ifndef BINOMIAL_COEFFICIENT_INTEGER_H_
#define BINOMIAL_COEFFICIENT_INTEGER_H_

template <typename T>
T Comb(T n, T k) {
  if (k > n) return 0;
  if (k > n - k) {
    k = n - k;
  }
  T result = 1;
  for (T i = n - k + 1; i <= n; ++i) { 
    result *= i; 
  }
  for (T i = 2; i <= k; ++i) { 
    result /= i; 
  }
  return result;
}

#endif  // BINOMIAL_COEFFICIENT_INTEGER_H_
