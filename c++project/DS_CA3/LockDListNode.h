#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

template<typename T>
class LockDListNode : public DListNode<T> {
public:
    bool isLocked;  // �ΨӪ�ܸ`�I�O�_�Q��w

    // �غc�l�G�I�s�����O���غc�l�ê�l�� isLocked
    LockDListNode(int item, DListNode<T>* prev, DListNode<T>* next) 
        : DListNode<T>(item, prev, next), isLocked(false) {}

    // ��w�`�I����k
    void lock() {
        isLocked = true;
    }
};  

#endif
