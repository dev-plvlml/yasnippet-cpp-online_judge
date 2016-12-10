#ifndef Z_FUNCTION_H_
#define Z_FUNCTION_H_

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

inline std::vector<size_t> GetZFunction(const std::string& s) {
  std::vector<size_t> z(s.size(), 0);
  size_t i_mem = 0, zi_mem = s.size();  // Rightmost match
  z[i_mem] = zi_mem;
  for (size_t i = 1; i < s.size(); ++i) {
    if (i < i_mem + zi_mem) {
      z[i] = std::min(z[i - i_mem], i_mem + zi_mem - i);
    } else {
      z[i] = 0;
    }
    while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {
      ++z[i];
    }
    if (i + z[i] > i_mem + zi_mem) {
      i_mem = i;
      zi_mem = z[i];
    }
  }
  return z;
}

#endif  // Z_FUNCTION_H_
