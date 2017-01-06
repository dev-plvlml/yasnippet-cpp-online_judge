#ifndef SUFFIX_AUTOMATON_H_
#define SUFFIX_AUTOMATON_H_

#include <cstddef>
#include <map>
#include <string>
#include <vector>

//! Directed Acyclic Word Graph
class DAWG {
 public:
  DAWG() {
    int q_cur = 0;
    states_.push_back(State());
    states_[q_cur].length = 0;
    states_[q_cur].link = -1;
    q_last_ = q_cur;
  }

  DAWG(const std::string& t): DAWG() {
    states_.reserve(2 * t.length() - 1);
    for (char c : t) PushBack(c);
  }

  void PushBack(char c) {
    int q_cur = states_.size();
    states_.push_back(State());
    states_[q_cur].length = states_[q_last_].length + 1;
    int q;
    for (q = q_last_;
         q != -1 && !states_[q].next.count(c);
         q = states_[q].link) {
      states_[q].next[c] = q_cur;
    }
    if (q == -1) {
      states_[q_cur].link = 0;
    } else {
      int q_next = states_[q].next[c];
      if (states_[q_next].length == states_[q].length + 1) {
        states_[q_cur].link = q_next;
      } else {
        int q_next_clone = states_.size();
        states_.push_back(states_[q_next]);
        states_[q_next_clone].length = states_[q].length + 1;
        for (q;
             q != -1 && states_[q].next[c] == q_next;
             q = states_[q].link) {
          states_[q].next[c] = q_next_clone;
        }
        states_[q_next].link = q_next_clone;
        states_[q_cur].link = q_next_clone;
      }
    }
    q_last_ = q_cur;
  }

  bool IsSubstr(const std::string& p) const {
    int q = 0;
    for (char c : p) {
      auto it = states_[q].next.find(c);
      if (it != states_[q].next.end()) {
        q = it->second;
      } else {
        return false;
      }
    }
    return true;
  }

  std::string LCS(const std::string& s) const;
  size_t Search(const std::string& s) const;

 private:
  struct State {
    size_t length;
    int link;  //!< Suffix link
    //! Transition function
    std::map<char, int> next;
  };

 private:
  int q_last_;
  std::vector<State> states_;
};

#endif  // SUFFIX_AUTOMATON_H_
