#include <cmath>
#include <functional>

template <class T, class Function, class Compare = std::less<T>>
T GoldenSectionSearch(T x1, T x2, Function function, Compare compare = Compare()) {
  constexpr T eps = 1.0e-9;
  const T phi = (1.0 + sqrt(5.0)) / 2.0; 
  T xL = x1 + (x2 - x1) * (2 - phi);
  T xR = x2 - (x2 - x1) * (2 - phi);
  T fL = function(xL);
  T fR = function(xR);
  while (x2 - x1 >= eps) {
    if (compare(fL, fR)) {
      x2 = xR;
      xR = xL, xL = x1 + (x2 - x1) * (2 - phi);
      fR = fL, fL = function(xL);
    } else {
      x1 = xL;
      xL = xR, xR = x2 - (x2 - x1) * (2 - phi);
      fL = fR, fR = function(xR);
    }
  }
  return (x1 + x2) / 2;
}
