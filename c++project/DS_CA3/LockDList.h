#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "LockDListNode.h"

template<typename T>
class LockDListNode;

template<typename T>
class LockDList : public DList<T> {
public:
    // 覆寫 newNode() 方法，確保創建的是 LockDListNode
    DListNode<T>* newNode(const T& item, DListNode<T>* prev,DListNode<T>* next) override;
    // 鎖定節點的方法
    void lockNode(DListNode<T>* node);
    // 覆寫 remove() 方法，防止鎖定節點被移除
    void remove(DListNode<T>* node) override;
};

#endif