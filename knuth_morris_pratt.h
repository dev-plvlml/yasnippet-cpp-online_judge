vector<size_t> KMPComputePi(const string& s) {
  vector<size_t> pi(s.size());
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

size_t KMPSearch(const string& t, const string& p) {
  vector<size_t> pi = KMPComputePi(p);
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