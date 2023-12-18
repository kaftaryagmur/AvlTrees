
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
    for (int i = 0; i < size; i++)
    {
        copy[i]= new Stack(*(stacks[i]));
        cout<<"eleman kopyalandi"<<endl;

    }
    return copy;
}
int StackArray::findMinIndex(Stack** array,int size){
    int minTop = -1;
    for(int i = 0; i< size; i++){
        if(!array[i]->isEmpty()){
            if (minTop == -1 || array[i]->top()< array[minTop]->top()){
                minTop = i;
            }
            
        }
    }
    cout <<endl;;
    cout<<"eleman sayisi: "<<size<<endl;
    cout<<"min eleman: "<<array[minTop]->getTopOfStack()<<endl;
    cout<< "min eleman index: "<<minTop<<endl;
    return minTop;
}
int StackArray::findMaxIndex(Stack** array,int size){
    int maxTop = -1;
    for (int i = 0; i < size; i++) {
        if (!array[i]->isEmpty()) {
            if (maxTop == -1 || array[i]->top() > array[maxTop]->top()) {
                maxTop = i;
            }
        }
    }
    cout <<endl;;
    cout << "eleman sayisi: " << size << endl;
    cout << "max eleman: " << array[maxTop]->getTopOfStack()<< endl;
    cout<< "max eleman index: "<<maxTop<<endl;
    return maxTop;
}


void StackArray::removeMinTop(int minIndex,Stack** array){
    if (minIndex >= 0 && minIndex < size && !array[minIndex]->isEmpty()){
        cout<<"en kucuk silindi:"<<array[minIndex]->getTopOfStack()<<endl;
        
        cout<<"pop calismadi"<<endl;
        
        if (stacks[minIndex]->isEmpty()) { //STACKARRAYIN ILGILI INDEKSINDEKI STACK BOSSA SILINECEK
            delete stacks[minIndex];
            Stack** newArray = new Stack*[size-1];
            for (int i = 0, j = 0; i < size; i++) {
                if (i != minIndex) {
                    newArray[j++] = array[i];
                }
            }
            delete [] array;
            array = newArray;
            size--;
        }
        
    }
}
void StackArray::removeMaxTop(int maxIndex,Stack** array){
    if (maxIndex >= 0 && maxIndex < size && !array[maxIndex]->isEmpty()){
        cout<<"en buyuk silindi:"<<array[maxIndex]->getTopOfStack()<<endl;
        stacks[maxIndex]->pop();
        /*if (stacks[maxIndex]->isEmpty()) { //STACKARRAYIN ILGILI INDEKSINDEKI STACK BOSSA SILINECEK
            delete stacks[maxIndex];
            shiftLeft(maxIndex);
            size--;
        }*/
    }
}