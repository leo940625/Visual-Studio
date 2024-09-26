#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include"DListNode.h"
#include "LockDList.h"

template <class T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode<T> {
    public:
        bool isLocked;  // 用來表示節點是否被鎖定
        // 建構子：呼叫父類別的建構子並初始化 isLocked
        LockDListNode(const T& item, LockDListNode<T>* prev,
            LockDListNode<T>* next);
        // 鎖定節點的方法
        void lock();
};  

#endif
