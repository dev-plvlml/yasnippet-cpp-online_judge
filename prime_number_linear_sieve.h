#ifndef PRIME_NUMBER_LINEAR_SIEVE_H_
#define PRIME_NUMBER_LINEAR_SIEVE_H_

#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

class LinearSieve {
 public:
  LinearSieve(size_t n) {
    primes_.reserve(n / std::log(n));
    lpd_.resize(n, 0);
    for (unsigned i = 2; i < n; ++i) {
      if (!lpd_[i]) {
        lpd_[i] = i;
        primes_.push_back(i);
      }
      for (size_t j = 0; j < primes_.size() && primes_[j] <= lpd_[i]; ++j) {
        // Reducing integer overflow risks:
        if (i * 1uLL * primes_[j] > n)
          break;
        lpd_[i * primes_[j]] = primes_[j];
      }
    }
  }

  const auto& GetPrimes() const { return primes_; }
  const auto& GetLpd() const { return lpd_; }
  unsigned Lpd(size_t i) const { return lpd_[i]; }
  bool IsPrime(unsigned i) const { return i >= 2 && lpd_[i] == i; }

 private:
  std::vector<unsigned> primes_;
  std::vector<unsigned> lpd_;  // Least Prime Divisor
};

#endif  // PRIME_NUMBER_LINEAR_SIEVE_H_
