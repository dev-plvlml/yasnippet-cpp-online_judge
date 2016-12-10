#ifndef CONVEX_HULL_JARVIS_MARCH_H_
#define CONVEX_HULL_JARVIS_MARCH_H_

#include <vector>
#include "geometry/6_convex_polygon.h"

template <typename T>
ConvexPolygon<T> GetConvexHull(const std::vector<Point<T>>& pts) {
  ConvexPolygon<T> hull;
  // TODO: implement Jarvis' March
  return hull;
}

#endif  // CONVEX_HULL_JARVIS_MARCH_H_
