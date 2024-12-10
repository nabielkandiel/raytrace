#include "ray.hpp"
#include <gtest/gtest.h>

TEST(ray_test, DefaultDataCheck) {
  Ray<int> r1;
  Util::Vec3<int> v1(0, 0, 0);
  EXPECT_EQ(r1.direction(), v1);
  EXPECT_EQ(r1.origin(), v1);
  EXPECT_EQ(r1.at(0), v1);
  EXPECT_EQ(r1.at(5), v1);
}

TEST(ray_test, DataCheck) {
  Util::Vec3<int> v1(1, 2, 3);
  Util::Vec3<int> v2(1, 3, 5);
  Ray<int> r1(v1, v2);
  Util::Vec3<int> res2 = v1 + 5 * v2;
  EXPECT_EQ(r1.origin(), v1);
  EXPECT_EQ(r1.direction(), v2);
  EXPECT_EQ(r1.at(0), v1);
  EXPECT_EQ(r1.at(5), res2);
}