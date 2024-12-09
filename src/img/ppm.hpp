#pragma once
#include "color.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

using util::Color;

class ppm {
public:
  ppm(const size_t rows, const size_t cols);
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<Color<size_t>>> &data);
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<Color<size_t>>> &&data);

  const std::vector<std::vector<Color<size_t>>> &getData() const {
    return _data;
  }
  size_t getRows() { return _rows; }
  size_t getCols() { return _cols; }
  bool writeImgFile(const std::string &filename);

private:
  size_t _cols = 0;
  size_t _rows = 0;
  std::vector<std::vector<Color<size_t>>> _data;
};