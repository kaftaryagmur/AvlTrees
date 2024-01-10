/** 
* @file StackArray.hpp
* @description Bu dosyada, avl ağaçlarının yapraklarını tutan stack nesnelerini saklamak için kullanılan diziyi oluşturmak ve işlemleri yapmak için gerekli fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include "Stack.hpp"
#include "AvlNode.hpp"
#include "RootArray.hpp"

class StackArray{
private:
    Stack** stacks;
    int capacity;
    int size;
    void resize(int);      
public:
    StackArray(int);
    void addStack(Stack *stack);
    void deleteStack(int index,Stack **&);
    bool isEmpty(int)const;
    const int& top(int)const;
    int getSize();
    Stack** getStacks()const;
    Stack* getStack(int) const;
    Stack** copyStackArray() const;
    int findMinIndex(Stack**,int);
    int findMaxIndex(Stack**,int);
    void removeMinTop(int minIndex,Stack** StackArray,int);
    void removeMaxTop(int minIndex,Stack** StackArray,int);
    ~StackArray();
   

};

#endif