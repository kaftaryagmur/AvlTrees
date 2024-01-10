/** 
* @file AvlNode.cpp
* @description Bu dosyada, avl ağaçlarını oluşturan düğümleri oluşturangerekli fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "AvlNode.hpp"

AvlNode::AvlNode(const int data, AvlNode* leftchild, AvlNode* rightchild){
    this->data= data;
    this->left=leftchild;
    this->right= rightchild;
    height=0;
}
