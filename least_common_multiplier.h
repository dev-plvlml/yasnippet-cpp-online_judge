template <typename T>
T LCM(T a, T b) {
  // According to a formula:
  // return (a * b) / GCD(a, b);
  // Without integer overflow:
  return a / GCD(a, b) * b;
}
