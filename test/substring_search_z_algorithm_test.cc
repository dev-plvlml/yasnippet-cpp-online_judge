#include <algorithm>
#include <string>
#include <gtest/gtest.h>

#include "substring_search_z_algorithm.h"

TEST(ZAlgorithm, DISABLED_HandlesEmpty) {
  std::string foobar = "foobar", empty = "";
  EXPECT_EQ(foobar.find(empty), ZAlgorithm(foobar, empty));
  EXPECT_EQ(empty.find(foobar), ZAlgorithm(empty, foobar));
  EXPECT_EQ(empty.find(empty), ZAlgorithm(empty, empty));
}

TEST(ZAlgorithm, HandlesEqual) {
  std::string foobar = "foobar";
  EXPECT_EQ(foobar.find(foobar), ZAlgorithm(foobar, foobar));
}

TEST(ZAlgorithm, CormenSequence) {
  std::string text = "bacbababaabcbab", pattern = "ababaca";
  EXPECT_EQ(text.find(pattern), ZAlgorithm(text, pattern));
}

TEST(ZAlgorithm, ababaca) {
  std::string ababaca = "ababaca";
  EXPECT_EQ(ababaca.find("a"), ZAlgorithm(ababaca, "a"));
  EXPECT_EQ(ababaca.find("b"), ZAlgorithm(ababaca, "b"));
  EXPECT_EQ(ababaca.find("c"), ZAlgorithm(ababaca, "c"));
  EXPECT_EQ(ababaca.find("d"), ZAlgorithm(ababaca, "d"));
  EXPECT_EQ(ababaca.find("ab"), ZAlgorithm(ababaca, "ab"));
  EXPECT_EQ(ababaca.find("ba"), ZAlgorithm(ababaca, "ba"));
  EXPECT_EQ(ababaca.find("ac"), ZAlgorithm(ababaca, "ac"));
  EXPECT_EQ(ababaca.find("ca"), ZAlgorithm(ababaca, "ca"));
  EXPECT_EQ(ababaca.find("ad"), ZAlgorithm(ababaca, "ad"));
  EXPECT_EQ(ababaca.find("da"), ZAlgorithm(ababaca, "da"));
  EXPECT_EQ(ababaca.find("aba"), ZAlgorithm(ababaca, "aba"));
  EXPECT_EQ(ababaca.find("bab"), ZAlgorithm(ababaca, "bab"));
  EXPECT_EQ(ababaca.find("bac"), ZAlgorithm(ababaca, "bac"));
  EXPECT_EQ(ababaca.find("bad"), ZAlgorithm(ababaca, "bad"));
  EXPECT_EQ(ababaca.find("aca"), ZAlgorithm(ababaca, "aca"));
}
