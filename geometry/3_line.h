#ifndef GEOMETRY_3_LINE_H_
#define GEOMETRY_3_LINE_H_

#include <cmath>
#include <utility>
#include "geometry/0_types.h"
#include "geometry/1_vector.h"
#include "geometry/2_point.h"

template <typename T>
struct Line {
  Line(Point<T> a, Point<T> b): a(a), b(b) {}
  void Normalize() { if (a > b) std::swap(a, b); }
  Point<T> a, b;
};

template <typename T>
bool LiesOn(Point<T> p, Line<T> l) {
  return Collinear(Vector<T>{p, l.a}, Vector<T>{p, l.b});
}

template <typename T>
double Dist(Point<T> p, Line<T> l) {
  return 2.0 * std::fabs(OrientedArea(p, l.a, l.b)) / Dist(l.a, l.b);
}

template <typename T>
bool Intersects(Line<T> a1b1, Line<T> a2b2) {
  // TODO: implement bool Intersects(Line, Line)
}

template <typename T>
Point<T> Intersection(Line<T> a1b1, Line<T> a2b2) {
  // TODO: implement Point Intersection(Line, Line)
}

#endif  // GEOMETRY_3_LINE_H_
