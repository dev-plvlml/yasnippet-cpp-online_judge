template <typename T>
T GCD(T a, T b) {
  if (a != 0 && b != 0) {
    while (a != b) {
      if (a > b) {
        a -= b;
      } else {
        b -= a;
      }
    }
  }
  return max(a, b);
}
