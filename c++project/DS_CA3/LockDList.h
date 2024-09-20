#ifndef LOCKDLIST_H
#define LOCKDLIST_H

template<typename T>
class LockDList : public DList<T> {
public:
    // 覆寫 newNode() 方法，確保創建的是 LockDListNode
    DListNode* newNode(int item, DListNode* prev, DListNode* next) override {
        return new LockDListNode(item, prev, next);
    }

    // 鎖定節點的方法
    void lockNode(DListNode* node) {
        // 將 DListNode* 類型轉換為 LockDListNode*
        LockDListNode* lockNode = dynamic_cast<LockDListNode*>(node);
        if (lockNode != nullptr) {
            lockNode->lock();
        }
    }

    // 覆寫 remove() 方法，防止鎖定節點被移除
    void remove(DListNode* node) override {
        LockDListNode* lockNode = dynamic_cast<LockDListNode*>(node);
        if (lockNode == nullptr || !lockNode->isLocked) {
            DList::remove(node);  // 只有未鎖定節點才能被移除
        }
    }
};

#endif