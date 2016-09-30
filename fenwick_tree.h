#include <functional>
#include <vector>

template <typename T, class Function = std::plus<T>, class InvFunction = std::minus<T>>
class FenwickTree {
 public:
  FenwickTree(size_t size, T init = T())
      : tree_(size, init),
        init_(init)
  {}
  
  FenwickTree(const std::vector<T>& values, T init = T())
      : FenwickTree(values.size(), init) {
    for (size_t i = 0; i < values.size(); ++i) {
      Assign(i, values[i]);
    }
  }
  
  void Assign(size_t pos, T value) {
    Update(pos, InvFunction()(value, tree_[pos]));
  }
  
  T Get(size_t pos) const {
    return Query(pos, pos);
  }

  T Query(size_t last_incl) const {
    T result = init_;
    for (int i = int{last_incl}; i >= 0; i = F(i) - 1) {
      result = Function()(result, tree_[i]);
    }
    return result;
  }

  T Query(size_t first, size_t last_incl) const {
    T result = Query(last_incl);
    if (first) { result = InvFunction()(result, Query(first - 1)); }
    return result;
  }

  void Update(size_t pos, T delta) {
    for (size_t i = pos; i < tree_.size(); i = H(i)) {
      tree_[i] = Function()(tree_[i], delta);
    }
  }

 protected:
  static size_t F(size_t i) { return i & (i+1); }
  static size_t H(size_t i) { return i | (i+1); }
  
 private:
  std::vector<T> tree_;
  T init_;
};
