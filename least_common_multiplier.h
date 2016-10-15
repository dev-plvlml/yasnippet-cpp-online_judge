#include <cstdlib>

template <typename T>
T GCD(T a, T b);

template <typename T>
T LCM(T a, T b) {
  a = abs(a);
  b = abs(b);
  // According to a formula:
  // return (a * b) / GCD(a, b);
  // Reducing integer overflow:
  return a / GCD(a, b) * b;
}
