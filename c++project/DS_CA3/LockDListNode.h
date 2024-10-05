/**
 * @author HSIEH WU CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 *
 * LockDListNode.h
 * version 1.0
 */

#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include"DListNode.h"
#include<string>

template <typename T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode<T> {
    public:
        bool Lock; 
        LockDListNode(const T& i, DListNode<T>* prev, DListNode<T>* next);
};
#endif
