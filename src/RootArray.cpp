/** 
* @file RootArray.cpp
* @description Bu dosyada, avl ağaçlarının kökkerini tutan diziyi oluşturmak ve gerekli işlemleri yapmak için fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "RootArray.hpp"
#include "StackArray.hpp"
#include "Stack.hpp"

#include <fstream>
#include <sstream>

using namespace std;

void RootArray::resize(int newCapacity){
    AvlNode** newRoots = new AvlNode*[newCapacity];
    for (int i = 0; i < size; i++) {
        newRoots[i] = roots[i];
    }

    delete[] roots;
    roots = newRoots;
    capacity = newCapacity;
}
RootArray::RootArray(int capacity){
    this->capacity= capacity;
    size =0;
    roots = new AvlNode*[capacity];

}
void RootArray::addRoot(AvlNode* root){
    if (size == capacity) {
        resize(capacity * 2);
    }

    roots[size++] = root;
}
AvlNode* RootArray::getRoot(int index){
    if (index >= 0 && index < size) {
        return roots[index];
    } else {
   
        return NULL;
    }
}
int RootArray::getSize(){
    return size;
}
RootArray::~RootArray() {
    delete[] roots;
}
void RootArray::printPostOrder(AvlNode* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }
}

AvlNode** RootArray::copyRootArray() const{
    AvlNode** copy = new AvlNode*[size];
    for (int i = 0; i < size; i++){
        copy[i]= new AvlNode(*(roots[i]));
    }
    return copy;
}
void RootArray::deleteRoot(int index,AvlNode**& rootArray) {
    if (index >= 0 && index<size) {
        delete rootArray[index];
        AvlNode** newRootArray = new AvlNode*[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i == index) continue;
            newRootArray[j] = rootArray[i];
            j++;
        }
        delete [] rootArray;
        rootArray = newRootArray;
        size--;
        
    }
    else throw "Index out of range";
}
AvlNode** RootArray::getRoots()const{
    return roots;
}








