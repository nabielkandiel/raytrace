#pragma once
#include "color.hpp"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using Util::Color;

template <typename T> class ppm {
public:
  ppm(const size_t rows, const size_t cols) {
    if (rows == 0 || cols == 0)
      return;
    _rows = rows;
    _cols = cols;
    _data.resize(rows);
    for (size_t i = 0; i < rows; i++) {
      _data[i].resize(cols);
    }
  }
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<Color<T>>> &data) {
    if (rows > 0 && rows == data.size() && cols == data[0].size()) {
      for (const auto &col : data) {
        if (col.size() != cols)
          return;
      }
      _rows = rows;
      _cols = cols;
      _data = data;
    }
  }
  ppm(const size_t rows, const size_t cols,
      const std::vector<std::vector<Color<T>>> &&data) {
    if (rows > 0 && rows == data.size() && cols == data[0].size()) {
      for (const auto &col : data) {
        if (col.size() != cols)
          return;
      }
      _rows = rows;
      _cols = cols;
      _data = std::move(data);
    }
  }

  const std::vector<std::vector<Color<T>>> &getData() const { return _data; }
  size_t getRows() { return _rows; }
  size_t getCols() { return _cols; }

  bool writeImgFile(const std::string &filename) {
    std::ofstream outfile(filename);

    if (!outfile.is_open()) {
      std::cerr << "Could not open output file" << std::endl;
    }
    outfile << "P3" << std::endl;
    outfile << _cols << " " << _rows << std::endl;
    outfile << "255" << std::endl;
    for (size_t height = 0; height < _rows; height++) {
      std::clog << "\rScanlines remaining: " << (_rows - height) << ' '
                << std::flush;
      for (size_t width = 0; width < _cols; width++) {
        outfile << _data[height][width] << " ";
      }
      outfile << std::endl;
    }
    std::clog << "\rDone.                 \n";
    outfile.close();
    return true;
  }

private:
  size_t _cols = 0;
  size_t _rows = 0;
  std::vector<std::vector<Color<T>>> _data;
};