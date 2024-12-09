#include "color.hpp"
#include <gtest/gtest.h>

using util::Color;

// Test default constructor
TEST(ColorTest, DefaultConstructor) {
  Color<int> color;
  EXPECT_EQ(color.red(), 0);
  EXPECT_EQ(color.green(), 0);
  EXPECT_EQ(color.blue(), 0);
}

// Test parameterized constructor with valid inputs
TEST(ColorTest, ParameterizedConstructorValid) {
  Color<int> color(255, 128, 64);
  EXPECT_EQ(color.red(), 255);
  EXPECT_EQ(color.green(), 128);
  EXPECT_EQ(color.blue(), 64);
}

// Test parameterized constructor with negative inputs
TEST(ColorTest, ParameterizedConstructorNegative) {
  Color<int> color(-10, -20, -30);
  EXPECT_EQ(color.red(), 0);
  EXPECT_EQ(color.green(), 0);
  EXPECT_EQ(color.blue(), 0);
}

// Test addition operator
TEST(ColorTest, AdditionOperator) {
  Color<int> color1(100, 50, 25);
  Color<int> color2(50, 50, 50);
  Color<int> result = color1 + color2;
  EXPECT_EQ(result.red(), 150);
  EXPECT_EQ(result.green(), 100);
  EXPECT_EQ(result.blue(), 75);
}

// Test subtraction operator with non-negative results
TEST(ColorTest, SubtractionOperatorNonNegative) {
  Color<int> color1(100, 50, 25);
  Color<int> color2(50, 25, 10);
  Color<int> result = color1 - color2;
  EXPECT_EQ(result.red(), 50);
  EXPECT_EQ(result.green(), 25);
  EXPECT_EQ(result.blue(), 15);
}

// Test subtraction operator with negative results
TEST(ColorTest, SubtractionOperatorNegative) {
  Color<int> color1(50, 25, 10);
  Color<int> color2(100, 50, 25);
  Color<int> result = color1 - color2;
  EXPECT_EQ(result.red(), 0);
  EXPECT_EQ(result.green(), 0);
  EXPECT_EQ(result.blue(), 0);
}

// test += with other color
TEST(ColorTest, PlusEqColorOperator) {
  Color<int> color1(50, 25, 10);
  Color<int> color2(100, 50, 25);
  color1 += color2;
  EXPECT_EQ(color1.red(), 150);
  EXPECT_EQ(color1.green(), 75);
  EXPECT_EQ(color1.blue(), 35);
}

// test -= with other color
TEST(ColorTest, SubEqColorOperator) {
  Color<int> color1(100, 50, 25);
  Color<int> color2(50, 25, 10);
  color1 -= color2;
  EXPECT_EQ(color1.red(), 50);
  EXPECT_EQ(color1.green(), 25);
  EXPECT_EQ(color1.blue(), 15);
}

// test -= with other color and negative res
TEST(ColorTest, SubEqColorOperatorNegative) {
  Color<int> color1(50, 25, 10);
  Color<int> color2(100, 50, 25);
  color1 -= color2;
  EXPECT_EQ(color1.red(), 0);
  EXPECT_EQ(color1.green(), 0);
  EXPECT_EQ(color1.blue(), 0);
}

// test *= with other color
TEST(ColorTest, DotProdOp) {
  Color<int> color1(5, 4, 3);
  Color<int> color2(2, 1, 0);
  color1 *= color2;
  EXPECT_EQ(color1.red(), 10);
  EXPECT_EQ(color1.green(), 4);
  EXPECT_EQ(color1.blue(), 0);
}

// test /= with other color
TEST(ColorTest, DivProdOp) {
  Color<int> color1(15, 15, 15);
  Color<int> color2(5, 3, 1);
  color1 /= color2;
  EXPECT_EQ(color1.red(), 3);
  EXPECT_EQ(color1.green(), 5);
  EXPECT_EQ(color1.blue(), 15);
}

// Test scalar addition
TEST(ColorTest, ScalarAddition) {
  Color<int> color(10, 20, 30);
  color += 2;
  EXPECT_EQ(color.red(), 12);
  EXPECT_EQ(color.green(), 22);
  EXPECT_EQ(color.blue(), 32);
}

// Test scalar addition with negative
TEST(ColorTest, ScalarAdditionNegative) {
  Color<int> color(10, 20, 30);
  color += -12;
  EXPECT_EQ(color.red(), 0);
  EXPECT_EQ(color.green(), 8);
  EXPECT_EQ(color.blue(), 18);
}

// Test scalar subtraction
TEST(ColorTest, ScalarSubtraction) {
  Color<int> color(10, 20, 30);
  color -= 2;
  EXPECT_EQ(color.red(), 8);
  EXPECT_EQ(color.green(), 18);
  EXPECT_EQ(color.blue(), 28);
}

// Test scalar subtraction with negative
TEST(ColorTest, ScalarSubtractionNegative) {
  Color<int> color(10, 20, 30);
  color -= 12;
  EXPECT_EQ(color.red(), 0);
  EXPECT_EQ(color.green(), 8);
  EXPECT_EQ(color.blue(), 18);
}

// Test scalar multiplication
TEST(ColorTest, ScalarMultiplication) {
  Color<int> color(10, 20, 30);
  color *= 2;
  EXPECT_EQ(color.red(), 20);
  EXPECT_EQ(color.green(), 40);
  EXPECT_EQ(color.blue(), 60);
}

// Test scalar multiplication with negative value
TEST(ColorTest, ScalarMultiplicationNegative) {
  Color<int> color(10, 20, 30);
  EXPECT_THROW(color *= -1, std::runtime_error);
}

// Test scalar division
TEST(ColorTest, ScalarDivision) {
  Color<int> color(20, 40, 60);
  color /= 2;
  EXPECT_EQ(color.red(), 10);
  EXPECT_EQ(color.green(), 20);
  EXPECT_EQ(color.blue(), 30);
}

// Test scalar division with negative value
TEST(ColorTest, ScalarDivisionNegative) {
  Color<int> color(20, 40, 60);
  EXPECT_THROW(color /= -1, std::runtime_error);
}

// Test indexing
TEST(ColorTest, Indexing) {
  Color<int> color(255, 128, 64);
  EXPECT_EQ(color[0], 255);
  EXPECT_EQ(color[1], 128);
  EXPECT_EQ(color[2], 64);
}

// Test stream output operator
TEST(ColorTest, StreamOutputOperator) {
  Color<int> color(10, 20, 30);
  std::ostringstream os;
  os << color;
  EXPECT_EQ(os.str(), "10 20 30");
}