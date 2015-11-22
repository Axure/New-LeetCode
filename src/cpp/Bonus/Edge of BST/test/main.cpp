#include <iostream>

#include "../lib/Bst.h"

void print(BinaryTree<int> const *a) {
  std::cout << a->getValue() << ", ";
}

int main(int argc, char *argv[]) {
  int v = 3;
  auto *a = new BinaryTree<int>(v);
  auto *b = new BinaryTree<int>(4);
  auto *c = new BinaryTree<int>(5);
  auto *d = new BinaryTree<int>(6);
  a->setLeft(b);
  b->setLeft(c);
  a->setRight(d);
  c->createLeft(7)->createRight(9);


  std::function<void(BinaryTree<int> * const)> f = print;

  std::cout << "[main]: Preorder traversal: ";
  a->preOrderTraverse(f);
  std::cout << "[main]: Inorder traversal: ";
  a->inOrderTraverse(f);
  std::cout << "[main]: Postorder traversal: ";
  a->postOrderTraverse(f);
  a->print();
  auto r = a->getPreOrderList();
  for (auto rs: r) {
    std::cout << "Traverse from vector: "  << rs->getValue() << std::endl;
  }

  std::cout << "[main]: The depth of a is " << a->getDepth() << std::endl;
  std::cout << "[main]: The width of a is " << a->getWidth(1) << std::endl;

  delete a;
  b->preOrderTraverse(f);
  delete b;
  c->preOrderTraverse(f);

  return 0;

};
