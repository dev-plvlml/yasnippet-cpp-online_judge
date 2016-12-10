#include <gtest/gtest.h>

#include "pi_function.h"

using Vsz = std::vector<size_t>;

TEST(PiFunction, CormenSequence) {
  EXPECT_EQ(Vsz({0,0,1,2,3,0,1}), GetPiFunction("ababaca"));
}

TEST(PiFunction, EmaxxSequences) {
  EXPECT_EQ(Vsz({0,0,0,1,2,3,0}), GetPiFunction("abcabcd"));
  EXPECT_EQ(Vsz({0,1,0,1,2,2,3}), GetPiFunction("aabaaab"));
}

TEST(PiFunction, EqualSequence) {
  EXPECT_EQ(Vsz({0,1,2,3,4,5,6}), GetPiFunction("aaaaaaa"));
}
