struct NumMatrix {

};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
  for (int i = 0; i < matrixRowSize; ++i) {
    for (int j = 0; j < matrixColSize; ++j) {

    }
  }
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {

}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {

}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);

#include <iostream>
using namespace std;
int main() {
  cout << "Hello, World!" << endl;
  return 0;
}