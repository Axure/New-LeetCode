#include <iostream>

#include "lib/Bst.h"

void print(int a) {
  std::cout << a << ", ";
}

int main(int argc, char *argv[]) {
  int v = 3;
  BinaryTree *a = new BinaryTree(v);
  a->preOrderTraverse(&std::move(print));
  return 0;

};
