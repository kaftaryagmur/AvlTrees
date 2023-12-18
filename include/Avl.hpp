#ifndef AVL_HPP
#define AVL_HPP

#include "AvlNode.hpp"
#include "StackArray.hpp"
#include "RootArray.hpp"

class RootArray;
class Avl{
private:
    AvlNode *root;
    bool deleteNode(AvlNode *&);
    bool search(AvlNode*, const int&);
    AvlNode *searchAndAdd(AvlNode*, const int&); 
    AvlNode *changeWithLeftChild(AvlNode*);
    AvlNode *changeWithRightChild(AvlNode*);
    int height(AvlNode*);
    int postOrder(AvlNode*);
    
public:
    Avl();
    bool isEmpty()const;
    bool search(const int&);
    void Add(const int&);
    void Clear();
    AvlNode* sendRoot();
    ~Avl();

    int postOrder();
    void readFromFile(const std::string& ,RootArray& ,StackArray&);
    void postOrderAllTrees(Avl*[], int);

    void printAsciiLetter(Stack*,AvlNode*);




};
#endif
