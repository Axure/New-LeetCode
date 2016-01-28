#include <vector>
#include <map>
using namespace std;
/**
 * A brutal solution?
 */
class Solution {
 private:
  map<int, bool> canSumUpTo;
  vector<int> reachableSums;
  vector<int> requiredPatches;
 public:
  int minPatches(vector<int>& nums, int n) {
    size_t size = nums.size();
//    int min = nums.at(0);
//    int max = nums.at(nums.size() - 1);
//    int min_hole = 0;

//    int top = nums.at(0);
//    reachableSums.push_back(top);
    reachableSums.push_back(0);
    canSumUpTo[0] = true;
//    canSumUpTo[top] = true;

    int index = 0;
    int currentSum = 1;


    while((index < size) && (currentSum <= n)) {
      while (currentSum != nums.at(index) && canSumUpTo.find(currentSum) != canSumUpTo.end()) {
        currentSum++;
      }
      if (currentSum == nums.at(index)) {
        /**
         * Add
         */
        while ( index < size &&currentSum == nums.at(index)) {
          index++;
        }
      } else {
        /**
         * Add manually
         */
        requiredPatches.push_back(currentSum);
      }
      /**
       * Update
       */
      size_t reachableSize = reachableSums.size();
      for (int i = 0; i < reachableSize; ++i) {
        int newSum = reachableSums[i] + currentSum;
        if (canSumUpTo.find(newSum) != canSumUpTo.end()) {
        } else {
          reachableSums.push_back(newSum);
          canSumUpTo[newSum] = true;
        }
      }
      /**
       * Find the smallest number which cannot be summed up to.
       * If we find a number provided, update the canSumUpTo dictionary.
       */
//      if (nums.at(index) - min > 1) {
//        min_hole = min + 1;
//      }
      /**
       * How to effectively determine if a number can be forged?
       *
       * Just put it in a map?
       */
//      if (canSumUpTo.find(min_hole) != canSumUpTo.end()) {
        /**
         * If we can sum up to that? skip it...
         */
//      }
      currentSum++;
    }
    return static_cast<int>(requiredPatches.size());
  }
};