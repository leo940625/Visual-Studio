#ifndef LOCKDLIST_H
#define LOCKDLIST_H
template<typename T>
#include<DListNode.h>
#include<DList.h>


class LockDList : public DList<T> {
public:
    // �мg newNode() ��k�A�T�O�Ыت��O LockDListNode
    DListNode<T> * newNode(int item, DListNode* prev, DListNode<T> * next) override {
        return new LockDListNode(item, prev, next);
    }

    // ��w�`�I����k
    void lockNode(DListNode<T> * node) {
        // �N DListNode* �����ഫ�� LockDListNode*
        LockDListNode<T> * lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode != nullptr) {
            lockNode->lock();
        }
    }

    // �мg remove() ��k�A������w�`�I�Q����
    void remove(DListNode<T> * node) override {
        LockDListNode<T> * lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode == nullptr || !lockNode->isLocked) {
            DList::remove(node);  // �u������w�`�I�~��Q����
        }
    }
};

#endif