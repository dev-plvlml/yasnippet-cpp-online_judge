#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <gtest/gtest.h>

#include "minmax_lazy_propagation.h"
#include "../segment_tree.h"

TEST(SegmentTree, DefaultInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42}, sums(6);

  SegmentTree<int> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(numbers[i], tree.Get(i));
  }

  std::partial_sum(begin(numbers), end(numbers), begin(sums));
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(sums[i], tree.Query(0, i));
  }

  std::partial_sum(rbegin(numbers), rend(numbers), rbegin(sums));
  for (int i = 5; i >= 0; --i) {
    ASSERT_EQ(sums[i], tree.Query(i, 5));
  }

  const int kAnswer = 42;
  tree.Set(0, kAnswer);
  ASSERT_EQ(kAnswer, tree.Get(0));
  tree.Set(1, kAnswer);
  tree.Set(2, kAnswer);
  ASSERT_EQ(kAnswer, tree.Get(1));
  ASSERT_EQ(kAnswer, tree.Get(2));
  tree.Set(3, kAnswer);
  tree.Set(4, kAnswer);
  tree.Set(5, kAnswer);
  ASSERT_EQ(kAnswer, tree.Get(3));
  ASSERT_EQ(kAnswer, tree.Get(4));
  ASSERT_EQ(kAnswer, tree.Get(5));

  ASSERT_EQ(kAnswer * 6, tree.Query(0, 5));
}

TEST(SegmentTree, MinMaxInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};

  SegmentTree<Data, Function, Propagator> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(numbers[i], tree.Get(i).min);
  }
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(*max_element(begin(numbers), next(begin(numbers), i + 1)),
              tree.Query(0, i).max);
  }

  const int kAnswer = 42;
  tree.Update(0, 5, std::make_pair(kColor, kAnswer));
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(kAnswer, tree.Get(i).max);
  }

  tree.Update(0, 4, std::make_pair(kDelta, numbers[4] - numbers[5]));
  ASSERT_EQ(numbers[4], tree.Get(4).max);
  tree.Update(0, 3, std::make_pair(kDelta, numbers[3] - numbers[4]));
  ASSERT_EQ(numbers[3], tree.Get(3).max);
  tree.Update(0, 2, std::make_pair(kDelta, numbers[2] - numbers[3]));
  tree.Update(0, 1, std::make_pair(kDelta, numbers[1] - numbers[2]));
  tree.Update(0, 0, std::make_pair(kDelta, numbers[0] - numbers[1]));
  ASSERT_EQ(numbers[2], tree.Get(2).max);
  ASSERT_EQ(numbers[1], tree.Get(1).max);
  ASSERT_EQ(numbers[0], tree.Get(0).max);

  for (int i = 5; i >= 0; --i) {
    ASSERT_EQ(*min_element(next(begin(numbers), i), end(numbers)),
              tree.Query(i, 5).min);
  }
}
