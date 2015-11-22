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
void BinaryTree<T>::preOrderTraverse(const std::function<void(BinaryTree<T>* const)> &lambda) {
  /**
   * Traverse the root.
   */
  lambda(this);

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
std::vector<BinaryTree<T>*> BinaryTree<T>::getPreOrderList() {
  std::vector<BinaryTree<T>*> result;
  auto push = [&result](BinaryTree<T> * const element) mutable {
    result.push_back(element);
  };
  this->preOrderTraverse(push);
  return result;
}

template<typename T>
void BinaryTree<T>::inOrderTraverse(const std::function<void(BinaryTree<T>* const)> &lambda) {
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
  lambda(this);

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
void BinaryTree<T>::postOrderTraverse(const std::function<void(BinaryTree<T>* const)> &lambda) {
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
  lambda(this);
}

template<typename T>
BinaryTree<T> *BinaryTree<T>::createLeft(T value) {
  if (this->getLeft() == nullptr) {
    this->setLeft(new BinaryTree(value));
  }
  return this->getLeft();
}

template<typename T>
BinaryTree<T> *BinaryTree<T>::createRight(T value) {
  if (this->getRight() == nullptr) {
    this->setRight(new BinaryTree(value));
  }
  return this->getRight();
}

#include <algorithm>

template <typename T>
void BinaryTree<T>::print() {
  const auto depth = this->getDepth();
  const auto width = this->getWidth(1);
  auto buffer = new char[depth * width];

  for (int i = 0; i < this->getDepth(); ++i) {
    for (int j = 0; j < this->getWidth(1); ++j) {
      buffer[i * width + j] =  '*';
    }
    std::cout << std::endl;
  }

  for (int i = 0; i < this->getDepth(); ++i) {
    for (int j = 0; j < this->getWidth(1); ++j) {
      std::cout << buffer[i * width + j];
    }
    std::cout << std::endl;
  }

  delete buffer;
}

//template <typename T>
//void BinaryTree<T>::printInsideBoard(int boardWidth, )

template <typename T>
int BinaryTree<T>::getWidth(int elementWidth) {


  auto pLeft = this->getLeft();
  auto pRight = this->getRight();
  int widthLeft = pLeft == nullptr ? 0 : pLeft->getWidth(elementWidth);
  int widthRight = pRight == nullptr ? 0 : pRight->getWidth(elementWidth);

  return elementWidth + 2 + widthLeft + widthRight;
}

template <typename T>
int BinaryTree<T>::getDepth() {
  auto pLeft = this->getLeft();
  auto pRight = this->getRight();
  int depthLeft = pLeft == nullptr ? 0 : pLeft->getDepth();
  int depthRight = pRight == nullptr ? 0 : pRight->getDepth();
  
  return 1 + std::max(depthLeft, depthRight);
}


template
class BinaryTree<int>;
