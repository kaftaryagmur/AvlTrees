/** 
* @file Test.cpp
* @description Bu dosyada, programı başlatan main fonksiyonu bulunmaktadır.
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "Avl.hpp"
#include "AvlNode.hpp"
#include "RootArray.hpp"
#include "Stack.hpp"
#include "StackArray.hpp"

int PostorderDolas(AvlNode* root, int& total, int& noChildTotal) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = PostorderDolas(root->left, total, noChildTotal);
    int rightSum = PostorderDolas(root->right, total, noChildTotal);

    int currentNodeValue = root->data;
    total += currentNodeValue;

    if (root->left == nullptr && root->right == nullptr) {
        noChildTotal += currentNodeValue;
    }

    return leftSum + rightSum + currentNodeValue;
}

#include <iostream>
using namespace std;

int main() {   
    StackArray stackArray(7);
    RootArray rootArray(7);
    Avl tree;
    Stack stack;
    
    tree.readFromFile("Veri.txt", rootArray, stackArray);
    cout << endl;
    
    int total = 0;
    int noChildTotal = 0;

    Stack** tmpStacks = stackArray.copyStackArray();
    AvlNode** tmpRoots = rootArray.copyRootArray();
    int size = stackArray.getSize();

    while (size > 1) {
        int minTopIndex = stackArray.findMinIndex(tmpStacks, size);
        stackArray.removeMinTop(minTopIndex, tmpStacks, size);
        if (tmpStacks[minTopIndex]->isEmpty()) { //STACK SİLİNME
            stackArray.deleteStack(minTopIndex,tmpStacks);
            rootArray.deleteRoot(minTopIndex, tmpRoots);
            size--;
            system("CLS");
            for (int i = 0; i < size; i++) {
                int total = 0;
                int noChildTotal = 0;
                PostorderDolas(tmpRoots[i], total, noChildTotal);
                int ascii = (total % (90 - 65 + 1)) + 65;
                cout << char(ascii);
            } 

        } 
        else {
            int maxTopIndex = stackArray.findMaxIndex(tmpStacks, size);
            stackArray.removeMaxTop(maxTopIndex, tmpStacks, size);
            if (tmpStacks[maxTopIndex]->isEmpty()) { //STACK SİLİNME
                stackArray.deleteStack(maxTopIndex,tmpStacks);
                rootArray.deleteRoot(maxTopIndex, tmpRoots);
                size--;
                system("CLS");
                for (int i = 0; i < size; i++) {
                int total = 0;
                int noChildTotal = 0;
                PostorderDolas(tmpRoots[i], total, noChildTotal);
                int ascii = (total % (90 - 65 + 1)) + 65;
                cout << char(ascii);
                }
            }
        }
    }   

    cout << " :son eleman." << endl;
    delete [] tmpRoots;
    delete [] tmpStacks;

}

