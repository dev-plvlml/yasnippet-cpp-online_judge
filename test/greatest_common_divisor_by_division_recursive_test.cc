#include <gtest/gtest.h>

#include "greatest_common_divisor_by_division_recursive.h"

TEST(GreatestCommonDivisorByModuloRecursive, HandlesZero) {
  EXPECT_EQ(1, GCD_ByDivRec(1, 0));
  EXPECT_EQ(1, GCD_ByDivRec(0, 1));
  EXPECT_EQ(42, GCD_ByDivRec(42, 0));
  EXPECT_EQ(42, GCD_ByDivRec(0, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesOne) {
  EXPECT_EQ(1, GCD_ByDivRec(1, 1));
  EXPECT_EQ(1, GCD_ByDivRec(1, 42));
  EXPECT_EQ(1, GCD_ByDivRec(42, 1));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesEqual) {
  EXPECT_EQ(42, GCD_ByDivRec(42, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesPrime) {
  EXPECT_EQ(1, GCD_ByDivRec(2, 3));
  EXPECT_EQ(1, GCD_ByDivRec(3, 2));
  EXPECT_EQ(1, GCD_ByDivRec(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, GCD_ByDivRec(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesCoprime) {
  EXPECT_EQ(1, GCD_ByDivRec(42, 55));
  EXPECT_EQ(1, GCD_ByDivRec(55, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesFibonacci) {
  EXPECT_EQ(1, GCD_ByDivRec(5, 8));
  EXPECT_EQ(1, GCD_ByDivRec(8, 5));
  EXPECT_EQ(1, GCD_ByDivRec(24'157'817, 39'088'169));
  EXPECT_EQ(1, GCD_ByDivRec(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesArbitrary) {
  EXPECT_EQ(2, GCD_ByDivRec(42, 2));
  EXPECT_EQ(2, GCD_ByDivRec(2, 42));
  EXPECT_EQ(6, GCD_ByDivRec(42, 6));
  EXPECT_EQ(6, GCD_ByDivRec(6, 42));
  EXPECT_EQ(7, GCD_ByDivRec(42, 35));
  EXPECT_EQ(7, GCD_ByDivRec(35, 42));
  EXPECT_EQ(6, GCD_ByDivRec(42, 30));
  EXPECT_EQ(6, GCD_ByDivRec(30, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, DISABLED_HandlesNegative) {
  EXPECT_EQ(1, GCD_ByDivRec(-2, -3));
  EXPECT_EQ(1, GCD_ByDivRec(-3, -2));
  EXPECT_EQ(7, GCD_ByDivRec(-42, -35));
  EXPECT_EQ(7, GCD_ByDivRec(-35, -42));
  EXPECT_EQ(6, GCD_ByDivRec(-42, -30));
  EXPECT_EQ(6, GCD_ByDivRec(-30, -42));
}
