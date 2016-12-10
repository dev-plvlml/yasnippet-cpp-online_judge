#ifndef CONVEX_HULL_CHANS_ALGORITHM_H_
#define CONVEX_HULL_CHANS_ALGORITHM_H_

#include <vector>
#include "geometry/6_convex_polygon.h"

template <typename T>
ConvexPolygon<T> GetConvexHull(const std::vector<Point<T>>& pts) {
  ConvexPolygon<T> hull;
  // TODO: implement Chan's Algorithm
  return hull;
}

#endif  // CONVEX_HULL_CHANS_ALGORITHM_H_
