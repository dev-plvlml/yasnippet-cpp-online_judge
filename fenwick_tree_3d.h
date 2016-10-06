#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree3d {
 public:
  FenwickTree3d(size_t i_size, size_t j_size, size_t k_size, T init = T())
      : tree_(i_size),
        init_(init) {
    for (auto& tree_i : tree_) {
      tree_i.resize(j_size);
      for (auto& tree_i_j : tree_i) {
        tree_i_j.resize(k_size, init);
      }
    }
  }
  
  FenwickTree3d(const std::vector<std::vector<std::vector<T>>>& values, T init = T())
      : FenwickTree3d(values.size(), values[0].size(), values[0][0].size(), init) {
    for (size_t i = 0; i < values.size(); ++i) {
      for (size_t j = 0; j < values[i].size(); ++j) {
        for (size_t k = 0; k < values[i][j].size(); ++k) {
          Assign(i, j, k, values[i][j][k]);
        }
      }
    }
  }
    
  void Assign(size_t i, size_t j, size_t k, T value) {
    Update(i, j, k, InvFunction()(value, tree_[i][j][k]));
  }
  
  T Get(size_t i, size_t j, size_t k) const {
    return Query(i, i, j, j, k, k);
  }

  T Query(size_t i0, size_t j0, size_t k0) const {
    T result = init_;
    for (int i = int{i0}; i >= 0; i = F(i) - 1) {
      for (int j = int{j0}; j >= 0; j = F(j) - 1) {
        for (int k = int{k0}; k >= 0; k = F(k) - 1) {
          result = Function()(result, tree_[i][j][k]);
        }
      }
    }
    return result;
  }

  T Query(size_t i1, size_t i2, size_t j1, size_t j2, size_t k1, size_t k2) const {
    T result = Query(i2, j2, k2);
    if (i1) result = InvFunction()(result, Query(i1 - 1, j2, k2));
    if (j1) result = InvFunction()(result, Query(i2, j1 - 1, k2));
    if (k1) result = InvFunction()(result, Query(i2, j2, k1 - 1));
    if (i1 && j1) result = Function()(result, Query(i1 - 1, j1 - 1, k2));
    if (i1 && k1) result = Function()(result, Query(i1 - 1, j2, k1 - 1));
    if (j1 && k1) result = Function()(result, Query(i2, j1 - 1, k1 - 1));
    if (i1 && j1 && k1) result = InvFunction()(result, Query(i1 - 1, j1 - 1, k1 - 1));
    return result;
  }

  void Update(size_t i0, size_t j0, size_t k0, T delta) {
    for (size_t i = i0; i < tree_.size(); i = H(i)) {
      for (size_t j = j0; j < tree_[i].size(); j = H(j)) {
        for (size_t k = k0; k < tree_[i][j].size(); k = H(k)) {
          tree_[i][j][k] = Function()(tree_[i][j][k], delta);
        }
      }
    }
  }

 protected:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }

 private:
  std::vector<std::vector<std::vector<T>>> tree_;
  T init_;
};
