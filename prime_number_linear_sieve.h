#ifndef PRIME_NUMBER_LINEAR_SIEVE_H_
#define PRIME_NUMBER_LINEAR_SIEVE_H_

#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

std::pair<std::vector<unsigned>, std::vector<unsigned>> GetPrimes_N(size_t n) {
  std::vector<unsigned> primes;
  primes.reserve(n / std::log(n));
  std::vector<unsigned> lpd(n+1, 0);  // Least Prime Divisor
  for (unsigned i = 2; i <= n; ++i) {
    if (!lpd[i]) {
      lpd[i] = i;
      primes.push_back(i);
    }
    for (size_t j = 0; j < primes.size() && primes[j] <= lpd[i]; ++j) {
      // Reducing integer overflow risks:
      if (i * 1uLL * primes[j] > n)
        break;
      lpd[i * primes[j]] = primes[j];
    }
  }
  return {std::move(primes), std::move(lpd)};
}

#endif  // PRIME_NUMBER_LINEAR_SIEVE_H_
