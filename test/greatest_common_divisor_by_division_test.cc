#include <gtest/gtest.h>

#include "greatest_common_divisor_by_division.h"

TEST(GreatestCommonDivisorByModulo, HandlesZero) {
  EXPECT_EQ(1, GCD_ByDiv(1, 0));
  EXPECT_EQ(1, GCD_ByDiv(0, 1));
  EXPECT_EQ(42, GCD_ByDiv(42, 0));
  EXPECT_EQ(42, GCD_ByDiv(0, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesOne) {
  EXPECT_EQ(1, GCD_ByDiv(1, 1));
  EXPECT_EQ(1, GCD_ByDiv(1, 42));
  EXPECT_EQ(1, GCD_ByDiv(42, 1));
}

TEST(GreatestCommonDivisorByModulo, HandlesEqual) {
  EXPECT_EQ(42, GCD_ByDiv(42, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesPrime) {
  EXPECT_EQ(1, GCD_ByDiv(2, 3));
  EXPECT_EQ(1, GCD_ByDiv(3, 2));
  EXPECT_EQ(1, GCD_ByDiv(101, 103));
  EXPECT_EQ(1, GCD_ByDiv(103, 101));
  EXPECT_EQ(1, GCD_ByDiv(107, 109));
  EXPECT_EQ(1, GCD_ByDiv(109, 107));
  EXPECT_EQ(1, GCD_ByDiv(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, GCD_ByDiv(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByModulo, HandlesCoprime) {
  EXPECT_EQ(1, GCD_ByDiv(42, 55));
  EXPECT_EQ(1, GCD_ByDiv(55, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesFibonacci) {
  EXPECT_EQ(1, GCD_ByDiv(5, 8));
  EXPECT_EQ(1, GCD_ByDiv(8, 5));
  EXPECT_EQ(1, GCD_ByDiv(24'157'817, 39'088'169));
  EXPECT_EQ(1, GCD_ByDiv(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByModulo, HandlesArbitrary) {
  EXPECT_EQ(2, GCD_ByDiv(42, 2));
  EXPECT_EQ(2, GCD_ByDiv(2, 42));
  EXPECT_EQ(6, GCD_ByDiv(42, 6));
  EXPECT_EQ(6, GCD_ByDiv(6, 42));
  EXPECT_EQ(7, GCD_ByDiv(42, 35));
  EXPECT_EQ(7, GCD_ByDiv(35, 42));
  EXPECT_EQ(6, GCD_ByDiv(42, 30));
  EXPECT_EQ(6, GCD_ByDiv(30, 42));
}

TEST(GreatestCommonDivisorByModulo, HandlesNegative) {
  EXPECT_EQ(1, GCD_ByDiv(-2, -3));
  EXPECT_EQ(1, GCD_ByDiv(-3, -2));
  EXPECT_EQ(7, GCD_ByDiv(-42, -35));
  EXPECT_EQ(7, GCD_ByDiv(-35, -42));
  EXPECT_EQ(6, GCD_ByDiv(-42, -30));
  EXPECT_EQ(6, GCD_ByDiv(-30, -42));
}
