#ifndef PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_
#define PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_

#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

std::pair<std::vector<unsigned>, std::vector<char>> GetPrimes_NloglogN(size_t n) {
  std::vector<unsigned> primes;
  primes.reserve(n / std::log(n));
  std::vector<char> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (unsigned i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      // Reducing integer overflow risks:
      if (i * 1uLL * i > n)
        break;
      for (unsigned j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return {std::move(primes), std::move(is_prime)};
}

#endif  // PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_
