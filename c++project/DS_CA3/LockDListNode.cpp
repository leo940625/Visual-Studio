#include <iostream>
using namespace std;
#include "LockDListNode.h"
#include "DListNode.h"

template class LockDListNode<int>;
template class LockDListNode<string>;
template class LockDListNode<float>;
template class LockDListNode<double>;

template<typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* prev, DListNode<T>* next) 
            : DListNode<T>(i, prev, next), Lock(false) {}