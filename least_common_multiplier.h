template <typename T>
T LCM(T a, T b) {
  // According to a formula:
  // return (a * b) / GCD(a, b);
  // Reducing integer overflow:
  return a / GCD(a, b) * b;
}
