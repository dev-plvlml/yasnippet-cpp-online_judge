#ifndef GEOMETRY_5_POLYGON_H_
#define GEOMETRY_5_POLYGON_H_

#include <algorithm>
#include <cmath>
#include "geometry/0_types.h"
#include "geometry/2_point.h"

template <typename T>
struct Polygon {
  Polygon() = default;
  Polygon(size_t n): pts(n) {}
  virtual bool IsConvex() const;
  double Perimeter() const;
  double OrientedArea() const;
  virtual int Orientation() const;
  void Orient(int new_orientation = 1);
  void Normalize();
  std::vector<Point<T>> pts;
};

template <typename T>
bool Polygon<T>::IsConvex() const {
  int orientation = 0;
  size_t i, n = pts.size();
  for (i = 0; i < n; ++i) {
    double oriented_area =
        ::OrientedArea(pts[i], pts[(i+1) % n], pts[(i+2) % n]);
    if (oriented_area < 0) { orientation = -1;  break; }
    if (oriented_area > 0) { orientation = +1;  break; }
  }
  for (i; i < n; ++i) {
    if (::OrientedArea(pts[i], pts[(i+1) % n], pts[(i+2) % n]) * orientation < 0)
      return false;
  }
  return true;
}

template <typename T>
double Polygon<T>::OrientedArea() const {
  double result = 0;
  for (size_t i = 1; i+1 < pts.size(); ++i) {
    result += ::OrientedArea(pts[0], pts[i], pts[i+1]);
  }
  return result;
}

template <typename T>
int Polygon<T>::Orientation() const {
  return OrientedArea() >= +0.0 ? +1 : -1;
}

template <typename T>
void Polygon<T>::Orient(int new_orientation /* = 1 */) {
  if (Orientation() * new_orientation < 0) {
    std::reverse(std::next(std::begin(pts), 1), std::end(pts));
  }
}

template <typename T>
void Polygon<T>::Normalize() {
  auto lowest_of_leftmost =
      std::min_element(std::begin(pts), std::end(pts));
  if (lowest_of_leftmost != std::begin(pts)) {
    std::rotate(std::begin(pts), lowest_of_leftmost, std::end(pts));
  }
}

template <typename T>
bool IsInside(Point<T> p, Polygon<T>& ngon) {
  // TODO: implement bool IsInside(Point, Polygon)
}

#endif  // GEOMETRY_5_POLYGON_H_
