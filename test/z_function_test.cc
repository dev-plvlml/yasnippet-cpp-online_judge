#include <cstddef>
#include <vector>
#include <gtest/gtest.h>

#include "z_function.h"

using Vsz = std::vector<size_t>;

TEST(ZFunction, EmaxxSequences) {
  EXPECT_EQ(Vsz({7,2,1,0,2,1,0}), GetZFunction("aaabaab"));
  EXPECT_EQ(Vsz({7,0,1,0,3,0,1}), GetZFunction("abacaba"));
}

TEST(ZFunction, EqualSequence) {
  EXPECT_EQ(Vsz({7,6,5,4,3,2,1}), GetZFunction("aaaaaaa"));
}
