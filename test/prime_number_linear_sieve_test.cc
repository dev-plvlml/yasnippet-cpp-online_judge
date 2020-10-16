#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "prime_number_linear_sieve.h"

TEST(PrimeNumberLinearSieve, UpTo10) {
  LinearSieve sieve(10 + 1);
  ASSERT_THAT(sieve.GetPrimes(), testing::ElementsAre(2,3,5,7));
  ASSERT_THAT(sieve.GetLPD(), testing::ElementsAre(0,0,2,3,2,5,2,7,2,3,2));
}
