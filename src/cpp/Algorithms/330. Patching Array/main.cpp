#include "Solution.hpp"
#include <iostream>
int main() {
  auto solution = Solution();
  vector<int> array = {1, 3};

  std::cout << solution.minPatches(array, 6);

  return 0;
}