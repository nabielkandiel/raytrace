#pragma once

#include <array>
#include <ostream>

namespace util {

template <typename T> class Vec3 {
public:
  Vec3() : _data{0, 0, 0} {};
  Vec3(T a, T b, T c) : _data{a, b, c} {};

  friend std::ostream &operator<<(std::ostream &os, const Vec3<T> &obj) {
    os << obj._data[0] << " " << obj._data[1] << " " << obj._data[2];
    return os;
  }

  Vec3<T> operator+(Vec3<T> const &other) {
    return Vec3<T>{_data[0] + other[0], _data[1] + other[1],
                   _data[2] + other[2]};
  }

  Vec3<T> operator-(Vec3<T> const &other) {
    return Vec3{_data[0] - other[0], _data[1] - other[1], _data[2] - other[2]};
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
} // namespace util