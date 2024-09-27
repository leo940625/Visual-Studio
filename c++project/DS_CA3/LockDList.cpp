#include <iostream>
using namespace std;

#include "LockDList.h"
#include "DList.h"

template class DListNode<int>;
template class DListNode<string>;

template<typename T>
class LockDListNode;

// �мg newNode() ��k�A�T�O�Ыت��O LockDListNode
template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev,DListNode<T>* next){
    return new LockDListNode<T>(item, prev, next);
}

// ��w�`�I����k
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
    // �N DListNode* �����ഫ�� LockDListNode*
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode != nullptr) {
        lockNode->lock();
    }
}

// �мg remove() ��k�A������w�`�I�Q����
template<typename T>
void LockDList<T>::remove(DListNode<T>* node){
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode == nullptr || !lockNode->isLocked) {
        DList<T>::remove(node);  // �u������w�`�I�~��Q����
    }
}