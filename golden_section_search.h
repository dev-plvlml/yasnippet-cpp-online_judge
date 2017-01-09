#ifndef GOLDEN_SECTION_SEARCH_H_
#define GOLDEN_SECTION_SEARCH_H_

#include <cmath>
#include <functional>
#include "main.h"

template <class T, class Function, class Compare = std::less<T>>
T GoldenSectionSearch(T x1, T x2, Function function, Compare compare = Compare()) {
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

#endif  // GOLDEN_SECTION_SEARCH_H_
