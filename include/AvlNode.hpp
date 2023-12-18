#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <iostream>

class AvlNode{
public:
    int data;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode(const int data, AvlNode* leftchild=NULL, AvlNode* rightchild=NULL);
};
#endif
