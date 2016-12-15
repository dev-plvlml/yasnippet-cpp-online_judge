#ifndef GREATEST_COMMON_DIVISOR_BY_DIVISION_RECURSIVE_H_
#define GREATEST_COMMON_DIVISOR_BY_DIVISION_RECURSIVE_H_

template <typename T>
T GCD_ByDivRec(T a, T b) {
  if (b != 0) {
    return GCD_ByDivRec(b, a % b);
  }
  return a;
}

#endif  // GREATEST_COMMON_DIVISOR_BY_DIVISION_RECURSIVE_H_
