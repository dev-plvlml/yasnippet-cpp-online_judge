template <typename T>
T GCD(T a, T b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return max(a, b);
}
