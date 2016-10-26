#include <algorithm>
#include <numeric>
#include <vector>
#include <gtest/gtest.h>

#include "../fenwick_tree.h"

TEST(FenwickTree, DefaultInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};
  std::vector<int>  sums(numbers.size()), rsums(numbers.size());
  std::partial_sum(begin(numbers), end(numbers), begin(sums));
  std::partial_sum(rbegin(numbers), rend(numbers), begin(rsums));

  FenwickTree<int> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(numbers[i], tree.Get(i));
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
