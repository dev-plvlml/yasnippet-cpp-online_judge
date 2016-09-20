template <typename T>
T GCD(T a, T b) {
  if (b != 0) {
    return GCD(b, a % b);
  }
  return a;
}
