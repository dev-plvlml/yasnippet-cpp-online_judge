#ifndef SEGMENT_TREE_MINMAX_H_
#define SEGMENT_TREE_MINMAX_H_

#include <climits>
#include <queue>
#include <utility>

namespace segm_tree {

enum Command {
  kColor, kDelta
};

struct MinMaxData {
  MinMaxData() = default;

  MinMaxData(int value) : min(value), max(value) {}

  MinMaxData& operator=(int value) {
    min = value;
    max = value;
    return *this;
  }

  MinMaxData& operator=(std::pair<Command, int> task) {
    tasks.push(task);
    return *this;
  }

  struct Function {
    MinMaxData operator()(const MinMaxData& arg1, const MinMaxData& arg2);
  };

  struct Propagator {
    void operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right);
  };

  std::queue<std::pair<Command, int>> tasks;
  int min = INT_MAX;
  int max = INT_MIN;
};

MinMaxData MinMaxData::Function::operator()(const MinMaxData& arg1, const MinMaxData& arg2) {
  MinMaxData result;
  result.min = std::min(arg1.min, arg2.min);
  result.max = std::max(arg1.max, arg2.max);
  return result;
}

void MinMaxData::Propagator::operator()(MinMaxData& root, MinMaxData* left, MinMaxData* right) {
  while (!root.tasks.empty()) {
    auto task = root.tasks.front();
    switch (task.first) {
      case kColor:
        root.min = task.second;
        root.max = task.second;
        break;
      case kDelta:
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

}  // namespace segm_tree

#endif  // SEGMENT_TREE_MINMAX_H_
