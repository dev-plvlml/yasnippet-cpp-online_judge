#ifndef TREAP_WITH_IMPLICIT_KEY_SUM_H_
#define TREAP_WITH_IMPLICIT_KEY_SUM_H_

namespace treap {

struct SumData {
  SumData() = default;

  SumData(int value) :
      value(value),
      sum(value) {}

  struct Maintainer {
    void operator()(SumData& root, SumData* left, SumData* right) {
      root.sum = root.value + Sum(left) + Sum(right);
    }
  };

  static int Sum(SumData* data) { return data ? data->sum : 0; }

  int value = 0;
  int sum = 0;
};

}  // namespace treap

#endif  // TREAP_WITH_IMPLICIT_KEY_SUM_H
