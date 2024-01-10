/** 
* @file RootArray.hpp
* @description Bu dosyada, avl ağaçlarının kökkerini tutan diziyi oluşturmak ve gerekli işlemleri yapmak için fonksiyon tanımları bulunmaktadır.
* @course Dersi aldığınız 2.öğretim A grubu
* @assignment 2. ödev
* @date son güncelleme 24.12.2023
* @author Yağmur Kaftar/yagmur.kaftar@ogr.sakarya.edu.tr
*/
#ifndef ROOTARRAY_HPP
#define ROOTARRAY_HPP

#include "Avl.hpp"
#include "AvlNode.hpp"
#include "Stack.hpp"


class RootArray{
private:
  AvlNode** roots;
  int capacity;
  int size;
  void resize(int);
  void printPostOrder(AvlNode*); 

public:
  RootArray(int);
  void addRoot(AvlNode*);
  AvlNode* getRoot(int);
  int getSize();
  AvlNode** getRoots()const;
  AvlNode** copyRootArray() const;
  void deleteRoot(int index,AvlNode**&);
  ~RootArray();
};

#endif