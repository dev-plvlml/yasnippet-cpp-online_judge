#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
namespace subtraction {
#include "../greatest_common_divisor_by_subtraction.h"
}

TEST(GreatestCommonDivisorEuclidean, HandlesZero) {
  EXPECT_EQ(1, subtraction::GCD(1, 0));
  EXPECT_EQ(1, subtraction::GCD(0, 1));
  EXPECT_EQ(42, subtraction::GCD(42, 0));
  EXPECT_EQ(42, subtraction::GCD(0, 42));
}

TEST(GreatestCommonDivisorEuclidean, HandlesOne) {
  EXPECT_EQ(1, subtraction::GCD(1, 1));
  EXPECT_EQ(1, subtraction::GCD(1, 42));
  EXPECT_EQ(1, subtraction::GCD(42, 1));
}

TEST(GreatestCommonDivisorEuclidean, HandlesEqual) {
  EXPECT_EQ(42, subtraction::GCD(42, 42));
}

TEST(GreatestCommonDivisorEuclidean, HandlesPrime) {
  EXPECT_EQ(1, subtraction::GCD(2, 3));
  EXPECT_EQ(1, subtraction::GCD(3, 2));
  EXPECT_EQ(1, subtraction::GCD(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, subtraction::GCD(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorEuclidean, HandlesCoprime) {
  EXPECT_EQ(1, subtraction::GCD(42, 55));
  EXPECT_EQ(1, subtraction::GCD(55, 42));
}

TEST(GreatestCommonDivisorEuclidean, HandlesFibonacci) {
  EXPECT_EQ(1, subtraction::GCD(5, 8));
  EXPECT_EQ(1, subtraction::GCD(8, 5));
  EXPECT_EQ(1, subtraction::GCD(24'157'817, 39'088'169));
  EXPECT_EQ(1, subtraction::GCD(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorEuclidean, HandlesArbitrary) {
  EXPECT_EQ(2, subtraction::GCD(42, 2));
  EXPECT_EQ(2, subtraction::GCD(2, 42));
  EXPECT_EQ(6, subtraction::GCD(42, 6));
  EXPECT_EQ(6, subtraction::GCD(6, 42));
  EXPECT_EQ(7, subtraction::GCD(42, 35));
  EXPECT_EQ(7, subtraction::GCD(35, 42));
  EXPECT_EQ(6, subtraction::GCD(42, 30));
  EXPECT_EQ(6, subtraction::GCD(30, 42));
}

TEST(GreatestCommonDivisorEuclidean, HandlesNegative) {
  EXPECT_EQ(1, subtraction::GCD(-2, -3));
  EXPECT_EQ(1, subtraction::GCD(-3, -2));
  EXPECT_EQ(7, subtraction::GCD(-42, -35));
  EXPECT_EQ(7, subtraction::GCD(-35, -42));
  EXPECT_EQ(6, subtraction::GCD(-42, -30));
  EXPECT_EQ(6, subtraction::GCD(-30, -42));
}
