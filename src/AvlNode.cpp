#include "AvlNode.hpp"

AvlNode::AvlNode(const int data, AvlNode* leftchild, AvlNode* rightchild){
    this->data= data;
    this->left=leftchild;
    this->right= rightchild;
    height=0;
}
