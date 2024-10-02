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
        LockDListNode(const T& i, DListNode<T>* prev, DListNode<T>* next) 
            : DListNode<T>(i, prev, next), Lock(false) {}
};

#endif
