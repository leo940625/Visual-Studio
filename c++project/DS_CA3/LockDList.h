#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "LockDListNode.h"

template<typename T>
class LockDListNode;

template<typename T>
class LockDList : public DList<T> {
public:
    // �мg newNode() ��k�A�T�O�Ыت��O LockDListNode
    DListNode<T>* newNode(const T& item, DListNode<T>* prev,DListNode<T>* next) override {
        return new LockDListNode<T>(item, prev, next);
    }

    // ��w�`�I����k
    void lockNode(DListNode<T>* node) {
        // �N DListNode* �����ഫ�� LockDListNode*
        LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode != nullptr) {
            lockNode->lock();
        }
    }

    // �мg remove() ��k�A������w�`�I�Q����
    void remove(DListNode<T>* node) override {
        LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
        if (lockNode == nullptr || !lockNode->isLocked) {
            DList<T>::remove(node);  // �u������w�`�I�~��Q����
        }
    }
};

#endif