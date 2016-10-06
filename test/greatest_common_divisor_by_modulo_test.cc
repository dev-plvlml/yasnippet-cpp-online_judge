#include <gtest/gtest.h>

#include "../greatest_common_divisor_by_modulo.h"

TEST(GreatestCommonDivisorByModuloTest, HandlesZero) {
  EXPECT_EQ(1, GCD(1, 0));
  EXPECT_EQ(1, GCD(0, 1));
  EXPECT_EQ(42, GCD(42, 0));
  EXPECT_EQ(42, GCD(0, 42));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesOne) {
  EXPECT_EQ(1, GCD(1, 1));
  EXPECT_EQ(1, GCD(1, 42));
  EXPECT_EQ(1, GCD(42, 1));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesEqual) {
  EXPECT_EQ(42, GCD(42, 42));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesPrime) {
  EXPECT_EQ(1, GCD(2, 3));
  EXPECT_EQ(1, GCD(3, 2));
  EXPECT_EQ(1, GCD(1'000'000'007, 1'000'000'009));
  EXPECT_EQ(1, GCD(1'000'000'009, 1'000'000'007));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesCoprime) {
  EXPECT_EQ(1, GCD(42, 55));
  EXPECT_EQ(1, GCD(55, 42));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesFibonacci) {
  EXPECT_EQ(1, GCD(5, 8));
  EXPECT_EQ(1, GCD(8, 5));
  EXPECT_EQ(1, GCD(24'157'817, 39'088'169));
  EXPECT_EQ(1, GCD(39'088'169, 24'157'817));
}

TEST(GreatestCommonDivisorByModuloTest, HandlesArbitrary) {
  EXPECT_EQ(2, GCD(42, 2));
  EXPECT_EQ(2, GCD(2, 42));
  EXPECT_EQ(6, GCD(42, 6));
  EXPECT_EQ(6, GCD(6, 42));
  EXPECT_EQ(7, GCD(42, 35));
  EXPECT_EQ(7, GCD(35, 42));
  EXPECT_EQ(6, GCD(42, 30));
  EXPECT_EQ(6, GCD(30, 42));
}

//TEST(GreatestCommonDivisorByModuloTest, HandlesNegative) {
//  EXPECT_EQ(1, GCD(-2, -3));
//  EXPECT_EQ(1, GCD(-3, -2));
//  EXPECT_EQ(7, GCD(-42, -35));
//  EXPECT_EQ(7, GCD(-35, -42));
//  EXPECT_EQ(6, GCD(-42, -30));
//  EXPECT_EQ(6, GCD(-30, -42));
//}
