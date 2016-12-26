#ifndef DISJOINT_SET_UNION_BY_SIZE_H_
#define DISJOINT_SET_UNION_BY_SIZE_H_

#include <cstddef>
#include <numeric>
#include <utility>
#include <vector>

template <typename Tag>
class DSU;

struct DSU_BySize_Tag {};

template <>
class DSU<DSU_BySize_Tag> {
 public:
  DSU(size_t size);
  size_t FindSet(size_t id);
  size_t UniteSets(size_t id1, size_t id2);

 private:
  std::vector<size_t> parent_;
  std::vector<size_t> size_;
};

inline DSU<DSU_BySize_Tag>::DSU(size_t size)
    : parent_(size),
      size_(size, 1) {
  std::iota(parent_.begin(), parent_.end(), 0);
}

inline size_t DSU<DSU_BySize_Tag>::FindSet(size_t id) {
  if (parent_[id] != id) {
    // Naive approach:
    // return FindSet(parent_[id]);
    // Path compression:
    parent_[id] = FindSet(parent_[id]);
  }
  return parent_[id];
}

inline size_t DSU<DSU_BySize_Tag>::UniteSets(size_t id1, size_t id2) {
  size_t parent1 = FindSet(id1);
  size_t parent2 = FindSet(id2);
  if (parent1 != parent2) {
    // Union by size:
    if (size_[parent1] < size_[parent2]) {
      std::swap(parent1, parent2);
    }
    parent_[parent2] = parent1;
    size_[parent1] += size_[parent2];
  }
  return parent1;
}

#endif  // DISJOINT_SET_UNION_BY_SIZE_H_
