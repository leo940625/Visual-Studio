/**
 * @author HSIEH WU CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 *
 * LockDList.h
 * version 1.0
 */

#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "LockDListNode.h"

template<typename T>
class LockDListNode;

template<typename T>
class LockDList : public DList<T> {
public:
    // override newNode() 
    DListNode<T>* newNode(const T& item, DListNode<T>* prev,DListNode<T>* next) override;

    void lockNode(DListNode<T>* node);
   
    void remove(DListNode<T>* node) override;
};

#endif