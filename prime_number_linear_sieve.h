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
    for (size_t i = 2; i < n; ++i) {
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

  const auto& GetLPD() const { return lpd_; }  //!< Least Prime Divisor
  const auto& GetPrimes() const { return primes_; }
  bool IsPrime(size_t i) const { return i >= 2 && lpd_[i] == i; }
  unsigned LPD(size_t i) const { return lpd_[i]; }

 private:
  std::vector<size_t> primes_;
  std::vector<size_t> lpd_;
};

#endif  // PRIME_NUMBER_LINEAR_SIEVE_H_
