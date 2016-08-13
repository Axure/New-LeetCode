//
// Created by lluvi on 2016/8/13.
//

#ifndef LEETCODE_SOLUTION_HPP
#define LEETCODE_SOLUTION_HPP
#include <deque>
#include <cassert>
#include <sstream>
class Solution {
 private:
  std::deque<int> digits;
 public:
  int reverse(int x) {
    digits.clear();
    auto copy = x;
    while (copy != 0) {
      digits.push_back(copy % 10);
      copy /= 10;
    }
    int sum  = 0;
    for (auto &digit: digits) {
      sum *= 10;
      sum += digit;
    }
    return sum;
  }
};
#endif //LEETCODE_SOLUTION_HPP
