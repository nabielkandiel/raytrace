#pragma once
#include "rgb_pixel.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class ppm {
public:
  ppm(const size_t rows, const size_t cols);
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<rgb_pixel>> &data);
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<rgb_pixel>> &&data);

  const std::vector<std::vector<rgb_pixel>> &getData() const { return _data; }
  size_t getRows() { return _rows; }
  size_t getCols() { return _cols; }
  bool writeImgFile(const std::string &filename);

private:
  size_t _cols = 0;
  size_t _rows = 0;
  std::vector<std::vector<rgb_pixel>> _data;
};