#include <algorithm>
#include <string>
#include <gtest/gtest.h>

#include "substring_search_kmp_algorithm_online.h"

TEST(KMPAlgorithmOnline, DISABLED_HandlesEmpty) {
  std::string foobar = "foobar", empty = "";
  EXPECT_EQ(foobar.find(empty), KMPAlgorithm_Online(foobar, empty));
  EXPECT_EQ(empty.find(foobar), KMPAlgorithm_Online(empty, foobar));
  EXPECT_EQ(empty.find(empty), KMPAlgorithm_Online(empty, empty));
}

TEST(KMPAlgorithmOnline, HandlesEqual) {
  std::string foobar = "foobar";
  EXPECT_EQ(foobar.find(foobar), KMPAlgorithm_Online(foobar, foobar));
}

TEST(KMPAlgorithmOnline, CormenSequence) {
  std::string text = "bacbababaabcbab", pattern = "ababaca";
  EXPECT_EQ(text.find(pattern), KMPAlgorithm_Online(text, pattern));
}

TEST(KMPAlgorithmOnline, ababaca) {
  std::string ababaca = "ababaca";
  EXPECT_EQ(ababaca.find("a"), KMPAlgorithm_Online(ababaca, "a"));
  EXPECT_EQ(ababaca.find("b"), KMPAlgorithm_Online(ababaca, "b"));
  EXPECT_EQ(ababaca.find("c"), KMPAlgorithm_Online(ababaca, "c"));
  EXPECT_EQ(ababaca.find("d"), KMPAlgorithm_Online(ababaca, "d"));
  EXPECT_EQ(ababaca.find("ab"), KMPAlgorithm_Online(ababaca, "ab"));
  EXPECT_EQ(ababaca.find("ba"), KMPAlgorithm_Online(ababaca, "ba"));
  EXPECT_EQ(ababaca.find("ac"), KMPAlgorithm_Online(ababaca, "ac"));
  EXPECT_EQ(ababaca.find("ca"), KMPAlgorithm_Online(ababaca, "ca"));
  EXPECT_EQ(ababaca.find("ad"), KMPAlgorithm_Online(ababaca, "ad"));
  EXPECT_EQ(ababaca.find("da"), KMPAlgorithm_Online(ababaca, "da"));
  EXPECT_EQ(ababaca.find("aba"), KMPAlgorithm_Online(ababaca, "aba"));
  EXPECT_EQ(ababaca.find("bab"), KMPAlgorithm_Online(ababaca, "bab"));
  EXPECT_EQ(ababaca.find("bac"), KMPAlgorithm_Online(ababaca, "bac"));
  EXPECT_EQ(ababaca.find("bad"), KMPAlgorithm_Online(ababaca, "bad"));
  EXPECT_EQ(ababaca.find("aca"), KMPAlgorithm_Online(ababaca, "aca"));
}
