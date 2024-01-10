/** 
* @file Avl.cpp
* @description Bu dosyada, avl ağaçlarını oluşturmak ve işlemleri yapmak için gerekli fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/

#include "Avl.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>



using namespace std;
bool Avl::deleteNode(AvlNode *&subNode){
    AvlNode *delNode = subNode;
    if(subNode->right == NULL) subNode =subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else{
        delNode = subNode->left;
        AvlNode* parent = subNode;
        while(delNode->right!=NULL){
            parent = delNode;
            delNode = delNode->right;
        }
        subNode->data= delNode->data;
        if(parent == subNode) subNode->left = delNode->left;
        else parent->right = delNode->left;
    }
    delete delNode;
    return true;
}
bool Avl::search(AvlNode*subNode, const int& data){
    if(subNode == NULL) return false;
	if(subNode->data == data) return true;
	if(data < subNode->data) return search(subNode->left,data);
	else return search(subNode->right,data);
}
AvlNode* Avl::searchAndAdd(AvlNode *subNode, const int& item){ 
    if (subNode == NULL) subNode = new AvlNode(item); 
    else if(item < subNode->data){
        subNode->left = searchAndAdd(subNode->left, item);
        if(height(subNode->left) == height(subNode->right)+2){
            if(item < subNode->left->data){
                subNode = changeWithLeftChild(subNode);
            }
            else{
                subNode->left = changeWithRightChild(subNode->left);
                subNode = changeWithLeftChild(subNode);
            }
        }
    }
    else if(item > subNode->data){
        subNode->right = searchAndAdd(subNode->right, item);
        if(height(subNode->right) == height(subNode->left)+2){
            if(item > subNode->right->data){
                subNode= changeWithRightChild(subNode);
            }
            else{
                subNode->right = changeWithLeftChild(subNode->right);
                subNode = changeWithRightChild(subNode);
            }
        }
    }
    else; //eklenecek sayi zaten agacta vardir, ekleme yapilmaz.
			
	subNode->height = height(subNode);
	return subNode;
}
AvlNode *Avl::changeWithLeftChild(AvlNode *subNode){
    AvlNode *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    subNode->height = height(subNode);
    tmp->height = 1+max(height(tmp->left),subNode->height);

    return tmp;
}

AvlNode *Avl::changeWithRightChild(AvlNode *subNode){
    AvlNode *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    subNode->height = height(subNode);
    tmp->height = 1+max(height(tmp->right),subNode->height);
}
int Avl::height(AvlNode* subNode){
    if(subNode== NULL) return -1;
    return 1+max(height(subNode->left),height(subNode->right));
}

Avl::Avl(){
    root = NULL;
}
bool Avl::isEmpty()const{
    return root == NULL;
}
bool Avl::search(const int& data){
    return search(root,data);
}
void Avl::Add(const int& item){
    root = searchAndAdd(root, item);
}
void Avl::Clear(){
    while(!isEmpty()) deleteNode(root);
}
AvlNode* Avl::sendRoot(){
    return root;
}

int Avl::postOrder(AvlNode* node) {
    if (node == NULL) {
        return 0;
    }

    int leftSum = postOrder(node->left);
    int rightSum = postOrder(node->right);

    int totalSum = leftSum + rightSum + node->data;

    return totalSum;
}

int Avl::postOrder() {
    int totalSum = postOrder(root);
    cout << endl;
    return totalSum;
}


void Avl::readFromFile(const std::string& filename, RootArray& rootArray, StackArray& stackArray) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File could not be opened.");
    }
    string line;
    while (getline(file, line)) {
        AvlNode* root = NULL; 
        istringstream iss(line);
        int value;
        while (iss >> value) {
            root = searchAndAdd(root, value);
        }
        rootArray.addRoot(root); 
        Stack* stack = new Stack;  
        stack->addLeavesToStack(root);
        stackArray.addStack(stack);  

        printAsciiLetter(stack,root);       
    }   
    file.close();
}

void Avl::printAsciiLetter(Stack* stack,AvlNode* root){
    if(root==NULL){
        cout<<"kok bulunamadi"<<endl;
        return;
    } 
    int allSum = postOrder(root);
    int leavesSum= stack->sumOfStack(stack->getTopOfStack());
    int AVLToplamDugumDeger=allSum-leavesSum;
    int ascii = AVLToplamDugumDeger%(90-65 + 1) + 65;
    cout<<char(ascii);
}

void Avl::clearTree(AvlNode *&subNode) {
    if (subNode != NULL) {
        clearTree(subNode->left);
        clearTree(subNode->right);
        delete subNode;
        subNode = NULL;
    }
}
Avl::~Avl(){
    Clear();
}



