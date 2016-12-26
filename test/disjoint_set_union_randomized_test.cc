#include <gtest/gtest.h>

#include "disjoint_set_union_randomized.h"

TEST(DisjointSetUnionRandomized, MinimalCase) {
  DSU<DSU_Randomized_Tag> dsu(3);

  dsu.UniteSets(0, 1);
  EXPECT_EQ(true, dsu.FindSet(0) == dsu.FindSet(1));

  dsu.UniteSets(1, 2);
  EXPECT_EQ(true, dsu.FindSet(1) == dsu.FindSet(2));

  EXPECT_EQ(true, dsu.FindSet(0) == dsu.FindSet(2));
}
