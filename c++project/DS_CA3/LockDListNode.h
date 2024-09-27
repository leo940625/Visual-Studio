#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include"DListNode.h"
#include"LockDList.h"

template <typename T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode<T> {
    public:
        bool isLocked;  // �ΨӪ�ܸ`�I�O�_�Q��w
        // �غc�l�G�I�s�����O���غc�l�ê�l�� isLocked
        LockDListNode(const T& i, DListNode<T>* prev, DListNode<T>* next) 
            : DListNode<T>(i, prev, next), isLocked(false) {}
        
        // ��w�`�I����k
        void lock() {
            isLocked = true;
        }
};

#endif
