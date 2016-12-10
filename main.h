#ifndef MAIN_H_
#define MAIN_H_

#include <cmath>
#include <limits>
#include <utility>
using namespace std;

#define X first
#define Y second
#define A first
#define B second
#define U first
#define V second
#define MP make_pair
#define PB push_back
#define ALL(C) begin(C), end(C)

using LL = long long;
using Pii = pair<int, int>;
using Pdd = pair<double, double>;

constexpr double eps = 1.0e-9;
const double pi = acos(-1.0);
const double e = exp(1.0);
const double phi = (1.0 + sqrt(5.0)) / 2.0;

constexpr int k7 = 1000 * 1000 * 1000 + 7;
constexpr int k9 = 1000 * 1000 * 1000 + 9;
constexpr int inf = numeric_limits<int>::max();

constexpr char eol = '\n';

template <typename FP>
inline bool Eq(FP lhs, FP rhs) { return fabs(lhs - rhs) < eps; }

template <int i, typename T>
inline T Pow(T x) { return i ? x * Pow<i-1>(x) : 1; }

#endif  // MAIN_H_
