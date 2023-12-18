#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include "Stack.hpp"
#include "AvlNode.hpp"

class StackArray{
private:
    Stack** stacks;
    int capacity;
    int size;
    void resize(int);  
public:
    StackArray(int);
    void addStack(Stack *stack);
    bool isEmpty(int)const;
    const int& top(int)const;
    int getSize();
    Stack* getStack(int) const;

    Stack** copyStackArray() const;
    int findMinIndex(Stack**,int);
    int findMaxIndex(Stack**,int);
    void removeMinTop(int,Stack**);
    void removeMaxTop(int,Stack**);
    ~StackArray();
   

};

#endif