/** 
* @file StackNode.hpp
* @description Bu dosyada, avl ağaçlarının yapraklarının tutulduğu stacki tek yönlü bağlı liste olarak oluşturmak ve işlemleri yapmak için gerekli fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef STACKNODE_HPP
#define STACKNODE_HPP
#include <iostream>

class StackNode{
public:
    int data;
    StackNode* next;
    StackNode(const int&,StackNode *next=NULL);
    int getData() const;
    StackNode* getNext()const;
};


#endif