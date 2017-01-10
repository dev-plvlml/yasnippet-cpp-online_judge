#include <gtest/gtest.h>

#include "palindrome_count_manacher_algorithm.h"

TEST(ManacherAlgorithm, OddPalindromes) {
  EXPECT_EQ(12, CountPalindromes("abacaba"));
}

TEST(ManacherAlgorithm, EvenPalindromes) {
  EXPECT_EQ(11, CountPalindromes("aabbaa"));
}

TEST(ManacherAlgorithm, EqualSequence) {
  EXPECT_EQ(15, CountPalindromes("aaaaa"));
}

TEST(ManacherAlgorithm, ArbitraryPalindromes) {
  EXPECT_EQ(6, CountPalindromes("abba"));
  EXPECT_EQ(9, CountPalindromes("aabaa"));
  EXPECT_EQ(11, CountPalindromes("abaaba"));
  EXPECT_EQ(14, CountPalindromes("aababaa"));
}

