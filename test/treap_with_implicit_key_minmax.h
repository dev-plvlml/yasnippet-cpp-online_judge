#ifndef TREAP_WITH_IMPLICIT_KEY_MINMAX_H_
#define TREAP_WITH_IMPLICIT_KEY_MINMAX_H_

#include <climits>
#include <queue>
#include <utility>

namespace treap {

enum Command {
  kColor, kDelta
};

struct MinMaxData {
  MinMaxData() = default;

  MinMaxData(int value) : value(value), min(value), max(value) {}

  MinMaxData& operator=(int value) {
    this->value = value;
    min = value;
    max = value;
    return *this;
  }

  MinMaxData& operator=(std::pair<Command, int> task) {
    tasks.push(task);
    return *this;
  }

  struct Maintainer {
    void operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right);
  };

  struct Propagator {
    void operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right);
  };

  static int Min(MinMaxData* data) { return data ? data->min : INT_MAX; }

  static int Max(MinMaxData* data) { return data ? data->max : INT_MIN; }

  std::queue<std::pair<Command, int>> tasks;
  int value = 0;
  int min = INT_MAX;
  int max = INT_MIN;
};

void MinMaxData::Maintainer::operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right) {
  root.min = std::min(root.value, std::min(Min(left), Min(right)));
  root.max = std::max(root.value, std::max(Max(left), Max(right)));
}

void MinMaxData::Propagator::operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right) {
  while (!root.tasks.empty()) {
    auto task = root.tasks.front();
    switch (task.first) {
      case kColor:
        root.value = task.second;
        root.min = task.second;
        root.max = task.second;
        break;
      case kDelta:
        root.value += task.second;
        root.min += task.second;
        root.max += task.second;
        break;
    }
    for (auto ptr : {left, right}) {
      if (ptr) ptr->tasks.push(task);
    }
    root.tasks.pop();
  }
}

}  // namespace treap

#endif  // TREAP_WITH_IMPLICIT_KEY_MINMAX_H_
