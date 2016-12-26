#ifndef SUFFIX_AUTOMATON_LONGEST_COMMON_SUBSTRING_H_
#define SUFFIX_AUTOMATON_LONGEST_COMMON_SUBSTRING_H_

#include "suffix_automaton.h"

std::string DAWG::LCS(const std::string& s) const {
  size_t i_max = 0, max_length = 0;
  int q = 0;
  size_t cur_length = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    char c = s[i];
    while (q != 0 && !states_[q].next.count(c)) {
      q = states_[q].link;
      cur_length = states_[q].length;
    }
    auto it = states_[q].next.find(c);
    if (it != states_[q].next.end()) {
      q = it->second;
      ++cur_length;
      if (max_length < cur_length) {
        max_length = cur_length;
        i_max = i;
      }
    }
  }
  // Eliminating integer overflow risks:
  return s.substr(i_max + 1 - max_length, max_length);
}

#endif  // SUFFIX_AUTOMATON_LONGEST_COMMON_SUBSTRING_H_
