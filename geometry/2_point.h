#ifndef GEOMETRY_2_POINT_H_
#define GEOMETRY_2_POINT_H_

#include <cmath>
#include "geometry/0_types.h"
#include "geometry/1_vector.h"

template <typename T>
Point<T> operator+(Point<T> lhs_copy, Vector<T> rhs) {
  lhs_copy.first += rhs.x;
  lhs_copy.second += rhs.y;
  return lhs_copy;
}

template <typename T>
double Dist(Point<T> p1, Point<T> p2) {
  return std::hypot(p2.X - p1.X, p2.Y - p1.Y);
}

template <typename T>
bool Left(Point<T> p0, Point<T> p1, Point<T> p2) {
  return Left(Vector<T>{p0, p1}, Vector<T>{p0, p2});
}

template <typename T>
bool Right(Point<T> p0, Point<T> p1, Point<T> p2) {
  return Right(Vector<T>{p0, p1}, Vector<T>{p0, p2});
}

template <typename T>
double OrientedArea(Point<T> p0, Point<T> p1, Point<T> p2) {
  return (Vector<T>{p0, p1} ^ Vector<T>{p0, p2}) / 2.0;
}

#endif  // GEOMETRY_2_POINT_H_
