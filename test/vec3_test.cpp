#include "vec3.hpp"
#include <gtest/gtest.h>

using Util::Vec3;

// Test default constructor
TEST(Vec3Test, DefaultConstructor) {
  Vec3<int> Vec3;
  EXPECT_EQ(Vec3[0], 0);
  EXPECT_EQ(Vec3[1], 0);
  EXPECT_EQ(Vec3[2], 0);
}

// Test parameterized constructor with valid inputs
TEST(Vec3Test, ParameterizedConstructorValid) {
  Vec3<int> Vec3(255, 128, 64);
  EXPECT_EQ(Vec3[0], 255);
  EXPECT_EQ(Vec3[1], 128);
  EXPECT_EQ(Vec3[2], 64);
}

// Test parameterized constructor with negative inputs
TEST(Vec3Test, ParameterizedConstructorNegative) {
  Vec3<int> Vec3(-10, -20, -30);
  EXPECT_EQ(Vec3[0], -10);
  EXPECT_EQ(Vec3[1], -20);
  EXPECT_EQ(Vec3[2], -30);
}

// Test addition operator
TEST(Vec3Test, AdditionOperator) {
  Vec3<int> Vec31(100, 50, 25);
  Vec3<int> Vec32(50, 50, 50);
  Vec3<int> result = Vec31 + Vec32;
  EXPECT_EQ(result[0], 150);
  EXPECT_EQ(result[1], 100);
  EXPECT_EQ(result[2], 75);
}

// Test subtraction operator with non-negative results
TEST(Vec3Test, SubtractionOperatorNonNegative) {
  Vec3<int> Vec31(100, 50, 25);
  Vec3<int> Vec32(50, 25, 10);
  Vec3<int> result = Vec31 - Vec32;
  EXPECT_EQ(result[0], 50);
  EXPECT_EQ(result[1], 25);
  EXPECT_EQ(result[2], 15);
}

// Test subtraction operator with negative results
TEST(Vec3Test, SubtractionOperatorNegative) {
  Vec3<int> Vec31(50, 25, 10);
  Vec3<int> Vec32(100, 50, 25);
  Vec3<int> result = Vec31 - Vec32;
  EXPECT_EQ(result[0], -50);
  EXPECT_EQ(result[1], -25);
  EXPECT_EQ(result[2], -15);
}

// Test multiplication with another vec3
TEST(Vec3Test, multiplyOtherVec) {
  Vec3<int> Vec31(2, 3, 4);
  Vec3<int> Vec32(1, 2, 3);
  Vec3<int> result = Vec31 * Vec32;
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 6);
  EXPECT_EQ(result[2], 12);
}

// Test multiplication with scalor
TEST(Vec3Test, multiplyScalor) {
  Vec3<int> Vec31(50, 25, 10);
  Vec3<int> result = Vec31 * 3;
  EXPECT_EQ(result[0], 150);
  EXPECT_EQ(result[1], 75);
  EXPECT_EQ(result[2], 30);
  Vec3<int> result2 = 3 * Vec31;
  EXPECT_EQ(result2[0], 150);
  EXPECT_EQ(result2[1], 75);
  EXPECT_EQ(result2[2], 30);
}

// Test division with another vec3
TEST(Vec3Test, divideOtherVec) {
  Vec3<int> Vec31(2, 4, 6);
  Vec3<int> Vec32(1, 2, 3);
  Vec3<int> result = Vec31 / Vec32;
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 2);
  EXPECT_EQ(result[2], 2);
}

// Test division with scalor
TEST(Vec3Test, divideScalor) {
  Vec3<int> Vec31(50, 25, 10);
  Vec3<int> result = Vec31 / 5;
  EXPECT_EQ(result[0], 10);
  EXPECT_EQ(result[1], 5);
  EXPECT_EQ(result[2], 2);
}

// test += with other Vec3
TEST(Vec3Test, PlusEqVec3Operator) {
  Vec3<int> Vec31(50, 25, 10);
  Vec3<int> Vec32(100, 50, 25);
  Vec31 += Vec32;
  EXPECT_EQ(Vec31[0], 150);
  EXPECT_EQ(Vec31[1], 75);
  EXPECT_EQ(Vec31[2], 35);
}

