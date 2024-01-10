/** 
* @file AvlNode.hpp
* @description Bu dosyada, avl ağaçlarını oluşturan düğümleri oluşturangerekli fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <iostream>

class AvlNode{
public:
    int data;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode(const int data, AvlNode* leftchild=NULL, AvlNode* rightchild=NULL);
};
#endif
