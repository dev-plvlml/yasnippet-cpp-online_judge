#ifndef MODULAR_ARITHMETICS_H_
#define MODULAR_ARITHMETICS_H_

template <typename T>
T PlusMod(T a, T b, T m) {
  a %= m;
  b %= m;
  // Naive approach:
  // return (a + b) % m;
  // Reducing integer overflow risks:
  T sum = a - m + b;
  return sum < 0 ? sum + m : sum;
}

template <typename T>
T MultipliesMod(T a, T b, T m) {
  a %= m;
  b %= m;
  T product = 0;
  while (b) {
    if (b & 1) {
      product = PlusMod(product, a, m);
    }
    a = PlusMod(a, a, m);
    b >>= 1;
  }
  return product;
}

template <typename T>
T PowerMod(T a, T n, T m) {
  a %= m;
  T power = 1;
  while (n) {
    if (n & 1) {
      power = MultipliesMod(power, a, m);
    }
    a = MultipliesMod(a, a, m);
    n >>= 1;
  }
  return power;
}

#endif  // MODULAR_ARITHMETICS_H_
