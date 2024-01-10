/** 
* @file StackArray.cpp
* @description Bu dosyada, avl ağaçlarının yapraklarını tutan stack nesnelerini saklamak için kullanılan diziyi oluşturmak ve işlemleri yapmak için gerekli fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "StackArray.hpp"
using namespace std;

void StackArray::resize(int newCapacity){
    Stack** newStacks = new Stack*[newCapacity];
    for (int i = 0; i < size; i++) {
        newStacks[i] = stacks[i];
    }

    delete[] stacks;
    stacks = newStacks;
    capacity = newCapacity;
}
StackArray::StackArray(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->stacks = new Stack*[capacity];
}
void StackArray::addStack(Stack* stack){
    if (size == capacity) {
        resize(capacity * 2);
    }
    stacks[size++] = stack;
}
bool StackArray::isEmpty(int stackIndex)const{
    if (stackIndex >= 0 && stackIndex < size) {
        return stacks[stackIndex]->isEmpty();
    } else {
        throw "Index out of range";
    }
}
const int& StackArray::top(int stackIndex)const{
    if (stackIndex >= 0 && stackIndex < size) {
        return stacks[stackIndex]->top();
    } else {
        throw "Index out of range";
    }
}

int StackArray::getSize(){
    return size;
}

Stack* StackArray::getStack(int index) const {
    if (index >= 0 && index < size) {
        return stacks[index];
    } else {
        throw "Index out of range";
        return NULL;
    }
}
StackArray::~StackArray(){
    for (int i = 0; i < size; i++) {
        delete stacks[i];
    }
    delete[] stacks;
}
Stack** StackArray::copyStackArray() const{
    Stack** copy = new Stack*[size];
    for (int i = 0; i < size; i++){
        copy[i]= new Stack(*(stacks[i]));
    }
    return copy;
}
int StackArray::findMinIndex(Stack** stackArray, int size) {
    int minTop = -1;
    for (int i = 0; i < size; i++) { 
        if (minTop == -1 || stackArray[i]->top() < stackArray[minTop]->top()) {
            minTop = i;
        }
    }
   return minTop;
   
}

int StackArray::findMaxIndex(Stack** stackArray, int size) {
    int maxTop = -1;
    for (int i = 0; i < size; i++) {
        if (maxTop == -1 || stackArray[i]->top() > stackArray[maxTop]->top()) {
            maxTop = i;
        }
    }
     return maxTop;
}



void StackArray::deleteStack(int index,Stack **& stackArray){
    if (index >= 0 && index<size ) {
        delete stackArray[index];
        Stack** newStackArray = new Stack*[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i == index) continue;
            newStackArray[j] = stackArray[i];
            j++;
        }
        delete [] stackArray;
        stackArray = newStackArray;
        size--;
    }
    else throw "Index out of range";

}

void StackArray::removeMinTop(int minIndex, Stack** stackArray,int size) {
    if (minIndex >= 0 && minIndex < size && !stackArray[minIndex]->isEmpty()) {
        stackArray[minIndex]->pop();
        
    } 
}

void StackArray::removeMaxTop(int maxIndex, Stack** stackArray,int size){
    if (maxIndex >= 0 && maxIndex < size && !stackArray[maxIndex]->isEmpty()) {
        stackArray[maxIndex]->pop();
    }
}
Stack** StackArray::getStacks()const{
    return stacks;
}













