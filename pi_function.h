#ifndef PI_FUNCTION_H_
#define PI_FUNCTION_H_

#include <cstddef>
#include <string>
#include <vector>

inline std::vector<size_t> GetPiFunction(const std::string& s) {
  std::vector<size_t> pi(s.size());
  size_t q = 0;
  pi[q] = 0;
  for (size_t i = 1; i < s.size(); ++i) {
    while (q > 0 && s[i] != s[q]) {
      q = pi[q-1];
    }
    if (s[i] == s[q]) {
      ++q;
    }
    pi[i] = q;
  }
  return pi;
}

#endif  // PI_FUNCTION_H_
