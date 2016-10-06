#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>>
class SegmentTree {
 public:
  template <typename U = T>
  SegmentTree(const std::vector<U>& values)
      : tree_(4 * values.size()),
        size_(values.size()) {
    Build(values, Root(), 0, size_);
  }

  template <class Visitor>
  Visitor& Accept(size_t first, size_t last_incl, Visitor& visitor) const {
    return Accept(first, last_incl + 1, visitor, Root(), 0, size_);
  }

  template <typename U = T>
  void Assign(size_t pos, U value) {
    Assign(pos, value, Root(), 0, size_);
  }
  
  T Get(size_t pos) const {
    return Query(pos, pos);
  }

  T Query(size_t first, size_t last_incl) const {
    return Query(first, last_incl + 1, Root(), 0, size_);
  }

 protected:
  static constexpr size_t Root() { return 0; }
  static size_t Left(size_t i) { return 2*i + 1; }
  static size_t Right(size_t i) { return 2*i + 2; }
  static size_t Parent(size_t i) { return (i-1) / 2; }
  static size_t Middle(size_t l, size_t r) {
    // Naive approach:
    // return (l + r) / 2;
    // Reducing integer overflow:
    return l + (r - l) / 2;
  }

 private:
  template <class Visitor>
  Visitor& Accept(size_t l, size_t r, Visitor& visitor,
                  size_t v, size_t lv, size_t rv) const {
    if (l == lv && r == rv) return visitor(tree_[v]);
    size_t mv = Middle(lv, rv);
    if (r <= mv) return Accept(l, r, visitor, Left(v), lv, mv);
    if (l >= mv) return Accept(l, r, visitor, Right(v), mv, rv);
    Accept(l, mv, visitor, Left(v), lv, mv);
    Accept(mv, r, visitor, Right(v), mv, rv);
    return visitor;
  }

  template <typename U = T>
  void Assign(size_t pos, U value, size_t v, size_t lv, size_t rv) {
    if (rv - lv == 1) return (void) tree_[v] = value;
    size_t mv = Middle(lv, rv);
    if (pos < mv) {
      Assign(pos, value, Left(v), lv, mv);
    } else {
      Assign(pos, value, Right(v), mv, rv);
    }
    tree_[v] = Function()(tree_[Left(v)], tree_[Right(v)]);
  }

  template <typename U = T>
  void Build(const std::vector<U>& values, size_t v, size_t lv, size_t rv) {
    if (rv - lv == 1) return (void) tree_[v] = values[lv];
    size_t mv = Middle(lv, rv);
    Build(values, Left(v), lv, mv);
    Build(values, Right(v), mv, rv);
    tree_[v] = Function()(tree_[Left(v)], tree_[Right(v)]);
  }

  T Query(size_t l, size_t r, size_t v, size_t lv, size_t rv) const {
    if (l == lv && r == rv) return tree_[v];
    size_t mv = Middle(lv, rv);
    if (r <= mv) return Query(l, r, Left(v), lv, mv);
    if (l >= mv) return Query(l, r, Right(v), mv, rv);
    return Function()(Query(l, mv, Left(v), lv, mv),
                      Query(mv, r, Right(v), mv, rv));
  }

 private:
  std::vector<T> tree_;
  size_t size_;
};
