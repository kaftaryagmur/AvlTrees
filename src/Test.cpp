#include "Avl.hpp"
#include "RootArray.hpp"
#include "Stack.hpp"
#include "StackArray.hpp"

#include <iostream>
using namespace std;
int main() {
    
    StackArray stackArray(7);
    RootArray rootArray(7);
    Avl tree;
    Stack stack;

    tree.readFromFile("Veri.txt", rootArray, stackArray);
    cout<<endl;
    cout << "root array veri sayisi: " << rootArray.getSize() <<endl;
    cout << "stack array veri sayisi: " << stackArray.getSize() <<endl;

    Stack** tmpStacks = stackArray.copyStackArray();
    int minTop= stackArray.findMinIndex(tmpStacks, stackArray.getSize());
    //EN BÜYÜK EN KÜCÜK CIKARMA YAZCAM
    cout<<endl;
    stackArray.removeMinTop(minTop,tmpStacks); /*SORUN VAR*/

    

    return 0;
}
