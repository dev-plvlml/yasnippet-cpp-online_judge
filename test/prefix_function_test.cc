#include <cstddef>
#include <vector>
#include <gtest/gtest.h>

#include "prefix_function.h"

using Vsz = std::vector<size_t>;

TEST(PiFunction, CormenSequence) {
  EXPECT_EQ(Vsz({0,0,1,2,3,0,1}), GetPrefixFunction("ababaca"));
}

TEST(PiFunction, EmaxxSequences) {
  EXPECT_EQ(Vsz({0,0,0,1,2,3,0}), GetPrefixFunction("abcabcd"));
  EXPECT_EQ(Vsz({0,1,0,1,2,2,3}), GetPrefixFunction("aabaaab"));
}

TEST(PiFunction, EqualSequence) {
  EXPECT_EQ(Vsz({0,1,2,3,4,5,6}), GetPrefixFunction("aaaaaaa"));
}
