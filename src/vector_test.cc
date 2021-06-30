#include "gtest/gtest.h"

#include "vector.h"

TEST(VectorSize, BasicAssertions) {
  fig::vector<int> ints;
  EXPECT_EQ(ints.size(), 0);
  ints.push_back(0);
  EXPECT_EQ(ints.size(), 1);
  ints.pop_back();
  EXPECT_EQ(ints.size(), 0);
}

TEST(VectorCapacity, BasicAssertions) {
  fig::vector<int> ints;
  EXPECT_EQ(ints.capacity(), 0);
  ints.push_back(0);
  EXPECT_EQ(ints.capacity(), 1);
  ints.push_back(0);
  EXPECT_EQ(ints.capacity(), 2);
  ints.push_back(0);
  EXPECT_EQ(ints.capacity(), 4);
  ints.pop_back();
  EXPECT_EQ(ints.capacity(), 4);
}

TEST(VectorGetRawData, BasicAssertions) {
  fig::vector<int> ints;
  EXPECT_EQ(ints.data(), nullptr);
  ints.push_back(0);
  EXPECT_NE(ints.data(), nullptr);
}
