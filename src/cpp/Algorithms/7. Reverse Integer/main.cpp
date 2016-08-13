#include "Solution.hpp"
#include <gtest/gtest.h>

TEST(BASIC, EQ) {
  ASSERT_EQ(1, 1);
}

TEST(BASIC, SIMPLE_TEST_123) {
  Solution solution;
  auto answer = solution.reverse(123);
  ASSERT_EQ(answer, 321);
}

TEST(BASIC, SIMPLE_TEST_17320) {
  Solution solution;
  auto answer = solution.reverse(17320);
  ASSERT_EQ(answer, 2371);
}

TEST(BASIC, SIMPLE_TEST_MINUS_1235) {
  Solution solution;
  auto answer = solution.reverse(-1235);
  ASSERT_EQ(answer, -5321);
}