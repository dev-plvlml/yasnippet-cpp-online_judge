#include <gtest/gtest.h>

#include "greatest_common_divisor_by_division_recursive.h"

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesZero) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(1, 0));
  EXPECT_EQ(1, GCD_ByDiv_Rec(0, 1));
  EXPECT_EQ(42, GCD_ByDiv_Rec(42, 0));
  EXPECT_EQ(42, GCD_ByDiv_Rec(0, 42));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesOne) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(1, 1));
  EXPECT_EQ(1, GCD_ByDiv_Rec(1, 42));
  EXPECT_EQ(1, GCD_ByDiv_Rec(42, 1));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesEqual) {
  EXPECT_EQ(42, GCD_ByDiv_Rec(42, 42));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesPrime) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(2, 3));
  EXPECT_EQ(1, GCD_ByDiv_Rec(3, 2));
  EXPECT_EQ(1, GCD_ByDiv_Rec(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, GCD_ByDiv_Rec(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesCoprime) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(42, 55));
  EXPECT_EQ(1, GCD_ByDiv_Rec(55, 42));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesFibonacci) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(5, 8));
  EXPECT_EQ(1, GCD_ByDiv_Rec(8, 5));
  EXPECT_EQ(1, GCD_ByDiv_Rec(24'157'817, 39'088'169));
  EXPECT_EQ(1, GCD_ByDiv_Rec(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByDivisionRecursive, HandlesArbitrary) {
  EXPECT_EQ(2, GCD_ByDiv_Rec(42, 2));
  EXPECT_EQ(2, GCD_ByDiv_Rec(2, 42));
  EXPECT_EQ(6, GCD_ByDiv_Rec(42, 6));
  EXPECT_EQ(6, GCD_ByDiv_Rec(6, 42));
  EXPECT_EQ(7, GCD_ByDiv_Rec(42, 35));
  EXPECT_EQ(7, GCD_ByDiv_Rec(35, 42));
  EXPECT_EQ(6, GCD_ByDiv_Rec(42, 30));
  EXPECT_EQ(6, GCD_ByDiv_Rec(30, 42));
}

TEST(GreatestCommonDivisorByDivisionRecursive, DISABLED_HandlesNegative) {
  EXPECT_EQ(1, GCD_ByDiv_Rec(-2, -3));
  EXPECT_EQ(1, GCD_ByDiv_Rec(-3, -2));
  EXPECT_EQ(7, GCD_ByDiv_Rec(-42, -35));
  EXPECT_EQ(7, GCD_ByDiv_Rec(-35, -42));
  EXPECT_EQ(6, GCD_ByDiv_Rec(-42, -30));
  EXPECT_EQ(6, GCD_ByDiv_Rec(-30, -42));
}
