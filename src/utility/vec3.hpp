#pragma once

#include <array>
#include <cmath>
#include <ostream>
#include <stdint.h>

namespace Util {

template <typename T> class Vec3 {
public:
  // x [0], y [1], z [2]
  Vec3() : _data{0, 0, 0} {};
  Vec3(T a, T b, T c) : _data{a, b, c} {};

  friend std::ostream &operator<<(std::ostream &os, const Vec3<T> &obj) {
    os << obj._data[0] << " " << obj._data[1] << " " << obj._data[2];
    return os;
  }

  Vec3<T> operator+(Vec3<T> const &other) const {
    return Vec3<T>{_data[0] + other[0], _data[1] + other[1],
                   _data[2] + other[2]};
  }

  Vec3<T> operator-(Vec3<T> const &other) const {
    return Vec3{_data[0] - other[0], _data[1] - other[1], _data[2] - other[2]};
  }

  Vec3<T> operator*(Vec3<T> const &other) const {
    return Vec3<T>{_data[0] * other[0], _data[1] * other[1],
                   _data[2] * other[2]};
  }

  Vec3<T> operator*(T const &other) const {
    return Vec3{_data[0] * other, _data[1] * other, _data[2] * other};
  }

  Vec3<T> operator/(Vec3<T> const &other) const {
    return Vec3<T>{_data[0] / other[0], _data[1] / other[1],
                   _data[2] / other[2]};
  }

  Vec3<T> operator/(T const &other) const {
    return Vec3{_data[0] / other, _data[1] / other, _data[2] / other};
  }

  Vec3<T> &operator+=(const Vec3<T> &other) {
    _data[0] += other[0];
    _data[1] += other[1];
    _data[2] += other[2];
    return *this;
  }

  Vec3<T> &operator-=(const Vec3<T> &other) {
    _data[0] -= other[0];
    _data[1] -= other[1];
    _data[2] -= other[2];
    return *this;
  }

  Vec3<T> &operator*=(const Vec3<T> &other) {
    _data[0] *= other[0];
    _data[1] *= other[1];
    _data[2] *= other[2];
    return *this;
  }

  Vec3<T> &operator/=(const Vec3<T> &other) {
    _data[0] /= other[0];
    _data[1] /= other[1];
    _data[2] /= other[2];
    return *this;
  }

  template <typename U> Vec3<T> &operator+=(const U &other) {
    _data[0] += other;
    _data[1] += other;
    _data[2] += other;
    return *this;
  }

  template <typename U> Vec3<T> &operator-=(const U &other) {
    _data[0] -= other;
    _data[1] -= other;
    _data[2] -= other;
    return *this;
  }

  template <typename U> Vec3<T> &operator*=(const U &other) {
    _data[0] *= other;
    _data[1] *= other;
    _data[2] *= other;
    return *this;
  }

  template <typename U> Vec3<T> &operator/=(const U &other) {
    _data[0] /= other;
    _data[1] /= other;
    _data[2] /= other;
    return *this;
  }

  T &operator[](int idx) { return _data[idx]; }

  T operator[](int idx) const { return _data[idx]; }

private:
  std::array<T, 3> _data;
};

template <typename T>
constexpr bool operator==(const Vec3<T> &lhs, const Vec3<T> &rhs) {
  if (lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2])
    return true;
  return false;
}
template <typename T> Vec3<T> operator*(const T &scalar, const Vec3<T> &vec) {
  return vec * scalar;
}

template <typename T>
Vec3<T> make_unit(Vec3<T> vec) {
  T squared = (vec[0]*vec[0]) + (vec[1]*vec[1]) + (vec[2]*vec[2]);
  T mag = std::sqrt(squared);
  return (vec/mag);
}

} // namespace Util
