#include <gtest/gtest.h>

#include <cstdlib>
namespace division {
#include "greatest_common_divisor_by_division.h"
}

TEST(GreatestCommonDivisorByModulo, HandlesZero) {
  EXPECT_EQ(1, division::GCD(1, 0));
  EXPECT_EQ(1, division::GCD(0, 1));
  EXPECT_EQ(42, division::GCD(42, 0));
  EXPECT_EQ(42, division::GCD(0, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesOne) {
  EXPECT_EQ(1, division::GCD(1, 1));
  EXPECT_EQ(1, division::GCD(1, 42));
  EXPECT_EQ(1, division::GCD(42, 1));
}

TEST(GreatestCommonDivisorByModulo, HandlesEqual) {
  EXPECT_EQ(42, division::GCD(42, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesPrime) {
  EXPECT_EQ(1, division::GCD(2, 3));
  EXPECT_EQ(1, division::GCD(3, 2));
  EXPECT_EQ(1, division::GCD(101, 103));
  EXPECT_EQ(1, division::GCD(103, 101));
  EXPECT_EQ(1, division::GCD(107, 109));
  EXPECT_EQ(1, division::GCD(109, 107));
  EXPECT_EQ(1, division::GCD(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, division::GCD(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByModulo, HandlesCoprime) {
  EXPECT_EQ(1, division::GCD(42, 55));
  EXPECT_EQ(1, division::GCD(55, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesFibonacci) {
  EXPECT_EQ(1, division::GCD(5, 8));
  EXPECT_EQ(1, division::GCD(8, 5));
  EXPECT_EQ(1, division::GCD(24'157'817, 39'088'169));
  EXPECT_EQ(1, division::GCD(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByModulo, HandlesArbitrary) {
  EXPECT_EQ(2, division::GCD(42, 2));
  EXPECT_EQ(2, division::GCD(2, 42));
  EXPECT_EQ(6, division::GCD(42, 6));
  EXPECT_EQ(6, division::GCD(6, 42));
  EXPECT_EQ(7, division::GCD(42, 35));
  EXPECT_EQ(7, division::GCD(35, 42));
  EXPECT_EQ(6, division::GCD(42, 30));
  EXPECT_EQ(6, division::GCD(30, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesNegative) {
  EXPECT_EQ(1, division::GCD(-2, -3));
  EXPECT_EQ(1, division::GCD(-3, -2));
  EXPECT_EQ(7, division::GCD(-42, -35));
  EXPECT_EQ(7, division::GCD(-35, -42));
  EXPECT_EQ(6, division::GCD(-42, -30));
  EXPECT_EQ(6, division::GCD(-30, -42));
}
