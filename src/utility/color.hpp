#pragma once
#include <algorithm>
#include <array>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <stdint.h>

namespace Util {

template <typename T> class Color {
public:
  Color() : _data{0, 0, 0} {};
  Color(T a, T b, T c)
      : _data{std::clamp(a, static_cast<T>(0), std::numeric_limits<T>::max()),
              std::clamp(b, static_cast<T>(0), std::numeric_limits<T>::max()),
              std::clamp(c, static_cast<T>(0), std::numeric_limits<T>::max())} {
  }

  T red() const { return _data[0]; }
  T green() const { return _data[1]; }
  T blue() const { return _data[2]; }

  friend std::ostream &operator<<(std::ostream &os, const Color<T> &obj) {
    os << obj._data[0] << " " << obj._data[1] << " " << obj._data[2];
    return os;
  }

  Color<T> operator+(Color<T> const &other) {
    return Color{_data[0] + other[0], _data[1] + other[1], _data[2] + other[2]};
  }

  Color<T> operator-(Color<T> const &other) {
    T a = _data[0] - other[0];
    T b = _data[1] - other[1];
    T c = _data[2] - other[2];
    return Color{a, b, c};
  }

  Color<T> &operator+=(const Color<T> &other) {
    _data[0] += other[0];
    _data[1] += other[1];
    _data[2] += other[2];
    return *this;
  }

  Color<T> &operator-=(const Color<T> &other) {
    _data[0] -= other[0];
    _data[1] -= other[1];
    _data[2] -= other[2];
    if (_data[0] < 0)
      _data[0] = 0;
    if (_data[1] < 0)
      _data[1] = 0;
    if (_data[2] < 0)
      _data[2] = 0;
    return *this;
  }

  Color<T> &operator*=(const Color<T> &other) {
    _data[0] *= other[0];
    _data[1] *= other[1];
    _data[2] *= other[2];
    return *this;
  }

  Color<T> &operator/=(const Color<T> &other) {
    _data[0] /= other[0];
    _data[1] /= other[1];
    _data[2] /= other[2];
    return *this;
  }

  template <typename U> Color<T> &operator+=(const U &other) {
    _data[0] += other;
    _data[1] += other;
    _data[2] += other;
    if (_data[0] < 0)
      _data[0] = 0;
    if (_data[1] < 0)
      _data[1] = 0;
    if (_data[2] < 0)
      _data[2] = 0;
    return *this;
  }

  template <typename U> Color<T> &operator-=(const U &other) {
    _data[0] -= other;
    _data[1] -= other;
    _data[2] -= other;
    if (_data[0] < 0)
      _data[0] = 0;
    if (_data[1] < 0)
      _data[1] = 0;
    if (_data[2] < 0)
      _data[2] = 0;
    return *this;
  }

  template <typename U> Color<T> &operator*=(const U &other) {
    if (other < 0) {
      throw std::runtime_error("Negative value not allowed");
    }
    _data[0] *= other;
    _data[1] *= other;
    _data[2] *= other;
    return *this;
  }

  template <typename U> Color<T> &operator/=(const U &other) {
    if (other < 0) {
      throw std::runtime_error("Negative value not allowed");
    }
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
} // namespace Util