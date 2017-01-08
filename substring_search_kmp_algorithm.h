#ifndef SUBSTRING_SEARCH_KMP_ALGORITHM_H_
#define SUBSTRING_SEARCH_KMP_ALGORITHM_H_

#include <cstddef>
#include <string>
#include <vector>
#include "prefix_function.h"

size_t KMPAlgorithm(const std::string& t, const std::string& p, char d = '#') {
  std::vector<size_t> pi = GetPrefixFunction(p + d + t);
  for (size_t i = p.size() + 1; i < pi.size(); ++i) {
    if (pi[i] == p.size()) {
      return i + 1 - pi[i] - (p.size() + 1);
    }
  }
  return t.npos;
}

#endif  // SUBSTRING_SEARCH_KMP_ALGORITHM_H_
