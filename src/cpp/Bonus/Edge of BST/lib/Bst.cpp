//
// Created by 郑虎 on 2015-11-21.
//

#include "Bst.h"

template<typename T>
Bst<T>::Bst() {

}

template<typename T>
Bst<T>::~Bst() {

}

template<typename T>
Bst<T> *const Bst<T>::insert(T value) {
  if (value < this->getValue()) {
    auto pLeft = this->getLeft();
    if (pLeft != nullptr) {
      this->getLeft()->insert(value);
    } else {
      this->createLeft(value);
    }

  } else {
    auto pRight = this->getRight();
    if (pRight != nullptr) {
      this->getRight()->insert(value);
    } else {
      this->createRight(value);
    }
  }

  return this;
}

template
class Bst<int>;