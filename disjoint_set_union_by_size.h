#include <numeric>
#include <utility>
#include <vector>

class DSU {
 public:
  DSU(size_t size)
      : parent_(size),
        size_(size, 1) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  size_t FindSet(size_t key) {
    if (parent_[key] == key) {
      return parent_[key];
    } else {
      // Naive approach:
      // return FindSet(parent_[key]); 
      // With path compression:
      return parent_[key] = FindSet(parent_[key]);
    }
  }

  pair<size_t, bool> SetUnion(size_t key1, size_t key2) {
    size_t parent1 = FindSet(key1);
    size_t parent2 = FindSet(key2);
    if (parent1 == parent2) {
      return {parent2, false};
    } else {
      // Union by size:
      if (size_[parent1] > size_[parent2]) {
        swap(parent1, parent2);
      }
      parent_[parent1] = parent2;
      size_[parent2] += size_[parent1];
      return {parent2, true};
    }
  }

 private:
  vector<size_t> parent_;
  vector<size_t> size_;
};
