#include <functional>

extern const double eps;

template <class T, class Function, class Compare = std::less<T>>
T TernarySearch(T x1, T x2, Function function, Compare compare = Compare()) {
  while (x2 - x1 >= eps) {
    T dx = (x2 - x1) / 3;
    T xL = x1 + dx;
    T xR = x2 - dx;
    T fL = function(xL);
    T fR = function(xR);
    if (compare(fL, fR)) {
      x2 = xR;
    } else {
      x1 = xL;
    }
  }
  return (x1 + x2) / 2;
}
