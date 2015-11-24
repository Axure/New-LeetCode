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
      pRight->~BinaryTree();
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
void BinaryTree<T>::preOrderTraverse(const std::function<void(BinaryTree<T> *const)> &lambda) {
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
std::vector<BinaryTree<T> *> BinaryTree<T>::getPreOrderList() {
  std::vector<BinaryTree<T> *> result;
  auto push = [&result](BinaryTree<T> *const element) mutable {
    result.push_back(element);
  };
  this->preOrderTraverse(push);
  return result;
}

template<typename T>
void BinaryTree<T>::inOrderTraverse(const std::function<void(BinaryTree<T> *const)> &lambda) {
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
void BinaryTree<T>::postOrderTraverse(const std::function<void(BinaryTree<T> *const)> &lambda) {
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

template<typename T>
void BinaryTree<T>::print() const {
  const auto depth = this->getDepth();
  const auto width = this->getWidth(1);
  auto buffer = new std::string[depth * width];

  for (int i = 0; i < this->getDepth(); ++i) {
    for (int j = 0; j < this->getWidth(1); ++j) {
      buffer[i * width + j] = '_';
    }
    std::cout << std::endl;
  }

  this->fillInBoard(this, width, buffer, 0, 0);
  for (int i = 0; i < this->getDepth(); ++i) {
    for (int j = 0; j < this->getWidth(1); ++j) {
      std::cout << buffer[i * width + j];
    }
    std::cout << std::endl;
  }

//  std::free(buffer); // TODO: figure out why this cannot be deleted: `pointer being freed was not allocated`.
}

/**
 *
 */
template<typename T>
void BinaryTree<T>::fillInBoard(const BinaryTree<T> *node,
                                int boardWidth,
                                std::string *board,
                                int baseDepth,
                                int baseWidth) const {
  std::cout << "paramters: " << boardWidth << ", " << baseDepth << ", " << baseWidth << std::endl;
  const int width = node->getWidth(1);
  const auto pLeft = node->getLeft();
  const auto pRight = node->getRight();
  const int leftWidth = pLeft == nullptr ? 0 : pLeft->getWidth(1);
  const int rightWidth = pRight == nullptr ? 0 : pRight->getWidth(1);
  /**
   * Fill the exact place with an indicator.
   */
  /**
   * Fill the other positions with a placeholder.
   */
  const int baseIndex = baseDepth * boardWidth + baseWidth;
  std::cout << "calculated: " << width << ", " << leftWidth << ", " << rightWidth << ", " << baseIndex << std::endl;
  for (int i = baseIndex; i < baseIndex + leftWidth; ++i) {
    board[i] = '_';
  }
  for (int i = baseIndex + leftWidth; i < baseIndex + leftWidth + 3; ++i) {
    if (i == baseIndex + leftWidth + 1) {
      board[i] = BinaryTree<T>::toString(node->getValue());
    } else {
      board[i] = '*';
    }
  }
  for (int i = baseIndex + leftWidth + 3; i < baseIndex + width; ++i) {
    board[i] = '_';
  }
  /**
   * Fill in the domains controlled by its children.
   */
  if (pLeft != nullptr) {
    this->fillInBoard(pLeft, boardWidth, board, baseDepth + 1, baseWidth);
  }
  if (pRight != nullptr) {
    this->fillInBoard(pRight, boardWidth, board, baseDepth + 1, baseWidth + leftWidth + 3);
  }
}

template<typename T>
int BinaryTree<T>::getWidth(int elementWidth) const {

  auto pLeft = this->getLeft();
  auto pRight = this->getRight();
  int widthLeft = pLeft == nullptr ? 0 : pLeft->getWidth(elementWidth);
  int widthRight = pRight == nullptr ? 0 : pRight->getWidth(elementWidth);

  return elementWidth + 2 + widthLeft + widthRight;
}

template<typename T>
int BinaryTree<T>::getDepth() const {
  auto pLeft = this->getLeft();
  auto pRight = this->getRight();
  int depthLeft = pLeft == nullptr ? 0 : pLeft->getDepth();
  int depthRight = pRight == nullptr ? 0 : pRight->getDepth();

  return 1 + std::max(depthLeft, depthRight);
}

template<>
std::string BinaryTree<int>::toString(int value) {
  return std::to_string(value);
}

template
class BinaryTree<int>;