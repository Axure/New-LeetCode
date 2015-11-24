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

 protected:
  void *pLeft;
  void *pRight;

 private:
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
    return (BinaryTree*)pLeft;
  }

  virtual BinaryTree *getRight() const {
    return (BinaryTree*)pRight;
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

  virtual void setLeft(BinaryTree *const pLeft) {
    if (this->getLeft() != nullptr) {
      this->getLeft()->decreaseReferenceCount();
    }
    this->pLeft = pLeft;
    pLeft->increaseReferenceCount();
  }

  virtual void setRight(BinaryTree *const pRight) {
    if (this->getRight() != nullptr) {
      this->getRight()->decreaseReferenceCount();
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

  virtual BinaryTree *createLeft(T value);
  virtual BinaryTree *createRight(T value);

  void print() const;
  int getWidth(int elementWidth) const;
  int getDepth() const;

  void fillInBoard(const BinaryTree *node, int boardWidth, std::string *board, int baseDepth, int baseWidth) const;
  static std::string toString(T value);
};

#endif //LEETCODE_BINARYTREE_H
