#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "prime_number_sieve_of_eratosthenes.h"

TEST(PrimeNumberSieveOfEratosthenes, UpTo10) {
  SieveOfEratosthenes sieve(10 + 1);
  ASSERT_THAT(sieve.GetPrimes(), testing::ElementsAre(2,3,5,7));
  ASSERT_THAT(sieve.GetIsPrime(), testing::ElementsAre(0,0,1,1,0,1,0,1,0,0,0));
}
