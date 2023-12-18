#ifndef ROOTARRAY_HPP
#define ROOTARRAY_HPP

#include "Avl.hpp"
#include "AvlNode.hpp"
#include "Stack.hpp"


class RootArray{
private:
  AvlNode** roots;
  int capacity;
  int size;
  void resize(int);
  void printPostOrder(AvlNode*); 

public:
  RootArray(int);
  void addRoot(AvlNode*);
  AvlNode* getRoot(int);
  int getSize();
  void printAllPostOrder();
  ~RootArray();
};

#endif