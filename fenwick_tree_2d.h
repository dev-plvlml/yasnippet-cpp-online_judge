#ifndef FENWICK_TREE_2D_H_
#define FENWICK_TREE_2D_H_

#include <cstddef>
#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree2d {
 public:
  FenwickTree2d(size_t i_size, size_t j_size, T init = T())
      : data_(i_size),
        init_(init) {
    for (auto& data_i : data_) {
      data_i.resize(j_size, init);
    }
  }
  
  FenwickTree2d(const std::vector<std::vector<T>>& values, T init = T())
      : FenwickTree2d(values.size(), values[0].size(), init) {
    for (size_t i = 0; i < values.size(); ++i) {
      for (size_t j = 0; j < values[i].size(); ++j) {
        Set(i, j, values[i][j]);
      }
    }
  }
  
  T Get(size_t i, size_t j) const {
    return Query(i, 1, j, 1);
  }

  T Query(size_t i_count, size_t j_count) const {
    T result = init_;
    for (int i = (int)i_count - 1; i >= 0; i = F(i) - 1) {
      for (int j = (int)j_count - 1; j >= 0; j = F(j) - 1) {
        result = Function()(result, data_[i][j]);
      }
    }
    return result;
  }

  T Query(size_t i_pos, size_t i_count, size_t j_pos, size_t j_count) const {
    T result = Query(i_pos + i_count, j_pos + j_count);
    if (i_pos) result = InvFunction()(result, Query(i_pos, j_pos + j_count));
    if (j_pos) result = InvFunction()(result, Query(i_pos + i_count, j_pos));
    if (i_pos && j_pos) result = Function()(result, Query(i_pos, j_pos));
    return result;
  }

  void Set(size_t i, size_t j, T value) {
    Update(i, j, InvFunction()(value, data_[i][j]));
  }

  void Update(size_t i_pos, size_t j_pos, T delta) {
    for (size_t i = i_pos; i < data_.size(); i = H(i)) {
      for (size_t j = j_pos; j < data_[i].size(); j = H(j)) {
        data_[i][j] = Function()(data_[i][j], delta);
      }
    }
  }

 private:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }

 private:
  std::vector<std::vector<T>> data_;
  T init_;
};

#endif  // FENWICK_TREE_2D_H_
