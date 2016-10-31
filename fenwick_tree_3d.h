#ifndef FENWICK_TREE_3D_H_
#define FENWICK_TREE_3D_H_

#include <cstddef>
#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree3d {
 public:
  FenwickTree3d(size_t i_size, size_t j_size, size_t k_size, T init = T())
      : data_(i_size),
        init_(init) {
    for (auto& data_i : data_) {
      data_i.resize(j_size);
      for (auto& data_i_j : data_i) {
        data_i_j.resize(k_size, init);
      }
    }
  }
  
  FenwickTree3d(const std::vector<std::vector<std::vector<T>>>& values, T init = T())
      : FenwickTree3d(values.size(), values[0].size(), values[0][0].size(), init) {
    for (size_t i = 0; i < values.size(); ++i) {
      for (size_t j = 0; j < values[i].size(); ++j) {
        for (size_t k = 0; k < values[i][j].size(); ++k) {
          Set(i, j, k, values[i][j][k]);
        }
      }
    }
  }
  
  T Get(size_t i, size_t j, size_t k) const {
    return Query(i, 1, j, 1, k, 1);
  }

  T Query(size_t i_count, size_t j_count, size_t k_count) const {
    T result = init_;
    for (int i = int{i_count} - 1; i >= 0; i = F(i) - 1) {
      for (int j = int{j_count} - 1; j >= 0; j = F(j) - 1) {
        for (int k = int{k_count} - 1; k >= 0; k = F(k) - 1) {
          result = Function()(result, data_[i][j][k]);
        }
      }
    }
    return result;
  }

  T Query(size_t i_pos, size_t i_count, size_t j_pos, size_t j_count, size_t k_pos, size_t k_count) const {
    T result = Query(i_pos + i_count, j_pos + j_count, k_pos + k_count);
    if (i_pos) result = InvFunction()(result, Query(i_pos, j_pos + j_count, k_pos + k_count));
    if (j_pos) result = InvFunction()(result, Query(i_pos + i_count, j_pos, k_pos + k_count));
    if (k_pos) result = InvFunction()(result, Query(i_pos + i_count, j_pos + j_count, k_pos));
    if (i_pos && j_pos) result = Function()(result, Query(i_pos, j_pos, k_pos + k_count));
    if (i_pos && k_pos) result = Function()(result, Query(i_pos, j_pos + j_count, k_pos));
    if (j_pos && k_pos) result = Function()(result, Query(i_pos + i_count, j_pos, k_pos));
    if (i_pos && j_pos && k_pos) result = InvFunction()(result, Query(i_pos, j_pos, k_pos));
    return result;
  }

  void Set(size_t i, size_t j, size_t k, T value) {
    Update(i, j, k, InvFunction()(value, data_[i][j][k]));
  }

  void Update(size_t i_pos, size_t j_pos, size_t k_pos, T delta) {
    for (size_t i = i_pos; i < data_.size(); i = H(i)) {
      for (size_t j = j_pos; j < data_[i].size(); j = H(j)) {
        for (size_t k = k_pos; k < data_[i][j].size(); k = H(k)) {
          data_[i][j][k] = Function()(data_[i][j][k], delta);
        }
      }
    }
  }

 protected:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }

 private:
  std::vector<std::vector<std::vector<T>>> data_;
  T init_;
};

#endif  // FENWICK_TREE_3D_H_
