template <typename T>
T Comb(T n, T k) {
  if (k > n)
    return 0;
  T result = 1;
  if (k > n - k) {
    k = n - k;
  }
  for (T i = n - k + 1; i <= n; ++i) { 
    result *= i; 
  }
  for (T i = 2; i <= k; ++i) { 
    result /= i; 
  }
  return result;
}
