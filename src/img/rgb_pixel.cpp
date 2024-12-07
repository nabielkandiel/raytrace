#include "rgb_pixel.hpp"

std::ostream &operator<<(std::ostream &os, const rgb_pixel &obj) {
  os << obj.red << " " << obj.green << " " << obj.blue;
  return os;
}