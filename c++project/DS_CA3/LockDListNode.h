#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

template<typename T>
class LockDListNode : public DListNode<T> {
public:
    bool isLocked;  // 用來表示節點是否被鎖定

    // 建構子：呼叫父類別的建構子並初始化 isLocked
    LockDListNode(int item, DListNode<T>* prev, DListNode<T>* next) : DListNode<T>(item, prev, next), isLocked(false) {}

    // 鎖定節點的方法
    void lock() {
        isLocked = true;
    }
};  

#endif
