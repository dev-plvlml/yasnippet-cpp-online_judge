#include <cstddef>
#include <gtest/gtest.h>

#include "palindromic_tree.h"

TEST(PalindromicTree, OddPalindromes) {
  PalindromicTree abacaba;

  abacaba.PushBack('a');
  ASSERT_EQ(1, abacaba.Size());

  abacaba.PushBack('b');
  ASSERT_EQ(2, abacaba.Size());

  abacaba.PushBack('a');
  ASSERT_EQ(3, abacaba.Size());

  abacaba.PushBack('c');
  ASSERT_EQ(4, abacaba.Size());

  abacaba.PushBack('a');
  ASSERT_EQ(5, abacaba.Size());

  abacaba.PushBack('b');
  ASSERT_EQ(6, abacaba.Size());

  abacaba.PushBack('a');
  ASSERT_EQ(7, abacaba.Size());
}

TEST(PalindromicTree, EvenPalindromes) {
  PalindromicTree aabbaa;

  aabbaa.PushBack('a');
  ASSERT_EQ(1, aabbaa.Size());

  aabbaa.PushBack('a');
  ASSERT_EQ(2, aabbaa.Size());

  aabbaa.PushBack('b');
  ASSERT_EQ(3, aabbaa.Size());

  aabbaa.PushBack('b');
  ASSERT_EQ(4, aabbaa.Size());

  aabbaa.PushBack('a');
  ASSERT_EQ(5, aabbaa.Size());

  aabbaa.PushBack('a');
  ASSERT_EQ(6, aabbaa.Size());
}

TEST(PalindromicTree, EqualSequence) {
  PalindromicTree aaaaa;
  for (size_t i = 1; i <= 5; ++i) {
    aaaaa.PushBack('a');
    ASSERT_EQ(i, aaaaa.Size());
  }
}

TEST(PalindromicTree, ArbitraryPalindromes) {
  PalindromicTree abba("abba");
  EXPECT_EQ(4, abba.Size());

  PalindromicTree aabaa("aabaa");
  EXPECT_EQ(5, aabaa.Size());

  PalindromicTree abaaba("abaaba");
  EXPECT_EQ(6, abaaba.Size());

  PalindromicTree aababaa("aababaa");
  EXPECT_EQ(7, aababaa.Size());
}
