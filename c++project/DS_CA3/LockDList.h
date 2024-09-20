#ifndef LOCKDLIST_H
#define LOCKDLIST_H

template<typename T>
class LockDList : public DList<T> {
public:
    // �мg newNode() ��k�A�T�O�Ыت��O LockDListNode
    DListNode* newNode(int item, DListNode* prev, DListNode* next) override {
        return new LockDListNode(item, prev, next);
    }

    // ��w�`�I����k
    void lockNode(DListNode* node) {
        // �N DListNode* �����ഫ�� LockDListNode*
        LockDListNode* lockNode = dynamic_cast<LockDListNode*>(node);
        if (lockNode != nullptr) {
            lockNode->lock();
        }
    }

    // �мg remove() ��k�A������w�`�I�Q����
    void remove(DListNode* node) override {
        LockDListNode* lockNode = dynamic_cast<LockDListNode*>(node);
        if (lockNode == nullptr || !lockNode->isLocked) {
            DList::remove(node);  // �u������w�`�I�~��Q����
        }
    }
};

#endif