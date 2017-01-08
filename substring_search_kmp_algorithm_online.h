#ifndef SUBSTRING_SEARCH_KMP_ALGORITHM_ONLINE_H_
#define SUBSTRING_SEARCH_KMP_ALGORITHM_ONLINE_H_

#include <cstddef>
#include <string>
#include <vector>
#include "prefix_function.h"

// TODO: refactor into a class with bool PushBack(char c) method
size_t KMPAlgorithm_Online(const std::string& t, const std::string& p) {
  // TODO: refactor into a class constructor
  std::vector<size_t> pi = GetPrefixFunction(p);
  size_t q = 0;
  for (size_t i = 0; i < t.size(); ++i) {
    while (q > 0 && t[i] != p[q]) {
      q = pi[q-1];
    }
    if (t[i] == p[q]) {
      ++q;
    }
    if (q == p.size()) {
      return i + 1 - q;
    }
  }
  return t.npos;
}

#endif  // SUBSTRING_SEARCH_KMP_ALGORITHM_ONLINE_H_
