#ifndef SEGMENT_TREE_H_
#define SEGMENT_TREE_H_

#include <algorithm>
#include <cstddef>
#include <functional>
#include <vector>

template <typename T>
struct NullPropagator {
  void operator()(T& root, T* left, T* right) {}
};

template <typename T, class Function = std::plus<T>,
          class LazyPropagation = NullPropagator<T>>
class SegmentTree {
 public:
  template <typename U = T>
  SegmentTree(const std::vector<U>& values)
      : data_(4 * values.size()),
        size_(values.size()) {
    Build(values, Root(), LRoot(), RRoot());
  }

  template <class Visitor>
  Visitor& Accept(size_t pos, size_t count, Visitor& visitor) {
    return Accept(pos, pos + count, visitor, Root(), LRoot(), RRoot());
  }

  T Get(size_t pos) {
    return Query(pos, 1);
  }

  T Query(size_t pos, size_t count) {
    return Query(pos, pos + count, Root(), LRoot(), RRoot());
  }

  template <typename U = T>
  void Set(size_t pos, U value) {
    Update(pos, 1, value);
  }

  template <typename U>
  void Update(size_t pos, size_t count, U metadata) {
    Update(pos, pos + count, metadata, Root(), LRoot(), RRoot());
  }

 private:
  template <class Visitor>
  Visitor& Accept(size_t l, size_t r, Visitor& visitor,
                  size_t v, size_t lv, size_t rv) {
    if (l >= r) return visitor;  // Shortening code
    Push(v, lv, rv);
    if (l == lv && r == rv)
      return visitor(data_[v]);
    size_t mv = Median(lv, rv);
    Accept(l, std::min(mv, r), visitor, Left(v), lv, mv);
    Accept(std::max(l, mv), r, visitor, Right(v), mv, rv);
    return visitor;
  }

  template <typename U = T>
  void Build(const std::vector<U>& values,
             size_t v, size_t lv, size_t rv) {
    if (rv - lv == 1)
      return (void) (data_[v] = values[lv]);
    size_t mv = Median(lv, rv);
    Build(values, Left(v), lv, mv);
    Build(values, Right(v), mv, rv);
    data_[v] = Calc(v, lv, rv);
  }

  T Query(size_t l, size_t r,
          size_t v, size_t lv, size_t rv) {
    Push(v, lv, rv);
    if (l == lv && r == rv)
      return data_[v];
    size_t mv = Median(lv, rv);
    // NB: cannot be shortened?
    if (r <= mv)
      return Query(l, r, Left(v), lv, mv);
    if (l >= mv)
      return Query(l, r, Right(v), mv, rv);
    return Function()(Query(l, mv, Left(v), lv, mv),
                      Query(mv, r, Right(v), mv, rv));
  }

  template <typename U>
  void Update(size_t l, size_t r, U metadata,
              size_t v, size_t lv, size_t rv) {
    // Shortening code
    if (l >= r) return;
    Push(v, lv, rv);
    if (l == lv && r == rv)
      return (void) (data_[v] = metadata);
    size_t mv = Median(lv, rv);
    Update(l, std::min(mv, r), metadata, Left(v), lv, mv);
    Update(std::max(l, mv), r, metadata, Right(v), mv, rv);
    Push(Left(v), lv, mv);
    Push(Right(v), mv, rv);
    data_[v] = Calc(v, lv, rv);
  }

 private:
  T* Data(size_t v) { return v < data_.size() ? &data_[v] : nullptr; }
  
  T Calc(size_t v, size_t lv, size_t rv) {
    return Function()(data_[Left(v)], data_[Right(v)]);
  }

  void Push(size_t v, size_t lv, size_t rv) {
    LazyPropagation()(data_[v], Data(Left(v)), Data(Right(v)));
  }

 private:
  static constexpr size_t Root() { return 0; }
  static constexpr size_t LRoot() { return 0; }
  /*            */ size_t RRoot() const { return size_; }
  static size_t Left(size_t v) { return 2 * v + 1; }
  static size_t Right(size_t v) { return 2 * v + 2; }
  static size_t Median(size_t lv, size_t rv) { return lv + (rv - lv) / 2; }

 private:
  std::vector<T> data_;
  const size_t size_;
};

#endif  // SEGMENT_TREE_H_
