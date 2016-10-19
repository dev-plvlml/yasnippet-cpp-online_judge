#ifndef MINMAX_LAZY_PROPAGATION_H_
#define MINMAX_LAZY_PROPAGATION_H_

#include <queue>

enum Command {
  kColor, kDelta
};

struct Data {
  std::queue<std::pair<Command, int>> tasks;
  int min, max;

  Data& operator=(int value) {
    min = value;
    max = value;
    return *this;
  }

  Data& operator=(std::pair<Command, int> task) {
    tasks.push(task);
    return *this;
  }
};

struct Function {
  Data operator()(const Data& arg1, const Data& arg2) {
    Data result;
    result.min = std::min(arg1.min, arg2.min);
    result.max = std::max(arg1.max, arg2.max);
    return result;
  }
};

struct Propagator {
  void operator()(Data* root, Data* left, Data* right) {
    if (!root) return;
    while (!root->tasks.empty()) {
      auto task = root->tasks.front();
      switch (task.first) {
        case kColor:
          root->min = task.second;
          root->max = task.second;
          break;
        case kDelta:
          root->min += task.second;
          root->max += task.second;
          break;
      }
      for (auto ptr : {left, right}) {
        if (ptr) ptr->tasks.push(task);
      }
      root->tasks.pop();
    }
  }
};

#endif  // MINMAX_LAZY_PROPAGATION_H_
