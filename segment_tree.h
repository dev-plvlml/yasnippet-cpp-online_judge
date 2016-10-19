#include <algorithm>
#include <functional>
#include <vector>

template <typename T>
struct NullPropagator {
  void operator()(T* root, T* left, T* right) {}
};

template <typename T, class Function = std::plus<T>,
    class LazyPropagation = NullPropagator<T>>
class SegmentTree {
 public:
  template <typename U = T>
  SegmentTree(const std::vector<U>& values)
      : nodes_(4 * values.size()),
        size_(values.size()) {
    Build(values, Root(), 0, size_);
  }

  template <class Visitor>
  Visitor& Accept(size_t first, size_t last_incl, Visitor& visitor) {
    return Accept(first, last_incl + 1, visitor, Root(), 0, size_);
  }

  T Get(size_t pos) {
    return Query(pos, pos + 1, Root(), 0, size_);
  }

  T Query(size_t first, size_t last_incl) {
    return Query(first, last_incl + 1, Root(), 0, size_);
  }

  template <typename U = T>
  void Set(size_t pos, U value) {
    Set(pos, value, Root(), 0, size_);
  }

  template <typename U>
  void Update(size_t first, size_t last_incl, U value) {
    Update(first, last_incl + 1, value, Root(), 0, size_);
  }

 public:
  static constexpr size_t Root() { return 0; }
  static size_t Left(size_t v) { return 2 * v + 1; }
  static size_t Right(size_t v) { return 2 * v + 2; }
  static size_t Median(size_t l, size_t r) { return l + (r - l) / 2; }

 private:
  template <class Visitor>
  Visitor& Accept(size_t l, size_t r, Visitor& visitor,
                  size_t v, size_t lv, size_t rv) {
    if (l >= r) return visitor;  // Shortening code
    Push(v);
    if (l == lv && r == rv)
      return visitor(nodes_[v]);
    size_t mv = Median(lv, rv);
    Accept(l, std::min(mv, r), visitor, Left(v), lv, mv);
    Accept(std::max(l, mv), r, visitor, Right(v), mv, rv);
    return visitor;
  }

  template <typename U = T>
  void Build(const std::vector<U>& values,
             size_t v, size_t lv, size_t rv) {
    if (rv - lv == 1)
      return (void) (nodes_[v] = values[lv]);
    size_t mv = Median(lv, rv);
    Build(values, Left(v), lv, mv);
    Build(values, Right(v), mv, rv);
    Calc(v);
  }

  T Query(size_t l, size_t r,
                 size_t v, size_t lv, size_t rv) {
    Push(v);
    if (l == lv && r == rv)
      return nodes_[v];
    size_t mv = Median(lv, rv);
    // NB: cannot be shortened?
    if (r <= mv)
      return Query(l, r, Left(v), lv, mv);
    if (l >= mv)
      return Query(l, r, Right(v), mv, rv);
    return Function()(Query(l, mv, Left(v), lv, mv),
                      Query(mv, r, Right(v), mv, rv));
  }

  template <typename U = T>
  void Set(size_t pos, U value,
           size_t v, size_t lv, size_t rv) {
    Push(v);
    if (rv - lv == 1)
      return (void) (nodes_[v] = value);
    size_t mv = Median(lv, rv);
    if (pos < mv) {
      Set(pos, value, Left(v), lv, mv);
    } else {
      Set(pos, value, Right(v), mv, rv);
    }
    Push(Left(v));
    Push(Right(v));
    Calc(v);
  }

  template <typename U>
  void Update(size_t l, size_t r, U value,
              size_t v, size_t lv, size_t rv) {
    // Shortening code
    if (l >= r) return;
    Push(v);
    if (l == lv && r == rv)
      return (void) (nodes_[v] = value);
    size_t mv = Median(lv, rv);
    Update(l, std::min(mv, r), value, Left(v), lv, mv);
    Update(std::max(l, mv), r, value, Right(v), mv, rv);
    Push(Left(v));
    Push(Right(v));
    Calc(v);
  }

 private:
  T* Ptr(size_t v) { return v < nodes_.size() ? &nodes_[v] : nullptr; }

  void Calc(size_t v) {
    nodes_[v] = Function()(nodes_[Left(v)], nodes_[Right(v)]);
  }

  void Push(size_t v) {
    LazyPropagation()(Ptr(v), Ptr(Left(v)), Ptr(Right(v)));
  }

 private:
  std::vector<T> nodes_;
  size_t size_;
};
