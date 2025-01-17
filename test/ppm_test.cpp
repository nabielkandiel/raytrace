#include "ppm.hpp"
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

// [GENAI]: FUNCTION FROM CHATGPT
// Function to compare two files
bool areFilesEqual(const std::string &file1, const std::string &file2) {
  // Open both files in binary mode
  auto file1size = std::filesystem::file_size(file1);
  auto file2size = std::filesystem::file_size(file2);
  if (file1size != file2size) {
    std::cerr << "file sizes are different " << file1size << " : " << file2size
              << std::endl;
    return false;
  }

  std::ifstream f1(file1, std::ios::binary);
  std::ifstream f2(file2, std::ios::binary);

  // Check if both files were successfully opened
  if (!f1.is_open() || !f2.is_open()) {
    std::cerr << "cannot open files" << std::endl;
    return false; // If one of the files couldn't be opened, they are not equal
  }

  // Compare the files byte by byte
  char ch1, ch2;
  while (f1.get(ch1) && f2.get(ch2)) {
    if (ch1 != ch2) {
      std::cerr << "difference in bytes" << std::endl;
      return false; // If any byte differs, the files are not equal
    }
  }
  return true;
}

TEST(ppm_test, DefaultDataCheck) {
  ppm<size_t> def(5, 10);
  EXPECT_EQ(def.getRows(), 5);
  EXPECT_EQ(def.getCols(), 10);
  const auto &data = def.getData();
  EXPECT_EQ(data.size(), 5);
  EXPECT_EQ(data[0].size(), 10);
}

TEST(ppm_test, MoveDataCheck) {
  int image_width = 256;
  int image_height = 256;
  std::vector<std::vector<Color<size_t>>> data(
      image_height, std::vector<Color<size_t>>(image_width, {0, 0, 0}));
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      size_t ir = int(255.999 * r);
      size_t ig = int(255.999 * g);
      size_t ib = int(255.999 * b);
      data[j][i] = {ir, ig, ib};
    }
  }
  ppm<size_t> image(image_height, image_width, std::move(data));
  EXPECT_EQ(image.getRows(), image_height);
  EXPECT_EQ(image.getCols(), image_width);
  const auto &test_data = image.getData();
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      size_t ir = int(255.999 * r);
      size_t ig = int(255.999 * g);
      size_t ib = int(255.999 * b);
      EXPECT_EQ(test_data[j][i].red(), ir);
      EXPECT_EQ(test_data[j][i].green(), ig);
      EXPECT_EQ(test_data[j][i].blue(), ib);
    }
  }
}

TEST(ppm_test, WriteFileCheck) {
  int image_width = 256;
  int image_height = 256;
  std::vector<std::vector<Color<size_t>>> data(
      image_height, std::vector<Color<size_t>>(image_width, {0, 0, 0}));
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      size_t ir = int(255.999 * r);
      size_t ig = int(255.999 * g);
      size_t ib = int(255.999 * b);
      data[j][i] = {ir, ig, ib};
    }
  }
  ppm<size_t> image(image_height, image_width, std::move(data));
  image.writeImgFile("test_files/TEST.ppm");
  ASSERT_TRUE(areFilesEqual("test_files/TEST.ppm", "test_files/CONTROL.ppm"))
      << "Files should be equal but they are not!";
}