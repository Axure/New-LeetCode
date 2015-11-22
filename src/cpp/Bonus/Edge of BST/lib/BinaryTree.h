//
// Created by 郑虎 on 2015-11-21.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <functional>

template<typename T>
class BinaryTree {

 private:
  BinaryTree *pLeft;
  BinaryTree *pRight;
  T _value;
  int _referenceCount;

  void setReferenceCount(int value) {
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
    this->_referenceCount++;
  }

  void decreaseReferenceCount() {
    this->_referenceCount--;
  }

  void setLeft(BinaryTree *pLeft) {
    this->pLeft = pLeft;
  }

  void setRight(BinaryTree *pRight) {
    this->pRight = pRight;
  }

  void setValue(T _value) {
    this->_value = _value;
  }

  void preOrderTraverse(std::function<void(T)> &lambda);
};

#endif //LEETCODE_BINARYTREE_H
