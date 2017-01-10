#ifndef PALINDROME_COUNT_MANACHER_ALGORITHM_H_
#define PALINDROME_COUNT_MANACHER_ALGORITHM_H_

#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

std::pair<std::vector<int>, std::vector<int>>
ManacherAlgorithm(const std::string& s) {
  std::vector<int> radius_[2];
  radius_[0].resize(s.length(), 0);
  radius_[1].resize(s.length(), 0);
  for (int p : {0, 1}) {  // p for parity: 0 - odd, 1 - even
    int l = -1, r = -1;  // rightmost palindrome
    for (int i = 0; i < s.size(); ++i) {
      if (i <= r) {
        radius_[p][i] = std::min(radius_[p][l + r - i + p], r - i + 1);
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
  std::tie(radius_odd, radius_even) = ManacherAlgorithm(s);
  int count_odd = std::accumulate(std::begin(radius_odd), std::end(radius_odd), 0);
  int count_even = std::accumulate(std::begin(radius_even), std::end(radius_even), 0);
  return count_odd + count_even;
}

#endif  // PALINDROME_COUNT_MANACHER_ALGORITHM_H_
