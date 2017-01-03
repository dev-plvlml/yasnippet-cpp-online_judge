#include <gtest/gtest.h>

#include "greatest_common_divisor_by_subtraction.h"

TEST(GreatestCommonDivisorBySubtraction, HandlesZero) {
  EXPECT_EQ(1, GCD_BySub(1, 0));
  EXPECT_EQ(1, GCD_BySub(0, 1));
  EXPECT_EQ(42, GCD_BySub(42, 0));
  EXPECT_EQ(42, GCD_BySub(0, 42));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesOne) {
  EXPECT_EQ(1, GCD_BySub(1, 1));
  EXPECT_EQ(1, GCD_BySub(1, 42));
  EXPECT_EQ(1, GCD_BySub(42, 1));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesEqual) {
  EXPECT_EQ(42, GCD_BySub(42, 42));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesPrime) {
  EXPECT_EQ(1, GCD_BySub(2, 3));
  EXPECT_EQ(1, GCD_BySub(3, 2));
  EXPECT_EQ(1, GCD_BySub(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, GCD_BySub(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesCoprime) {
  EXPECT_EQ(1, GCD_BySub(42, 55));
  EXPECT_EQ(1, GCD_BySub(55, 42));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesFibonacci) {
  EXPECT_EQ(1, GCD_BySub(5, 8));
  EXPECT_EQ(1, GCD_BySub(8, 5));
  EXPECT_EQ(1, GCD_BySub(24'157'817, 39'088'169));
  EXPECT_EQ(1, GCD_BySub(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesArbitrary) {
  EXPECT_EQ(2, GCD_BySub(42, 2));
  EXPECT_EQ(2, GCD_BySub(2, 42));
  EXPECT_EQ(6, GCD_BySub(42, 6));
  EXPECT_EQ(6, GCD_BySub(6, 42));
  EXPECT_EQ(7, GCD_BySub(42, 35));
  EXPECT_EQ(7, GCD_BySub(35, 42));
  EXPECT_EQ(6, GCD_BySub(42, 30));
  EXPECT_EQ(6, GCD_BySub(30, 42));
}

TEST(GreatestCommonDivisorBySubtraction, HandlesNegative) {
  EXPECT_EQ(1, GCD_BySub(-2, -3));
  EXPECT_EQ(1, GCD_BySub(-3, -2));
  EXPECT_EQ(7, GCD_BySub(-42, -35));
  EXPECT_EQ(7, GCD_BySub(-35, -42));
  EXPECT_EQ(6, GCD_BySub(-42, -30));
  EXPECT_EQ(6, GCD_BySub(-30, -42));
}
