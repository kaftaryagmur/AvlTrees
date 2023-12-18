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
void RootArray::printAllPostOrder() {
    for (int i = 0; i < size; ++i) {
        cout << "Tree " << i + 1 << " (Postorder): ";
        printPostOrder(roots[i]);
        cout << endl;
    }
}







