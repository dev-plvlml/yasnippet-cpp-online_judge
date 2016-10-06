#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree2d {
 public:
  FenwickTree2d(size_t i_size, size_t j_size, T init = T())
      : tree_(i_size),
        init_(init) {
    for (auto& tree_i : tree_) {
      tree_i.resize(j_size, init);
    }
  }
  
  FenwickTree2d(const std::vector<std::vector<T>>& values, T init = T())
      : FenwickTree2d(values.size(), values[0].size(), init) {
    for (size_t i = 0; i < values.size(); ++i) {
      for (size_t j = 0; j < values[i].size(); ++j) {
        Assign(i, j, values[i][j]);
      }
    }
  }
    
  void Assign(size_t i, size_t j, T value) {
    Update(i, j, InvFunction()(value, tree_[i][j]));
  }
  
  T Get(size_t i, size_t j) const {
    return Query(i, i, j, j);
  }

  T Query(size_t i0, size_t j0) const {
    T result = init_;
    for (int i = int{i0}; i >= 0; i = F(i) - 1) {      
      for (int j = int{j0}; j >= 0; j = F(j) - 1) {
        result = Function()(result, tree_[i][j]);
      }
    }
    return result;
  }

  T Query(size_t i1, size_t i2, size_t j1, size_t j2) const {
    T result = Query(i2, j2);
    if (i1) result = InvFunction()(result, Query(i1 - 1, j2));
    if (j1) result = InvFunction()(result, Query(i2, j1 - 1));
    if (i1 && j1) result = Function()(result, Query(i1 - 1, j1 - 1));
    return result;
  }

  void Update(size_t i0, size_t j0, T delta) {    
    for (size_t i = i0; i < tree_.size(); i = H(i)) {      
      for (size_t j = j0; j < tree_[i].size(); j = H(j)) {
        tree_[i][j] = Function()(tree_[i][j], delta);
      }
    }
  }

 protected:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }

 private:
  std::vector<std::vector<T>> tree_;
  T init_;
};
