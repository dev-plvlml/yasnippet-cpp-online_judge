class DSU {
 public:
  DSU(size_t size)
      : parent_(size) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  size_t FindSet(size_t key) {
    if (parent_[key] == key) {
      return parent_[key];
    } else {
      // Without path compression:
      // return FindSet(parent_[key]); 
      // With path compression:
      return parent_[key] = FindSet(parent_[key]);
    }
  }

  pair<size_t, bool> SetUnion(size_t key1, size_t key2) {
    size_t parent1 = FindSet(key1);
    size_t parent2 = FindSet(key2);
    if (parent1 == parent2) {
      return { parent2, false };
    } else {
      // Randomized union:
      if (rand() & 1) {
        swap(parent1, parent2);
      }
      parent_[parent1] = parent2;
      return { parent2, true };
    }
  }

 private:
  vector<size_t> parent_;
};
