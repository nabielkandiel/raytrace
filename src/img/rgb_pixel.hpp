#pragma once
#include <cstdint>
#include <sstream>
#include <string>
struct rgb_pixel {
  size_t red;
  size_t green;
  size_t blue;

  std::string toString() {
    std::stringstream ss;
    ss << red << " " << green << " " << blue;
    return ss.str();
  }
};
