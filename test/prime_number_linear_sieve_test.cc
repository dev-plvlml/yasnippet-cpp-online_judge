#include <vector>
#include <gtest/gtest.h>

#include "prime_number_linear_sieve.h"

using Vu = std::vector<unsigned>;

TEST(PrimeNumberLinearSieve, UpTo10) {
  LinearSieve sieve(10);
  ASSERT_EQ(Vu({2,3,5,7}), sieve.GetPrimes());
  ASSERT_EQ(Vu({0,0,2,3,2,5,2,7,2,3,2}), sieve.GetLpd());
}
