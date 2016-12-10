#ifndef STRING_SEARCH_KNUTH_MORRIS_PRATT_H_
#define STRING_SEARCH_KNUTH_MORRIS_PRATT_H_

#include <cstddef>
#include <string>
#include <vector>
#include "pi_function.h"

size_t Search(const std::string& t, const std::string& p) {
  std::vector<size_t> pi = GetPiFunction(p);
  size_t q = 0;
  for (size_t i = 0; i < t.size(); ++i) {
    while (q > 0 && t[i] != p[q]) {
      q = pi[q-1];
    }
    if (t[i] == p[q]) {
      ++q;
    }
    if (q == p.size()) {
      return i - q + 1;
    }
  }
  return t.npos;
}

#endif  // STRING_SEARCH_KNUTH_MORRIS_PRATT_H_
