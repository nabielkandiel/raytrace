#pragma once
#include <cstdint>
#include <sstream>
#include <string>
struct rgb_pixel {
  size_t red;
  size_t green;
  size_t blue;

  friend std::ostream &operator<<(std::ostream &os, const rgb_pixel &obj);
};
