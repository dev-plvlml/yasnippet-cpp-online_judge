#ifndef PALINDROMIC_TREE_H_
#define PALINDROMIC_TREE_H_

#include <string>
#include <map>
#include <vector>

class PalindromicTree {
 public:
  PalindromicTree(char d = '#') {
    text_.push_back(d);
    states_.push_back(State());
    states_[0].length = -1;
    states_[0].link = -1;
    states_.push_back(State());
    states_[1].length = 0;
    states_[1].link = 0;
    q_last_ = 1;
  }

  PalindromicTree(const std::string& t): PalindromicTree() {
    text_.reserve(1 + t.length());
    for (char c : t) PushBack(c);
  }

  void PushBack(char c) {
    text_.push_back(c);
    int q = GetLink(q_last_);
    if (states_[q].next.count(c)) {
      q_last_ = states_[q].next[c];
    } else {
      int q_cur = states_.size();
      states_.push_back(State());
      states_[q].next[c] = q_cur;
      states_[q_cur].length = states_[q].length + 2;
      if (q == 0) {
        states_[q_cur].link = 1;
      } else {
        q = GetLink(states_[q].link);
        states_[q_cur].link = states_[q].next[c];
      }
      q_last_ = q_cur;
    }
  }

  size_t Size() const { return states_.size() - 2; }

 private:
  struct State {
    int length;
    int link;  //!< Suffix link
    //! Transition function
    std::map<char, int> next;
  };

 private:
  int GetLink(int q) const {
    while (text_[text_.length() - 1] !=
           text_[text_.length() - states_[q].length - 2]) {
      q = states_[q].link;
    }
    return q;
  }

 private:
  int q_last_;
  std::vector<State> states_;
  std::string text_;
};

#endif  // PALINDROMIC_TREE_H_
