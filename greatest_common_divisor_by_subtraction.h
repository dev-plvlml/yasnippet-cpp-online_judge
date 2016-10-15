#include <algorithm>
#include <cstdlib>

template <typename T>
T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (a != 0 && b != 0) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return std::max(a, b);
}
