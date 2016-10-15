#include <cstdlib>

template <typename T>
T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    T tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
