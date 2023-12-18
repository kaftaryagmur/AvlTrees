#ifndef STACKNODE_HPP
#define STACKNODE_HPP
#include <iostream>

class StackNode{
public:
    int data;
    StackNode* next;
    StackNode(const int&,StackNode *next=NULL);
    int getData() const;
    StackNode* getNext()const;
};


#endif