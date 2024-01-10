/** 
* @file Stack.hpp
* @description Bu dosyada, avl ağaçlarının yapraklarını tutan yapı ve stack üzerinde işlemler yapmak için gerekli fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"
#include "AvlNode.hpp"  

class Stack{
private:
    StackNode *topOfStack;

public:
    Stack();
    bool isEmpty()const;
    void addLeavesToStack(AvlNode* root);
    void pushLeaves(const int&);
    void removeTopElement(Stack* stack);
    void pop();
    const int& top()const;
    StackNode* getTopOfStack() const;
    void setTopOfStack(StackNode*);
    int sumOfStack(StackNode *topOfStack);
    void printStack();
    Stack* copyStack();
    void clear();
    ~Stack();
};
#endif