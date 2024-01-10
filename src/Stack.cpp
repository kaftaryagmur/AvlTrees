/** 
* @file Stack.cpp
* @description Bu dosyada, avl ağaçlarının yapraklarını tutan yapı ve stack üzerinde işlemler yapmak için gerekli fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"
#include "StackNode.hpp"
using namespace std;
Stack::Stack(){
    topOfStack=NULL;
}
void Stack::clear(){
 
    while (!isEmpty()){
        pop();
    }
}
void Stack::addLeavesToStack(AvlNode* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        pushLeaves(root->data);
    }
    addLeavesToStack(root->left);
    addLeavesToStack(root->right);
}
bool Stack::isEmpty()const{
    return topOfStack == NULL;
}
void Stack::pushLeaves(const int& data){
    StackNode* newNode = new StackNode(data, topOfStack);
    newNode->next = topOfStack;
    topOfStack=newNode;
}
void Stack::pop(){
   if(isEmpty()) throw "Stack is empty";
   StackNode* tmp = topOfStack;
   topOfStack = topOfStack->next;
}
const int& Stack::top()const{
    if(isEmpty()) throw "Stack is Empty";
    return topOfStack->data;
}

StackNode* Stack::getTopOfStack() const{
    return topOfStack;
}
int Stack::sumOfStack(StackNode *topOfStack) {
    if(topOfStack==NULL) cout<<"stack bos"<<endl;
    StackNode *tmp = topOfStack;
    int sum = 0;
    while (tmp != NULL) {
        sum += tmp->data;
        tmp = tmp->next;
    }
    return sum;
}
void Stack::setTopOfStack(StackNode* node){
    if (node == nullptr){
        cout << "Yığın boş, topOfStack ayarlanamaz." << endl;
        return;
    }
    topOfStack = node;
}
Stack::~Stack(){
    clear();
}

void Stack::printStack() {
    StackNode* current = topOfStack;
    cout << "Stack Elemanlari: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Stack* Stack::copyStack() {
    Stack* newStack = new Stack;
    StackNode* temp = topOfStack;
    StackNode* prev = nullptr;

    // Orijinal sırayı koruyarak kopyala
    while (temp != nullptr) {
        StackNode* newNode = new StackNode(temp->data);
        newNode->next = prev;  // Yeni elemanı eklerken bağlantıyı ters çevir
        prev = newNode;
        temp = temp->next;
    }

    // Yeni Stack'in top elemanını güncelle
    newStack->topOfStack = prev;

    return newStack;
}


