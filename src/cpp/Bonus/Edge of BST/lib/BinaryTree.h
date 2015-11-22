//
// Created by 郑虎 on 2015-11-21.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <functional>
#include <iostream>
#include <vector>

template<typename T>
class BinaryTree {

 private:
  BinaryTree *pLeft;
  BinaryTree *pRight;
  T _value;
  int _referenceCount;

  void setReferenceCount(int value) {
    std::cout << "[BinaryTree]: The reference count of " << this << " is set to " << value << ", previously "
        << _referenceCount << std::endl;
    this->_referenceCount = value;
  }

 public:
  virtual ~BinaryTree();
  BinaryTree();
  BinaryTree(T value);

  virtual BinaryTree *getLeft() const {
    return pLeft;
  }

  virtual BinaryTree *getRight() const {
    return pRight;
  }

  T getValue() const {
    return _value;
  }

  int getReferenceCount() const {
    return _referenceCount;
  }

  void increaseReferenceCount() {
    this->setReferenceCount(this->getReferenceCount() + 1);
  }

  void decreaseReferenceCount() {
    this->setReferenceCount(this->getReferenceCount() - 1);
  }

  void setLeft(BinaryTree *const pLeft) {
    if (this->pLeft != nullptr) {
      this->pLeft->decreaseReferenceCount();
    }
    this->pLeft = pLeft;
    pLeft->increaseReferenceCount();
  }

  void setRight(BinaryTree *const pRight) {
    if (this->pRight != nullptr) {
      this->pRight->decreaseReferenceCount();
    }
    this->pRight = pRight;
    pRight->increaseReferenceCount();
  }

  void setValue(T _value) {
    this->_value = _value;
  }

  void preOrderTraverse(const std::function<void(BinaryTree *const)> &lambda);
  std::vector<BinaryTree *> getPreOrderList();
  void inOrderTraverse(const std::function<void(BinaryTree *const)> &lambda);
  void postOrderTraverse(const std::function<void(BinaryTree *const)> &lambda);

  BinaryTree *createLeft(T value);
  BinaryTree *createRight(T value);

  void print() const;
  int getWidth(int elementWidth) const;
  int getDepth() const;

  void fillInBoard(const BinaryTree *node, int boardWidth, std::string *board, int baseDepth, int baseWidth) const;
  static std::string toString(T value);
};

#endif //LEETCODE_BINARYTREE_H
