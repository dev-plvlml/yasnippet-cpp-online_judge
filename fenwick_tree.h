#ifndef FENWICK_TREE_H_
#define FENWICK_TREE_H_

#include <cstddef>
#include <functional>
#include <iterator>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree {
 public:
  FenwickTree(size_t size, T init = T())
      : data_(size, init),
        init_(init)
  {}

  template <typename It = T*>
  FenwickTree(It first, It last, T init = T())
      // NOTE: Delegation constructor fails
      : data_(std::distance(first, last), init),
        init_(init) {
    size_t i = 0;
    for (It it = first; it < last; ++it, ++i) {
      Set(i, *it);
    }
  }
  
  T Get(size_t pos) const {
    return Query(pos, 1);
  }

  T Query(size_t count) const {
    T result = init_;
    for (int i = (int)count - 1; i >= 0; i = F(i) - 1) {
      result = Function()(result, data_[i]);
    }
    return result;
  }

  T Query(size_t pos, size_t count) const {
    T result = Query(pos + count);
    if (pos != 0) {
      result = InvFunction()(result, Query(pos));
    }
    return result;
  }

  void Set(size_t pos, T value) {
    Update(pos, InvFunction()(value, Get(pos)));
  }

  void Update(size_t pos, T delta) {
    for (size_t i = pos; i < data_.size(); i = H(i)) {
      data_[i] = Function()(data_[i], delta);
    }
  }

 private:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }
  
 private:
  std::vector<T> data_;
  const T init_;
};

#endif  // FENWICK_TREE_H_