// test -= with other Vec3
TEST(Vec3Test, SubEqVec3Operator) {
  Vec3<int> Vec31(100, 50, 25);
  Vec3<int> Vec32(50, 25, 10);
  Vec31 -= Vec32;
  EXPECT_EQ(Vec31[0], 50);
  EXPECT_EQ(Vec31[1], 25);
  EXPECT_EQ(Vec31[2], 15);
}

// test -= with other Vec3 and negative res
TEST(Vec3Test, SubEqVec3OperatorNegative) {
  Vec3<int> Vec31(50, 25, 10);
  Vec3<int> Vec32(100, 50, 25);
  Vec31 -= Vec32;
  EXPECT_EQ(Vec31[0], -50);
  EXPECT_EQ(Vec31[1], -25);
  EXPECT_EQ(Vec31[2], -15);
}

// test *= with other Vec3
TEST(Vec3Test, DotProdOp) {
  Vec3<int> Vec31(5, 4, 3);
  Vec3<int> Vec32(2, -1, 0);
  Vec31 *= Vec32;
  EXPECT_EQ(Vec31[0], 10);
  EXPECT_EQ(Vec31[1], -4);
  EXPECT_EQ(Vec31[2], 0);
}

// test /= with other Vec3
TEST(Vec3Test, DivProdOp) {
  Vec3<int> Vec31(15, 15, 15);
  Vec3<int> Vec32(5, -3, 1);
  Vec31 /= Vec32;
  EXPECT_EQ(Vec31[0], 3);
  EXPECT_EQ(Vec31[1], -5);
  EXPECT_EQ(Vec31[2], 15);
}

// Test scalar addition
TEST(Vec3Test, ScalarAddition) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 += 2;
  EXPECT_EQ(Vec3[0], 12);
  EXPECT_EQ(Vec3[1], 22);
  EXPECT_EQ(Vec3[2], 32);
}

// Test scalar addition with negative
TEST(Vec3Test, ScalarAdditionNegative) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 += -12;
  EXPECT_EQ(Vec3[0], -2);
  EXPECT_EQ(Vec3[1], 8);
  EXPECT_EQ(Vec3[2], 18);
}

// Test scalar subtraction
TEST(Vec3Test, ScalarSubtraction) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 -= 2;
  EXPECT_EQ(Vec3[0], 8);
  EXPECT_EQ(Vec3[1], 18);
  EXPECT_EQ(Vec3[2], 28);
}

// Test scalar subtraction with negative
TEST(Vec3Test, ScalarSubtractionNegative) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 -= 12;
  EXPECT_EQ(Vec3[0], -2);
  EXPECT_EQ(Vec3[1], 8);
  EXPECT_EQ(Vec3[2], 18);
}

// Test scalar multiplication
TEST(Vec3Test, ScalarMultiplication) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 *= 2;
  EXPECT_EQ(Vec3[0], 20);
  EXPECT_EQ(Vec3[1], 40);
  EXPECT_EQ(Vec3[2], 60);
}

// Test scalar multiplication with negative value
TEST(Vec3Test, ScalarMultiplicationNegative) {
  Vec3<int> Vec3(10, 20, 30);
  Vec3 *= -2;
  EXPECT_EQ(Vec3[0], -20);
  EXPECT_EQ(Vec3[1], -40);
  EXPECT_EQ(Vec3[2], -60);
}

// Test scalar division
TEST(Vec3Test, ScalarDivision) {
  Vec3<int> Vec3(20, 40, 60);
  Vec3 /= 2;
  EXPECT_EQ(Vec3[0], 10);
  EXPECT_EQ(Vec3[1], 20);
  EXPECT_EQ(Vec3[2], 30);
}

// Test scalar division with negative value
TEST(Vec3Test, ScalarDivisionNegative) {
  Vec3<int> Vec3(20, 40, 60);
  Vec3 /= -2;
  EXPECT_EQ(Vec3[0], -10);
  EXPECT_EQ(Vec3[1], -20);
  EXPECT_EQ(Vec3[2], -30);
}

// Test stream output operator
TEST(Vec3Test, StreamOutputOperator) {
  Vec3<int> Vec3(10, 20, 30);
  std::ostringstream os;
  os << Vec3;
  EXPECT_EQ(os.str(), "10 20 30");
}

// Test == operatot
TEST(Vec3Test, testEqual) {
  Vec3<int> v1(20, 40, 60);
  Vec3<int> v2(20, 40, 60);
  Vec3<int> v3(22, 40, 60);
  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v2 == v3);
}