#include <algorithm>
#include <string>
#include <gtest/gtest.h>

#include "substring_search_knuth_morris_pratt_alternative.h"

TEST(KnuthMorrisPrattAlternative, DISABLED_HandlesEmpty) {
  std::string foobar = "foobar", empty = "";
  EXPECT_EQ(foobar.find(empty), KMPAlgorithm_Alt(foobar, empty));
  EXPECT_EQ(empty.find(foobar), KMPAlgorithm_Alt(empty, foobar));
  EXPECT_EQ(empty.find(empty), KMPAlgorithm_Alt(empty, empty));
}

TEST(KnuthMorrisPrattAlternative, HandlesEqual) {
  std::string foobar = "foobar";
  EXPECT_EQ(foobar.find(foobar), KMPAlgorithm_Alt(foobar, foobar));
}

TEST(KnuthMorrisPrattAlternative, CormenSequence) {
  std::string text = "bacbababaabcbab", pattern = "ababaca";
  EXPECT_EQ(text.find(pattern), KMPAlgorithm_Alt(text, pattern));
}

TEST(KnuthMorrisPrattAlternative, ababaca) {
  std::string ababaca = "ababaca";
  EXPECT_EQ(ababaca.find("a"), KMPAlgorithm_Alt(ababaca, "a"));
  EXPECT_EQ(ababaca.find("b"), KMPAlgorithm_Alt(ababaca, "b"));
  EXPECT_EQ(ababaca.find("c"), KMPAlgorithm_Alt(ababaca, "c"));
  EXPECT_EQ(ababaca.find("d"), KMPAlgorithm_Alt(ababaca, "d"));
  EXPECT_EQ(ababaca.find("ab"), KMPAlgorithm_Alt(ababaca, "ab"));
  EXPECT_EQ(ababaca.find("ba"), KMPAlgorithm_Alt(ababaca, "ba"));
  EXPECT_EQ(ababaca.find("ac"), KMPAlgorithm_Alt(ababaca, "ac"));
  EXPECT_EQ(ababaca.find("ca"), KMPAlgorithm_Alt(ababaca, "ca"));
  EXPECT_EQ(ababaca.find("ad"), KMPAlgorithm_Alt(ababaca, "ad"));
  EXPECT_EQ(ababaca.find("da"), KMPAlgorithm_Alt(ababaca, "da"));
  EXPECT_EQ(ababaca.find("aba"), KMPAlgorithm_Alt(ababaca, "aba"));
  EXPECT_EQ(ababaca.find("bab"), KMPAlgorithm_Alt(ababaca, "bab"));
  EXPECT_EQ(ababaca.find("bac"), KMPAlgorithm_Alt(ababaca, "bac"));
  EXPECT_EQ(ababaca.find("bad"), KMPAlgorithm_Alt(ababaca, "bad"));
  EXPECT_EQ(ababaca.find("aca"), KMPAlgorithm_Alt(ababaca, "aca"));
}
