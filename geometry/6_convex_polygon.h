#ifndef GEOMETRY_6_CONVEX_POLYGON_H_
#define GEOMETRY_6_CONVEX_POLYGON_H_

#include <algorithm>
#include "geometry/0_types.h"
#include "geometry/2_point.h"
#include "geometry/5_polygon.h"

template <typename T>
struct ConvexPolygon : Polygon<T> {
  ConvexPolygon() = default;
  ConvexPolygon(size_t n): Polygon<T>(n) {}
  virtual bool IsConvex() const override { return true; }
  virtual int Orientation() const override;
  using Polygon<T>::pts;
};

template <typename T>
int ConvexPolygon<T>::Orientation() const {
  int orientation = 0;
  size_t n = pts.size();
  for (size_t i = 0; i < n; ++i) {
    double oriented_area =
        ::OrientedArea(pts[i], pts[(i+1) % n], pts[(i+2) % n]);
    if (oriented_area < 0) { orientation = -1;  break; }
    if (oriented_area > 0) { orientation = +1;  break; }
  }
  return orientation;
}

template <typename T>
bool IsInside_N(Point<T> p, const ConvexPolygon<T>& ngon) {
  double orientation = ngon.Orientation();
  size_t n = ngon.pts.size();
  for (size_t i = 0; i < n; ++i) {
    if (::OrientedArea(ngon.pts[i], ngon.pts[(i+1) % n], p) * orientation < 0)
      return false;
  }
  return true;
}

template <typename T>
bool IsInside_NlogN(Point<T> p, ConvexPolygon<T>& ngon) {
  ngon.Orient();
  ngon.Normalize();
  // TODO: implement bool IsInside_NlogN(Point, ConvexPolygon)
  // via binary search in O(log N)
}

#endif  // GEOMETRY_6_CONVEX_POLYGON_H_
