#include <iostream>

#include "lib/Bst.h"

void print(int a) {
  std::cout << a << ", ";
}

int main(int argc, char *argv[]) {
  int v = 3;
  auto *a = new BinaryTree<int>(v);
  auto *b = new BinaryTree<int>(4);
  auto *c = new BinaryTree<int>(5);
  auto *d = new BinaryTree<int>(6);
  a->setLeft(b);
  b->setLeft(d);
  a->setRight(c);


  std::function<void(int)> f = print;

  a->preOrderTraverse(f);
  return 0;

};
