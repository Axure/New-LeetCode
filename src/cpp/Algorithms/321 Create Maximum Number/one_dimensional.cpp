/**
 * What is the maximum number composed with a sub-sequence of a given sequence, in its original order?
 */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int *maxNumber(int *nums, int numsSize) {

  return 0;
}

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  int numbers[100];
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

//  int prev_answer[101] = {};
//  int current_answer[101] = {};

  int *prev_answer = new int[101]();
  int *current_answer = new int[101]();

  for (int j = 0; j < m; ++j) {

    int max_prev = 0;
    for (int i = n - 1 - j; i >= 0; --i) {
      max_prev = max(prev_answer[i + 1], max_prev);
      current_answer[i] = numbers[i] * (int)pow(10, j) + max_prev;
    }
    int *temp_pointer;
    temp_pointer = prev_answer;
    prev_answer = current_answer;
    current_answer = temp_pointer;
  }

  int result = 0;
  for (int i = 0; i < n + 1 - m; ++i) {
    result = max(result, prev_answer[i]);
  }
  cout << result;
  return 0;
}