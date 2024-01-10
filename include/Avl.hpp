/** 
* @file Avl.hpp
* @description Bu dosyada, avl ağaçlarını oluşturmak ve işlemleri yapmak için gerekli fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP

#include "AvlNode.hpp"
#include "StackArray.hpp"
#include "RootArray.hpp"

class RootArray;
class StackArray;
class Avl{
private:
    AvlNode *root;
    bool deleteNode(AvlNode *&);
    bool search(AvlNode*, const int&);
    AvlNode *changeWithLeftChild(AvlNode*);
    AvlNode *changeWithRightChild(AvlNode*);
    int height(AvlNode*);


public:
    Avl();
    bool isEmpty()const;
    bool search(const int&);
    void Add(const int&);
    void Clear();
    AvlNode* sendRoot();
    int postOrder(AvlNode*);
    int postOrder();
    void readFromFile(const std::string&, RootArray&, StackArray&);
    void printAsciiLetter(Stack*,AvlNode*);
    void clearTree(AvlNode *&subNode);
    AvlNode *searchAndAdd(AvlNode*, const int&); 
    ~Avl();

};
#endif
