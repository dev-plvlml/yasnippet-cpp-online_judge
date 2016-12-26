#ifndef PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_
#define PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_

#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

class SieveOfEratosthenes {
 public:
  SieveOfEratosthenes(size_t n) {
    primes_.reserve(n / std::log(n));
    is_prime_.resize(n, true);
    is_prime_[0] = is_prime_[1] = false;
    for (unsigned i = 2; i < n; ++i) {
      if (is_prime_[i]) {
        primes_.push_back(i);
        // Reducing integer overflow risks:
        if (i * 1uLL * i > n)
          continue;
        for (unsigned j = i * i; j <= n; j += i) {
          is_prime_[j] = false;
        }
      }
    }
  }

  const auto& GetPrimes() const { return primes_; }
  const auto& GetIsPrime() const { return is_prime_; }
  bool IsPrime(size_t i) const { return is_prime_[i]; }

 private:
  std::vector<unsigned> primes_;
  std::vector<char> is_prime_;
};

#endif  // PRIME_NUMBER_SIEVE_OF_ERATOSHPENES_H_
