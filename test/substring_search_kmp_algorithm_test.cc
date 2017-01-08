#include <algorithm>
#include <string>
#include <gtest/gtest.h>

#include "substring_search_kmp_algorithm.h"

TEST(KMPAlgorithm, DISABLED_HandlesEmpty) {
  std::string foobar = "foobar", empty = "";
  EXPECT_EQ(foobar.find(empty), KMPAlgorithm(foobar, empty));
  EXPECT_EQ(empty.find(foobar), KMPAlgorithm(empty, foobar));
  EXPECT_EQ(empty.find(empty), KMPAlgorithm(empty, empty));
}

TEST(KMPAlgorithm, HandlesEqual) {
  std::string foobar = "foobar";
  EXPECT_EQ(foobar.find(foobar), KMPAlgorithm(foobar, foobar));
}

TEST(KMPAlgorithm, CormenSequence) {
  std::string text = "bacbababaabcbab", pattern = "ababaca";
  EXPECT_EQ(text.find(pattern), KMPAlgorithm(text, pattern));
}

TEST(KMPAlgorithm, ababaca) {
  std::string ababaca = "ababaca";
  EXPECT_EQ(ababaca.find("a"), KMPAlgorithm(ababaca, "a"));
  EXPECT_EQ(ababaca.find("b"), KMPAlgorithm(ababaca, "b"));
  EXPECT_EQ(ababaca.find("c"), KMPAlgorithm(ababaca, "c"));
  EXPECT_EQ(ababaca.find("d"), KMPAlgorithm(ababaca, "d"));
  EXPECT_EQ(ababaca.find("ab"), KMPAlgorithm(ababaca, "ab"));
  EXPECT_EQ(ababaca.find("ba"), KMPAlgorithm(ababaca, "ba"));
  EXPECT_EQ(ababaca.find("ac"), KMPAlgorithm(ababaca, "ac"));
  EXPECT_EQ(ababaca.find("ca"), KMPAlgorithm(ababaca, "ca"));
  EXPECT_EQ(ababaca.find("ad"), KMPAlgorithm(ababaca, "ad"));
  EXPECT_EQ(ababaca.find("da"), KMPAlgorithm(ababaca, "da"));
  EXPECT_EQ(ababaca.find("aba"), KMPAlgorithm(ababaca, "aba"));
  EXPECT_EQ(ababaca.find("bab"), KMPAlgorithm(ababaca, "bab"));
  EXPECT_EQ(ababaca.find("bac"), KMPAlgorithm(ababaca, "bac"));
  EXPECT_EQ(ababaca.find("bad"), KMPAlgorithm(ababaca, "bad"));
  EXPECT_EQ(ababaca.find("aca"), KMPAlgorithm(ababaca, "aca"));
}
