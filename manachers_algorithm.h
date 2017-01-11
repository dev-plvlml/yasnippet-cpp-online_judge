#ifndef PALINDROME_SEARCH_MANACHERS_ALGORITHM_H_
#define PALINDROME_SEARCH_MANACHERS_ALGORITHM_H_

#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

std::pair<std::vector<int>, std::vector<int>>
ManachersAlgorithm(const std::string &s) {
  std::vector<int> radius_[2];
  radius_[0].resize(s.length(), 0);
  radius_[1].resize(s.length(), 0);
  for (int p : {0, 1}) {  // p for parity: 0 - odd, 1 - even
    int l = 0, r = 0;  // rightmost palindrome
    radius_[p][0] = !p;
    for (int i = 1; i < s.size(); ++i) {
      if (i <= r) {
        radius_[p][i] = std::min(radius_[p][l + (r - i) + p], (r - i) + 1);
      }
      while (i - radius_[p][i] - p >= 0 &&
          i + radius_[p][i] < s.size() &&
          s[i - radius_[p][i] - p] == s[i + radius_[p][i]]) {
        ++radius_[p][i];
      }
      if (i + radius_[p][i] - 1 > r) {
        r = i + radius_[p][i] - 1;
        l = i - radius_[p][i] + 1 - p;
      }
    }
  }
  return std::make_pair(std::move(radius_[0]), std::move(radius_[1]));
};

int CountPalindromes(const std::string& s) {
  std::vector<int> radius_odd, radius_even;
  std::tie(radius_odd, radius_even) = ManachersAlgorithm(s);
  int count_odd = std::accumulate(std::begin(radius_odd), std::end(radius_odd), 0);
  int count_even = std::accumulate(std::begin(radius_even), std::end(radius_even), 0);
  return count_odd + count_even;
}

//! Longest Palindromic Substring
std::string LPS(const std::string& s) {
  std::vector<int> radius_odd, radius_even;
  std::tie(radius_odd, radius_even) = ManachersAlgorithm(s);
  auto max_odd = std::max_element(std::begin(radius_odd), std::end(radius_odd));
  auto max_even = std::max_element(std::begin(radius_even), std::end(radius_even));
  if (2 * *max_odd - 1 > 2 * *max_even) {
    int i = std::distance(std::begin(radius_odd), max_odd);
    return s.substr(i - *max_odd + 1, 2 * *max_odd - 1);
  } else {
    int i = std::distance(std::begin(radius_even), max_even);
    return s.substr(i - *max_even, 2 * *max_even);
  }
}

#endif  // PALINDROME_SEARCH_MANACHERS_ALGORITHM_H_
