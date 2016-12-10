#ifndef GEOMETRY_0_TYPES_H_
#define GEOMETRY_0_TYPES_H_

#include <cmath>
#include <vector>
#include <utility>

template <typename T>
using Point = std::pair<T, T>;
#define X first
#define Y second

using Pi = Point<int>;
using Pd = Point<double>;

template <typename T>
struct Vector {
  Vector(T x, T y): x(x), y(y) {}
  Vector(Point<T> p0, Point<T> p): x(p.X - p0.X), y(p.Y - p0.Y) {}
  double Angle() const { return std::atan2(y, x); }
  double Length() const { return std::hypot(x, y); }
  T x, y;
};

using Vi = Vector<int>;
using Vd = Vector<double>;

#endif  // GEOMETRY_0_TYPES_H_
