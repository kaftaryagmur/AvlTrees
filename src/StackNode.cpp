#include "StackNode.hpp"

StackNode::StackNode(const int& data,StackNode *next){
    this->data = data;
    this->next = next;
}
int StackNode::getData() const {
        return data;
}
StackNode* StackNode::getNext() const {
    return next;
}