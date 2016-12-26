#ifndef SUFFIX_AUTOMATON_H_
#define SUFFIX_AUTOMATON_H_

#include <cstddef>
#include <map>
#include <string>
#include <vector>

class DAWG {
 public:
  DAWG() {
    int q_cur = 0;
    states_.push_back(State());
    states_[q_cur].length = 0;
    states_[q_cur].link = -1;
    q_last_ = q_cur;
  }

  DAWG(std::string t): DAWG() {
    states_.reserve(2 * t.size() - 1);
    for (char c : t) {
      PushBack(c);
    }
  }

  void PushBack(char c) {
    int q_cur = states_.size();
    states_.push_back(State());
    states_[q_cur].length = states_[q_last_].length + 1;
    int q_link;
    for (q_link = q_last_;
         q_link != -1 && !states_[q_link].next.count(c);
         q_link = states_[q_link].link) {
      states_[q_link].next[c] = q_cur;
    }
    if (q_link == -1) {
      states_[q_cur].link = 0;
    } else {
      int q_link_next = states_[q_link].next[c];
      if (states_[q_link_next].length == states_[q_link].length + 1) {
        states_[q_cur].link = q_link_next;
      } else {
        int q_link_next_clone = states_.size();
        states_.push_back(states_[q_link_next]);
        states_[q_link_next_clone].length = states_[q_link].length + 1;
        for (q_link;
             q_link != -1 && states_[q_link].next[c] == q_link_next;
             q_link = states_[q_link].link) {
          states_[q_link].next[c] = q_link_next_clone;
        }
        states_[q_link_next].link = q_link_next_clone;
        states_[q_cur].link = q_link_next_clone;
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
    int link;
    //! Transition function:
    std::map<char, int> next;
  };

 private:
  int q_last_;
  std::vector<State> states_;
};

#endif  // SUFFIX_AUTOMATON_H_
