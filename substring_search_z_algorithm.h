#ifndef SUBSTRING_SEARCH_Z_ALGORITHM_H_
#define SUBSTRING_SEARCH_Z_ALGORITHM_H_

#include <cstddef>
#include <string>
#include <vector>
#include "z_function.h"

size_t ZAlgorithm(const std::string& t, const std::string& p, char d = '#') {
  std::vector<size_t> z = GetZFunction(p + d + t);
  for (size_t i = p.size() + 1; i < z.size(); ++i) {
    if (z[i] == p.size()) {
      return i - (p.size() + 1);
    }
  }
  return t.npos;
}

#endif  // SUBSTRING_SEARCH_Z_ALGORITHM_H_
