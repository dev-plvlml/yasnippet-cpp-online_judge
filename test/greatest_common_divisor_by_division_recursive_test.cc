#include <gtest/gtest.h>

namespace recursive {
#include "../greatest_common_divisor_by_division_recursive.h"
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesZero) {
  EXPECT_EQ(1, recursive::GCD(1, 0));
  EXPECT_EQ(1, recursive::GCD(0, 1));
  EXPECT_EQ(42, recursive::GCD(42, 0));
  EXPECT_EQ(42, recursive::GCD(0, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesOne) {
  EXPECT_EQ(1, recursive::GCD(1, 1));
  EXPECT_EQ(1, recursive::GCD(1, 42));
  EXPECT_EQ(1, recursive::GCD(42, 1));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesEqual) {
  EXPECT_EQ(42, recursive::GCD(42, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesPrime) {
  EXPECT_EQ(1, recursive::GCD(2, 3));
  EXPECT_EQ(1, recursive::GCD(3, 2));
  EXPECT_EQ(1, recursive::GCD(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, recursive::GCD(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesCoprime) {
  EXPECT_EQ(1, recursive::GCD(42, 55));
  EXPECT_EQ(1, recursive::GCD(55, 42));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesFibonacci) {
  EXPECT_EQ(1, recursive::GCD(5, 8));
  EXPECT_EQ(1, recursive::GCD(8, 5));
  EXPECT_EQ(1, recursive::GCD(24'157'817, 39'088'169));
  EXPECT_EQ(1, recursive::GCD(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByModuloRecursive, HandlesArbitrary) {
  EXPECT_EQ(2, recursive::GCD(42, 2));
  EXPECT_EQ(2, recursive::GCD(2, 42));
  EXPECT_EQ(6, recursive::GCD(42, 6));
  EXPECT_EQ(6, recursive::GCD(6, 42));
  EXPECT_EQ(7, recursive::GCD(42, 35));
  EXPECT_EQ(7, recursive::GCD(35, 42));
  EXPECT_EQ(6, recursive::GCD(42, 30));
  EXPECT_EQ(6, recursive::GCD(30, 42));
}

//TEST(GreatestCommonDivisorByModuloRecursive, HandlesNegative) {
//  EXPECT_EQ(1, recursive::GCD(-2, -3));
//  EXPECT_EQ(1, recursive::GCD(-3, -2));
//  EXPECT_EQ(7, recursive::GCD(-42, -35));
//  EXPECT_EQ(7, recursive::GCD(-35, -42));
//  EXPECT_EQ(6, recursive::GCD(-42, -30));
//  EXPECT_EQ(6, recursive::GCD(-30, -42));
//}
