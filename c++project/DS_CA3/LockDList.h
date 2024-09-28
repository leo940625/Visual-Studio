#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "LockDListNode.h"

template<typename T>
class LockDListNode;

template<typename T>
class LockDList : public DList<T> {
public:
    // �мg newNode() ��k�A�T�O�Ыت��O LockDListNode
    DListNode<T>* newNode(const T& item, DListNode<T>* prev,DListNode<T>* next) override;
    // ��w�`�I����k
    void lockNode(DListNode<T>* node);
    // �мg remove() ��k�A������w�`�I�Q����
    void remove(DListNode<T>* node) override;
};

#endif