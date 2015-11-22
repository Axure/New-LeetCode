//
// Created by 郑虎 on 2015-11-21.
//

#include <stddef.h>
#include <iostream>
#include "BinaryTree.h"

/**
 * Cascading deletion. // TODO: What if the deletions are not cascading? E.g. using ARC?
 */
template<typename T>
BinaryTree<T>::~BinaryTree() {
  std::cout << "[BinaryTree]: " << std::endl << this << " is destroyed, value is " << this->getValue() << std::endl;

  auto pLeft = this->getLeft();
  /**
  * If the left child exists, decrease its reference count.
  */
  if (pLeft != nullptr) {
    pLeft->decreaseReferenceCount();
    /**
     * If already nothing references to the left child, destroy it.
     */
    if (pLeft->getReferenceCount() <= 0) {
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
    if (pRight->getReferenceCount() <= 0) {
      this->pRight->~BinaryTree();
    }
  }
}

template<typename T>
BinaryTree<T>::BinaryTree() : pLeft(nullptr), pRight(nullptr), _referenceCount(0) {
}

template<typename T>
BinaryTree<T>::BinaryTree(T value) : BinaryTree() {
  std::cout << "initialized with" << value << std::endl;
  this->setValue(value);
}

template<typename T>
void BinaryTree<T>::preOrderTraverse(std::function<void(T)> &lambda) {
  /**
   * Traverse the root.
   */
  lambda(this->getValue());

  auto pLeft = this->getLeft();
  /**
   * Traverse the left branch.
   */
  if (pLeft != nullptr) {
    std::cout << std::endl << "left";
    pLeft->preOrderTraverse(lambda);
  }

  auto pRight = this->getRight();
  /**
   * Traverse the right branch.
   */
  if (pRight != nullptr) {
    std::cout << std::endl << "right";
    pRight->preOrderTraverse(lambda);
  }
}

template<typename T>
void BinaryTree<T>::inOrderTraverse(std::function<void(T)> &lambda) {
  auto pLeft = this->getLeft();
  /**
   * Traverse the left branch.
   */
  if (pLeft != nullptr) {
    std::cout << std::endl << "left";
    pLeft->inOrderTraverse(lambda);
  }

  /**
   * Traverse the root.
   */
  lambda(this->getValue());

  auto pRight = this->getRight();
  /**
   * Traverse the right branch.
   */
  if (pRight != nullptr) {
    std::cout << std::endl << "right";
    pRight->inOrderTraverse(lambda);
  }
}

template<typename T>
void BinaryTree<T>::postOrderTraverse(std::function<void(T)> &lambda) {
  auto pLeft = this->getLeft();
  /**
   * Traverse the left branch.
   */
  if (pLeft != nullptr) {
    std::cout << std::endl << "left";
    pLeft->postOrderTraverse(lambda);
  }

  auto pRight = this->getRight();
  /**
   * Traverse the right branch.
   */
  if (pRight != nullptr) {
    std::cout << std::endl << "right";
    pRight->postOrderTraverse(lambda);
  }

  /**
   * Traverse the root.
   */
  lambda(this->getValue());
}

template
class BinaryTree<int>;