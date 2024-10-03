/**
 * @author HSIEH WU CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 *
 * DListNode.h
 * version 1.0
 */

/**
 *  A DListNode is a node in a DList (doubly-linked list).
 */

#ifndef DLISTNODE_H
#define DLISTNODE_H

using namespace std;
#include<string>

template<typename T>
class DList;

template<typename T>
class DListNode {
	/**
	 *  item references the item stored in the current node.
	 *  prev references the previous node in the DList.
	 *  next references the next node in the DList.
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	DListNode<T>* prev;
	DListNode<T>* next;
	friend class DList<T>;

public:
	T item;

	/**
	 *  DListNode() constructor.
	 *  @param i the item to store in the node.
	 *  @param p the node previous to this node.
	 *  @param n the node following this node.
	 */
	DListNode(const T& i, DListNode<T>* p, DListNode<T>* n);
    virtual ~DListNode() = default;
};


#endif

