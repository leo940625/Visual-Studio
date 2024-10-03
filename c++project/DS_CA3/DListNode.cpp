/**
 * @author HSIEH WU CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 *
 * DListNode.cpp
 * version 1.0
 */

/*
A DListNode is a node in a DList (doubly-linked list).
*/

#include "DListNode.h"
template class DListNode<int>;
template class DListNode<string>;
template class DListNode<float>;
template class DListNode<double>;


/**
 *  DListNode() constructor.
 *  @param i the item to store in the node.
 *  @param p the node previous to this node.
 *  @param n thAAe node following this node.
 */
//template class DListNode<int>;
template<typename T>
DListNode<T>::DListNode(const T& i, DListNode<T>* p,DListNode<T>* n){
	item = i;
	prev = p;
	next = n;
}

