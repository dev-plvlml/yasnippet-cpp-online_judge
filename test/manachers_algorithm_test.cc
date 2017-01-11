#include <gtest/gtest.h>

#include "manachers_algorithm.h"

TEST(ManachersAlgorithm, OddPalindromes) {
  EXPECT_EQ(12, CountPalindromes("abacaba"));
  EXPECT_EQ("abacaba", LPS("abacaba"));
}

TEST(ManachersAlgorithm, EvenPalindromes) {
  EXPECT_EQ(11, CountPalindromes("aabbaa"));
  EXPECT_EQ("aabbaa", LPS("aabbaa"));
}

TEST(ManachersAlgorithm, EqualSequence) {
  EXPECT_EQ(15, CountPalindromes("aaaaa"));
  EXPECT_EQ("aaaaa", LPS("aaaaa"));
}

TEST(ManachersAlgorithm, ArbitraryPalindromes) {
  EXPECT_EQ(6, CountPalindromes("abba"));
  EXPECT_EQ(9, CountPalindromes("aabaa"));
  EXPECT_EQ(11, CountPalindromes("abaaba"));
  EXPECT_EQ(14, CountPalindromes("aababaa"));
  EXPECT_EQ("abba", LPS("abba"));
  EXPECT_EQ("aabaa", LPS("aabaa"));
  EXPECT_EQ("abaaba", LPS("abaaba"));
  EXPECT_EQ("aababaa", LPS("aababaa"));
}

TEST(ManachersAlgorithm, ArbitrarySequences) {
  EXPECT_EQ("addda", LPS("abaccaddda"));
}
