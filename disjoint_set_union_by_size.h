#include <numeric>
#include <utility>
#include <vector>

class DSU {
 public:
  DSU(size_t size);
  size_t FindSet(size_t key);
  size_t SetUnion(size_t key1, size_t key2);

 private:
  std::vector<size_t> parent_;
  std::vector<size_t> size_;
};

inline DSU::DSU(size_t size)
    : parent_(size),
      size_(size, 1) {
  std::iota(parent_.begin(), parent_.end(), 0);
}

inline size_t DSU::FindSet(size_t key) {
  if (parent_[key] == key) {
    return parent_[key];
  } else {
    // Naive approach:
    // return FindSet(parent_[key]); 
    // With path compression:
    return parent_[key] = FindSet(parent_[key]);
  }
}

inline size_t DSU::SetUnion(size_t key1, size_t key2) {
  size_t parent1 = FindSet(key1);
  size_t parent2 = FindSet(key2);
  if (parent1 == parent2) {
    return parent1;
  } else {
    // Union by size:
    if (size_[parent1] < size_[parent2]) {
      std::swap(parent1, parent2);
    }
    parent_[parent2] = parent1;
    size_[parent1] += size_[parent2];
    return parent1;
  }
}
