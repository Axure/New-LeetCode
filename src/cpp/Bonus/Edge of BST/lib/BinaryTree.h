//
// Created by 郑虎 on 2015-11-21.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <functional>
#include <iostream>

template<typename T>
class BinaryTree {

 private:
  BinaryTree *pLeft;
  BinaryTree *pRight;
  T _value;
  int _referenceCount;

  void setReferenceCount(int value) {
    std::cout << "[BinaryTree]: The reference count of " << this << " is set to " << value << ", previously " << _referenceCount << std::endl;
    this->_referenceCount = value;
  }

 public:
  virtual ~BinaryTree();
  BinaryTree();
  BinaryTree(T value);

  BinaryTree *getLeft() const {
    return pLeft;
  }

  BinaryTree *getRight() const {
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

  void setLeft(BinaryTree *pLeft) {
    if (this->pLeft != nullptr) {
      this->pLeft->decreaseReferenceCount();
    }
    this->pLeft = pLeft;
    pLeft->increaseReferenceCount();
  }

  void setRight(BinaryTree *pRight) {
    if (this->pRight != nullptr) {
      this->pRight->decreaseReferenceCount();
    }
    this->pRight = pRight;
    pRight->increaseReferenceCount();
  }

  void setValue(T _value) {
    this->_value = _value;
  }

  void preOrderTraverse(std::function<void(T)> &lambda);
  void inOrderTraverse(std::function<void(T)> &lambda);
  void postOrderTraverse(std::function<void(T)> &lambda);
};

#endif //LEETCODE_BINARYTREE_H
