//
// Created by 郑虎 on 2015-11-21.
//

#include <stddef.h>
#include "BinaryTree.h"

/**
 * Cascading deletion. // TODO: What if the deletions are not cascading? E.g. using ARC?
 */
template<typename T>
BinaryTree::~BinaryTree() {

  auto pLeft = this->getLeft();
  /**
  * If the left child exists, decrease its reference count.
  */
  if (pLeft != nullptr) {
    pLeft->decreaseReferenceCount();
    /**
     * If already nothing references to the left child, destroy it.
     */
    if (pLeft->getReferenceCount() == 0) {
      pLeft->~BinaryTree();
    }
  }

  auto pRight = this->getRight();
  /**
   * If the right child exists, decrease its reference count.
   */
  if (pRight != nullptr) {
    pRight->decreaseReferenceCount();
    /**
     * If already nothing references to the right child, destroy it.
     */
    if (pRight->getReferenceCount() == 0) {
      this->pRight->~BinaryTree();
    }
  }
}

template<typename T>
BinaryTree::BinaryTree() {
  this->setReferenceCount(0);
}

template<typename T>
BinaryTree::BinaryTree(T value) {
  this->setValue(value);
}

template<typename T>
void BinaryTree::preOrderTraverse(std::function<void(T)> &lambda) {
  lambda(this->getValue());
  auto pLeft = this->getLeft();
  if (pLeft != nullptr) {
    pLeft->preOrderTraverse(lambda);
  }
  auto pRight = this->getRight();
  if (pRight != nullptr) {
    pRight->preOrderTraverse(lambda);
  }
}
