#include <gtest/gtest.h>

#include "suffix_automaton.h"

TEST(SuffixAutomaton, a) {
  DAWG dawg("a");
  EXPECT_EQ(true, dawg.IsSubstr(""));
  EXPECT_EQ(true, dawg.IsSubstr("a"));
  EXPECT_EQ(false, dawg.IsSubstr("b"));
  EXPECT_EQ(false, dawg.IsSubstr("aa"));
  EXPECT_EQ(false, dawg.IsSubstr("ab"));
  EXPECT_EQ(false, dawg.IsSubstr("ba"));
  EXPECT_EQ(false, dawg.IsSubstr("bb"));
}

TEST(SuffixAutomaton, aa) {
  DAWG dawg("aa");
  EXPECT_EQ(true, dawg.IsSubstr(""));
  EXPECT_EQ(true, dawg.IsSubstr("a"));
  EXPECT_EQ(false, dawg.IsSubstr("b"));
  EXPECT_EQ(true, dawg.IsSubstr("aa"));
  EXPECT_EQ(false, dawg.IsSubstr("ab"));
  EXPECT_EQ(false, dawg.IsSubstr("ba"));
  EXPECT_EQ(false, dawg.IsSubstr("bb"));
  EXPECT_EQ(false, dawg.IsSubstr("aaa"));
  EXPECT_EQ(false, dawg.IsSubstr("aab"));
}

TEST(SuffixAutomaton, ab) {
  DAWG dawg("ab");
  EXPECT_EQ(true, dawg.IsSubstr(""));
  EXPECT_EQ(true, dawg.IsSubstr("a"));
  EXPECT_EQ(true, dawg.IsSubstr("b"));
  EXPECT_EQ(false, dawg.IsSubstr("aa"));
  EXPECT_EQ(true, dawg.IsSubstr("ab"));
  EXPECT_EQ(false, dawg.IsSubstr("ba"));
  EXPECT_EQ(false, dawg.IsSubstr("bb"));
  EXPECT_EQ(false, dawg.IsSubstr("aba"));
  EXPECT_EQ(false, dawg.IsSubstr("abb"));
}

TEST(SuffixAutomaton, aba) {
  DAWG dawg("aba");
  EXPECT_EQ(true, dawg.IsSubstr(""));
  EXPECT_EQ(true, dawg.IsSubstr("a"));
  EXPECT_EQ(true, dawg.IsSubstr("b"));
  EXPECT_EQ(false, dawg.IsSubstr("aa"));
  EXPECT_EQ(true, dawg.IsSubstr("ab"));
  EXPECT_EQ(true, dawg.IsSubstr("ba"));
  EXPECT_EQ(false, dawg.IsSubstr("bb"));
  EXPECT_EQ(true, dawg.IsSubstr("aba"));
  EXPECT_EQ(false, dawg.IsSubstr("abb"));
  EXPECT_EQ(false, dawg.IsSubstr("baa"));
  EXPECT_EQ(false, dawg.IsSubstr("bab"));
}
