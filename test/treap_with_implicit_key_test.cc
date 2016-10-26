#include <algorithm>
#include <numeric>
#include <vector>
#include <gtest/gtest.h>

#include "treap_with_implicit_key_sum.h"
#include "treap_with_implicit_key_minmax.h"
using namespace treap;

#include "../treap_with_implicit_key.h"

TEST(TreapWithImplicitKey, DefaultInstanceArbitraryInsertSequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};
  Treap<int> treap;

  treap.Insert(0, 23);
  ASSERT_EQ(23, treap.Get(0));

  treap.Insert(1, 42);
  ASSERT_EQ(23, treap.Get(0));
  ASSERT_EQ(42, treap.Get(1));

  treap.Insert(0, 4);
  treap.Insert(1, 8);
  ASSERT_EQ(4, treap.Get(0));
  ASSERT_EQ(8, treap.Get(1));
  ASSERT_EQ(23, treap.Get(2));
  ASSERT_EQ(42, treap.Get(3));

  treap.Insert(2, 15);
  treap.Insert(3, 16);
  ASSERT_EQ(4, treap.Get(0));
  ASSERT_EQ(8, treap.Get(1));
  ASSERT_EQ(15, treap.Get(2));
  ASSERT_EQ(16, treap.Get(3));
  ASSERT_EQ(23, treap.Get(4));
  ASSERT_EQ(42, treap.Get(5));
}

TEST(TreapWithImplicitKey, SumInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};
  std::vector<int>  sums(numbers.size()), rsums(numbers.size());
  std::partial_sum(begin(numbers), end(numbers), begin(sums));
  std::partial_sum(rbegin(numbers), rend(numbers), begin(rsums));

  using namespace treap;
  Treap<SumData, SumData::Maintainer> tree(numbers);
  for (int i = 0; i < 6; ++i) {
    ASSERT_EQ(numbers[i], tree.Get(i).value);
  }

  for (int i = 0, n = 1; n <= 6; ++n) {
    ASSERT_EQ(sums[n-1], tree.Query(i, n).sum);
  }

  for (int i = 5, n = 1; n <= 6; --i, ++n) {
    ASSERT_EQ(rsums[n-1], tree.Query(i, n).sum);
  }

  const int kAnswer = 42;
  for (int i = 0; i < 6; ++i) {
    tree.Set(i, kAnswer);
    ASSERT_EQ(kAnswer, tree.Get(i).value);
  }

  ASSERT_EQ(6 * kAnswer, tree.Query(0, 6).sum);
}

TEST(TreapWithImplicitKey, MinMaxInstanceArbitrarySequence) {
  std::vector<int> numbers = {4, 8, 15, 16, 23, 42};

  Treap<MinMaxData, MinMaxData::Maintainer, MinMaxData::Propagator> tree(numbers);
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
