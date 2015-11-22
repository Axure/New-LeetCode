//
// Created by 郑虎 on 2015-11-21.
//

#ifndef LEETCODE_BST_H
#define LEETCODE_BST_H

#include "BinaryTree.h"

template <typename T>
class Bst: BinaryTree<T> {

 public:
  Bst();
  virtual ~Bst();
  const Bst &insert(T value);
};


#endif //LEETCODE_BST_H
