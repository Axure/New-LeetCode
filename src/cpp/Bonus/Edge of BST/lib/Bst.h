//
// Created by 郑虎 on 2015-11-21.
//

#ifndef LEETCODE_BST_H
#define LEETCODE_BST_H

#include "BinaryTree.h"

template<typename T>
class Bst: public BinaryTree<T> {

 public:
  Bst();
  virtual ~Bst();
  Bst<T> *const insert(T value);

  Bst(T value) : BinaryTree<T>(value) {
  }

  Bst *getLeft() const override {
    return (Bst *) this->pLeft;
  }

  Bst *getRight() const override {
    return (Bst *) this->pRight;
  }

  void setLeft(Bst *const pLeft) {
    if (this->getLeft() != nullptr) {
      this->getLeft()->decreaseReferenceCount();
    }
    this->pLeft = pLeft;
    pLeft->increaseReferenceCount();
  }

  void setRight(Bst *const pRight) {
    if (this->getRight() != nullptr) {
      this->getRight()->decreaseReferenceCount();
    }
    this->pRight = pRight;
    pRight->increaseReferenceCount();
  }

  Bst *createLeft(T value) override{
    if (this->getLeft() == nullptr) {
      this->setLeft(new Bst(value));
    }
    return this->getLeft();
  };
  
  Bst *createRight(T value)override {
    if (this->getRight() == nullptr) {
      this->setRight(new Bst(value));
    }
    return this->getRight();
  };

};

#endif //LEETCODE_BST_H
