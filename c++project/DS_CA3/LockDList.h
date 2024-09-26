#ifndef LOCKDLIST_H
#define LOCKDLIST_H
template<typename T>
#include<DListNode.h>
#include<DList.h>


class LockDList : public DList<T> {
public:
    // 覆寫 newNode() 方法，確保創建的是 LockDListNode
    DListNode<T> * newNode(int item, DListNode* prev, DListNode<T> * next) override {
        return new LockDListNode(item, prev, next);
    }

    // 鎖定節點的方法
    void lockNode(DListNode<T> * node) {
        // 將 DListNode* 類型轉換為 LockDListNode*
        LockDListNode<T> * lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode != nullptr) {
            lockNode->lock();
        }
    }

    // 覆寫 remove() 方法，防止鎖定節點被移除
    void remove(DListNode<T> * node) override {
        LockDListNode<T> * lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode == nullptr || !lockNode->isLocked) {
            DList::remove(node);  // 只有未鎖定節點才能被移除
        }
    }
};

#endif