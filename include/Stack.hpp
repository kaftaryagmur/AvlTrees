#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"
#include "AvlNode.hpp"  

class Stack{
private:
    StackNode *topOfStack;
    void clear();
public:
    Stack();
    bool isEmpty()const;
    void addLeavesToStack(AvlNode* root);
    void pushLeaves(const int&);
    void pop();
    const int& top()const;
    const int& getTopOfStack() const;
    int sumOfStack(StackNode *topOfStack);
    ~Stack();
    
};
#endif