/** 
* @file StackNode.cpp
* @description Bu dosyada, avl ağaçlarının yapraklarının tutulduğu stacki tek yönlü bağlı liste olarak oluşturmak ve işlemleri yapmak için gerekli fonksiyonlar bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
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
