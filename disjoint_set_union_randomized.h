#ifndef DISJOINT_SET_UNION_RANDOMIZED_H_
#define DISJOINT_SET_UNION_RANDOMIZED_H_

#include <cstdlib>
#include <numeric>
#include <utility>
#include <vector>

class DSU {
 public:
  DSU(size_t size);
  size_t FindSet(size_t id);
  size_t UniteSets(size_t id1, size_t id2);

 private:
  std::vector<size_t> parent_;
};

inline DSU::DSU(size_t size)
    : parent_(size) {
  std::iota(parent_.begin(), parent_.end(), 0);
}

inline size_t DSU::FindSet(size_t id) {
  if (parent_[id] != id) {
    // Naive approach:
    // return FindSet(parent_[id]);
    // Path compression:
    parent_[id] = FindSet(parent_[id]);
  }
  return parent_[id];
}

inline size_t DSU::UniteSets(size_t id1, size_t id2) {
  size_t parent1 = FindSet(id1);
  size_t parent2 = FindSet(id2);
  if (parent1 != parent2) {
    // Randomized union:
    if (rand() & 1) {
      std::swap(parent1, parent2);
    }
    parent_[parent2] = parent1;
  }
  return parent1;
}

#endif  // DISJOINT_SET_UNION_RANDOMIZED_H_
