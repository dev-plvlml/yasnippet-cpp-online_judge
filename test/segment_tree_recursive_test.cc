#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>
#include <gtest/gtest.h>

#include "segment_tree_minmax.h"
using namespace segm_tree;

#include "segment_tree_recursive.h"

TEST(SegmentTree, DefaultInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};
  std::vector<int> sums(numbers.size()), rsums(numbers.size());
  std::partial_sum(begin(numbers), end(numbers), begin(sums));
  std::partial_sum(rbegin(numbers), rend(numbers), begin(rsums));

  SegmentTree<int> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(numbers[i], tree.Get(i));
  }

  for (int i = 0, n = 1; n <= 6; ++n) {
    ASSERT_EQ(sums[n-1], tree.Query(i, n));
  }

  for (int i = 5, n = 1; n <= 6; --i, ++n) {
    ASSERT_EQ(rsums[n-1], tree.Query(i, n));
  }

  const int kAnswer = 42;
  for (int i = 0; i < 6; ++i) {
    tree.Set(i, kAnswer);
    ASSERT_EQ(kAnswer, tree.Get(i));
  }

  ASSERT_EQ(6 * kAnswer, tree.Query(0, 6));
}

TEST(SegmentTree, MinMaxInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};

  SegmentTree<MinMaxData, MinMaxData::Function, MinMaxData::Propagator> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(numbers[i], tree.Get(i).min);
    ASSERT_EQ(numbers[i], tree.Get(i).max);
  }

  for (int i = 0, n = 1; n <= 6; ++n) {
    ASSERT_EQ(*max_element(begin(numbers), next(begin(numbers), n)),
              tree.Query(i, n).max);
  }

  for (int i = 5, n = 1; n <= 6; --i, ++n) {
    ASSERT_EQ(*min_element(next(begin(numbers), i), end(numbers)),
              tree.Query(i, n).min);
  }

  const int kAnswer = 42;
  tree.Update(0, 6, std::make_pair(kColor, kAnswer));
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(kAnswer, tree.Get(i).min);
    ASSERT_EQ(kAnswer, tree.Get(i).max);
  }

  for (int i = 4, n = -4; i >= 0; --i, ++n) {
    tree.Update(i+n, i+1, std::make_pair(kDelta, numbers[i] - numbers[i+1]));
    ASSERT_EQ(numbers[i], tree.Get(i).max);
  }

  for (int i = 5, n = 1; n <= 6; ++n, --i) {
    ASSERT_EQ(*min_element(next(begin(numbers), i), end(numbers)),
              tree.Query(i, n).min);
  }
}
