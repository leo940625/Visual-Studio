/**
 * @author HSIEH WU CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 *
 * LockDListNode.h
 * version 1.0
 */
#include <iostream>
#include "LockDListNode.h"
#include "DListNode.h"
using namespace std;

template class LockDListNode<int>;
template class LockDListNode<string>;
template class LockDListNode<float>;
template class LockDListNode<double>;

template<typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* prev, DListNode<T>* next) 
            : DListNode<T>(i, prev, next), Lock(false){}