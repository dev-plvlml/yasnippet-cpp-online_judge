#include <gtest/gtest.h>

#include "prime_number_sieve_of_eratosthenes.h"

using Vu = std::vector<unsigned>;
using Vc = std::vector<char>;

TEST(PrimeNumberSieveOsEratosthenes, UpTo10) {
  Sieve sieve(10);
  ASSERT_EQ(Vu({2,3,5,7}), sieve.GetPrimes());
  ASSERT_EQ(Vc({0,0,1,1,0,1,0,1,0,0,0}), sieve.GetIsPrime());
}
