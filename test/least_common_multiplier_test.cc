#include <gtest/gtest.h>

#include "../greatest_common_divisor_by_division.h"
#include "../least_common_multiplier.h"

TEST(LeastCommonMultiplier, HandlesOne) {
  EXPECT_EQ(1, LCM(1, 1));
  EXPECT_EQ(42, LCM(1, 42));
  EXPECT_EQ(42, LCM(42, 1));
}

TEST(LeastCommonMultiplier, HandlesEqual) {
  EXPECT_EQ(42, LCM(42, 42));
}

TEST(LeastCommonMultiplier, HandlesPrime) {
  EXPECT_EQ(2 * 3, LCM(2, 3));
  EXPECT_EQ(3 * 2, LCM(3, 2));
  EXPECT_EQ(101 * 103, LCM(101, 103));
  EXPECT_EQ(103 * 101, LCM(103, 101));
  EXPECT_EQ(107 * 109, LCM(107, 109));
  EXPECT_EQ(109 * 107, LCM(109, 107));
  EXPECT_EQ(45007 * 45013, LCM(45007, 45013));
  EXPECT_EQ(45013 * 45007, LCM(45013, 45007));
}

TEST(LeastCommonMultiplier, HandlesCoprime) {
  EXPECT_EQ(42 * 55, LCM(42, 55));
  EXPECT_EQ(55 * 42, LCM(55, 42));
}

TEST(LeastCommonMultiplier, HandlesFibonacci) {
  EXPECT_EQ(5 * 8, LCM(5, 8));
  EXPECT_EQ(8 * 5, LCM(8, 5));
  EXPECT_EQ(28657 * 46368, LCM(28657, 46368));
  EXPECT_EQ(46368 * 28657, LCM(46368, 28657));
}

TEST(LeastCommonMultiplier, HandlesArbitrary) {
  EXPECT_EQ(42, LCM(42, 2));
  EXPECT_EQ(42, LCM(2, 42));
  EXPECT_EQ(42, LCM(42, 6));
  EXPECT_EQ(42, LCM(6, 42));
  EXPECT_EQ(6 * 7 * 5, LCM(42, 35));
  EXPECT_EQ(5 * 7 * 6, LCM(35, 42));
  EXPECT_EQ(7 * 6 * 5, LCM(42, 30));
  EXPECT_EQ(5 * 6 * 7, LCM(30, 42));
}

TEST(LeastCommonMultiplier, HandlesNegative) {
  EXPECT_EQ(2 * 3, LCM(-2, -3));
  EXPECT_EQ(3 * 2, LCM(-3, -2));
  EXPECT_EQ(6 * 7 * 5, LCM(-42, -35));
  EXPECT_EQ(5 * 7 * 6, LCM(-35, -42));
  EXPECT_EQ(7 * 6 * 5, LCM(-42, -30));
  EXPECT_EQ(5 * 6 * 7, LCM(-30, -42));
}
