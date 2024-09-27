#include <iostream>
using namespace std;

#include "LockDList.h"
#include "DList.h"

template class DListNode<int>;
template class DListNode<string>;

template<typename T>
class LockDListNode;

// 覆寫 newNode() 方法，確保創建的是 LockDListNode
template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev,DListNode<T>* next){
    return new LockDListNode<T>(item, prev, next);
}

// 鎖定節點的方法
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
    // 將 DListNode* 類型轉換為 LockDListNode*
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode != nullptr) {
        lockNode->lock();
    }
}

// 覆寫 remove() 方法，防止鎖定節點被移除
template<typename T>
void LockDList<T>::remove(DListNode<T>* node){
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode == nullptr || !lockNode->isLocked) {
        DList<T>::remove(node);  // 只有未鎖定節點才能被移除
    }
}