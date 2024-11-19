#include "BinaryTree.h"
#include<iostream>
using namespace std;

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree()
{
    makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int BinaryTree<K, V>::size()
{
    return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty()
{
    return size() == 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V> *entry, const K &key, BinaryTreeNode<K, V> *node)
{
    if (key.compareTo(node->entry->getkey()) <= 0){
        if (node->leftChild == nullptr){
            node->leftChild = new BinaryTreeNode<K, V>(entry, node);
        }
        else{
            insertHelper(entry, key, node->leftChild);
        }
    }
    else{
        if (node->rightChild == nullptr){
            node->rightChild = new BinaryTreeNode<K, V>(entry, node);
        }
        else{
            insertHelper(entry, key, node->rightChild);
        }
    }
}
/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void BinaryTree<K, V>::insert(const K &key, const V &value)
{
    Entry<K, V> *entry = new Entry<K, V>(key, value);
    if (root == nullptr)
    {
        root = new BinaryTreeNode<K, V>(entry);
    }
    else
    {
        insertHelper(entry, key, root);
    }
    tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return nullptr.
 *
 *  Be sure this method returns nullptr if node == nullptr.
 **/
template <typename K, typename V>
BinaryTreeNode<K, V> *BinaryTree<K, V>::findHelper(const K &key, BinaryTreeNode<K, V> *node)
{
    if (node == nullptr){
        return nullptr;
    }
    BinaryTreeNode<K, V> *current = node;
    while (current != nullptr){
        if (current->entry->getkey().compareTo(key) == 0){
            return current;
        }
        else if (current->entry->getkey().compareTo(key) > 0) {
            current = current->leftChild;
        }
        else{
            current = current->rightChild;
        }
    }
    return nullptr;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or nullptr if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
Entry<K, V> *BinaryTree<K, V>::find(const K &key)
{
    BinaryTreeNode<K, V> *node = findHelper(key, root);
    return node != nullptr ? node->entry : nullptr;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void BinaryTree<K, V>::remove(const K &key)
{
    BinaryTreeNode<K, V> *target = findHelper(key, root);
    if (target == nullptr){
        return;
    }
    if (target->leftChild == nullptr && target->rightChild == nullptr) {// No child
        if (target == root) {
            root = nullptr;
        } else {
            connect(target,nullptr);
        }
    }else if (target->leftChild == nullptr || target->rightChild == nullptr){// One child
        BinaryTreeNode<K, V> * child = (target->leftChild != nullptr) ? target->leftChild : target->rightChild;
        if (target == root) {
            root = child;
            root->parent = nullptr;
        } else {
            connect(target,child);
            child->parent = target->parent;
        }
    }else{//two child
        BinaryTreeNode<K, V> *temp = target->rightChild;
        while (temp->leftChild != nullptr){
            temp = temp->leftChild;
        }
        target->entry = new Entry<K, V>(temp->entry->getkey(), temp->entry->getvalue());
        //刪除temp
        connect(temp,temp->rightChild);
        if (temp->rightChild != nullptr){
           temp->rightChild->parent = temp->parent;
        }
        target = temp;
    }
    delete target;
    tsize--;
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void BinaryTree<K, V>::makeEmpty(){
    root = nullptr;
    tsize = 0;
}


template <typename K, typename V>
void BinaryTree<K, V>::connect(BinaryTreeNode<K, V>* node,BinaryTreeNode<K, V>* node1){
    if (node->parent->leftChild == node) {
        node->parent->leftChild = node1;
    } else {
        node->parent->rightChild = node1;
    }    
}

/**
 *  Convert the tree into a string.
 **/
template <typename K, typename V>
std::string BinaryTree<K, V>::toString(){
    if (root == nullptr){
        return "";
    }
    else{
        return root->toString();
    }
}
