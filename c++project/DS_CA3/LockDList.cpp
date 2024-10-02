#include <iostream>
using namespace std;

#include "LockDList.h"
#include "DList.h"

template class LockDList<int>;
template class LockDList<string>;
template class LockDList<float>;
template class LockDList<double>;

template<typename T>
class LockDListNode;


template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev,DListNode<T>* next){
    return new LockDListNode<T>(item, prev, next);
}


template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
    // change DListNode* to LockDListNode*
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode != nullptr) {
        lockNode->Lock = true;
    }
}
//override remove
template<typename T>
void LockDList<T>::remove(DListNode<T>* node){
    LockDListNode<T>* lockNode = dynamic_cast<LockDListNode<T>*>(node);
    if (lockNode != nullptr && !lockNode->Lock) {
        DList<T>::remove(node); //only unlock node can be remove
    }
}