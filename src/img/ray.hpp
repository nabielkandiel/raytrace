#pragma once

#include "vec3.hpp"

template <typename T> class Ray {
public:
  using Vec3 = Util::Vec3<T>;
  Ray() : orig(0, 0, 0), dir(0, 0, 0) {}
  Ray(const Vec3 origin, const Vec3 direction) : orig(origin), dir(direction) {}

  const Vec3 &origin() const { return orig; }
  const Vec3 &direction() const { return dir; }

  Vec3 at(T t) const { return orig + t * dir; }

private:
  Vec3 orig;
  Vec3 dir;
};
