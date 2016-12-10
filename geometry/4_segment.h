#ifndef GEOMETRY_4_SEGMENT_H_
#define GEOMETRY_4_SEGMENT_H_

#include <algorithm>
#include "geometry/0_types.h"
#include "geometry/1_vector.h"
#include "geometry/2_point.h"
#include "geometry/3_line.h"

template <typename T>
struct Segment {
  Segment(Point<T> a, Point<T> b): a(a), b(b) {}
  double Length() const { return std::hypot(b.X - a.X, b.Y - a.Y); }
  void Normalize() { if (a > b) std::swap(a, b); }
  Point<T> a, b;
};

using Si = Segment<int>;
using Sd = Segment<double>;

template <typename T>
struct Segment1d {
  Segment1d(T a, T b): a(a), b(b) {}
  void Normalize() { if (a > b) std::swap(a, b); }
  T a, b;
};

template <typename T>
bool BelongsTo(Point<T> p, Segment<T> ab) {
  return LiesOn(p, Line<T>{ab.a, ab.b}) &&
      Obtuse(Vector<T>{p, ab.a}, Vector<T>{p, ab.b});
}

template <typename T>
double Dist(Point<T> p, Segment<T> ab) {
  if (Acute(Vector<T>(ab.a, ab.b), Vector<T>(ab.a, p)) &&
      Acute(Vector<T>(ab.b, ab.a), Vector<T>(ab.b, p))) {
    return Dist(p, Line<T>{ab.a, ab.b});
  } else {
    return std::min(Dist(p, ab.a), Dist(p, ab.b));
  }
}

template <typename T>
bool Intersects(Segment1d<T> a1b1, Segment1d<T> a2b2) {
  a1b1.Normalize();
  a2b2.Normalize();
  return std::max(a1b1.a, a2b2.a) <= std::min(a1b1.b, a2b2.b);
}

template <typename T>
bool Intersects(Segment<T> a1b1, Segment<T> a2b2) {
  a1b1.Normalize();
  a2b2.Normalize();
  return Intersects({a1b1.a.X, a1b1.b.X}, {a2b2.a.X, a2b2.b.X}) &&
      Intersects({a1b1.a.Y, a1b1.b.Y}, {a2b2.a.Y, a2b2.b.Y}) &&
      OrientedArea(a1b1.a, a1b1.b, a2b2.a) * OrientedArea(a1b1.a, a1b1.b, a2b2.b) <= 0 &&
      OrientedArea(a2b2.a, a2b2.b, a1b1.a) * OrientedArea(a2b2.a, a2b2.b, a1b1.b) <= 0;
}

template <typename T>
Point<T> Intersection(Segment<T> a1b1, Segment<T> a2b2) {
  return Intersection(Line<T>{a1b1.a, a1b1.b}, Line<T>{a2b2.a, a2b2.b});
}

#endif  // GEOMETRY_4_SEGMENT_H_
