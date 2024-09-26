#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include"DListNode.h"
#include "LockDList.h"

template <class T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode<T> {
    public:
        bool isLocked;  // �ΨӪ�ܸ`�I�O�_�Q��w
        // �غc�l�G�I�s�����O���غc�l�ê�l�� isLocked
        LockDListNode(const T& item, LockDListNode<T>* prev,
            LockDListNode<T>* next);
        // ��w�`�I����k
        void lock();
};  

#endif
