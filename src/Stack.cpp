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
    if (isEmpty()) throw "Stack is Empty";
    cout << "pop: Popping element " << topOfStack->data << endl; // Debug mesajı
    StackNode *tmp = topOfStack;
    topOfStack = topOfStack->next;
    delete tmp;
}
const int& Stack::top()const{
    if(isEmpty()) throw "Stack is Empty";
    return topOfStack->data;
}
const int& Stack::getTopOfStack() const{
    return topOfStack->data;
}
int Stack::sumOfStack(StackNode *topOfStack) {
    StackNode *tmp = topOfStack;
    int sum = 0;
    while (tmp != NULL) {
        sum += tmp->data;
        tmp = tmp->next;
    }
    return sum;
}

Stack::~Stack(){
    clear();
}

