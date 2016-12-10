#ifndef GEOMETRY_1_VECTOR_H_
#define GEOMETRY_1_VECTOR_H_

#include "geometry/0_types.h"

template <typename T>
Vector<T> operator+(Vector<T> lhs_copy, Vector<T> rhs) {
  lhs_copy.x += rhs.x;
  lhs_copy.y += rhs.y;
  return lhs_copy;
}

template <typename T>
Vector<T> operator-(Vector<T> lhs_copy, Vector<T> rhs) {
  lhs_copy.x -= rhs.x;
  lhs_copy.y -= rhs.y;
  return lhs_copy;
}

template <typename T>
Vector<T> operator*(Vector<T> lhs_copy, T rhs) {
  lhs_copy.x *= rhs;
  lhs_copy.y *= rhs;
  return lhs_copy;
}

template <typename T>
T operator*(Vector<T> lhs, Vector<T> rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <typename T>
T operator^(Vector<T> lhs, Vector<T> rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}

template <typename T>
bool Orthogonal(Vector<T> v1, Vector<T> v2) {
  return (v1 * v2) == 0;
}

template <typename T>
bool Collinear(Vector<T> v1, Vector<T> v2) {
  return (v1 ^ v2) == 0;
}

template <typename T>
bool Acute(Vector<T> v1, Vector<T> v2) {
  return (v1 * v2) > 0;
}

template <typename T>
bool Obtuse(Vector<T> v1, Vector<T> v2) {
  return (v1 * v2) < 0;
}

template <typename T>
bool Left(Vector<T> v1, Vector<T> v2) {
  return (v1 ^ v2) > 0;
}

template <typename T>
bool Right(Vector<T> v1, Vector<T> v2) {
  return (v1 ^ v2) < 0;
}

#endif  // GEOMETRY_1_VECTOR_H_
