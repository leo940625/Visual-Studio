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
    if (node != nullptr){
        return node->entry;
    }
    else{
        return nullptr;
    }
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
    // No child
    if (target->leftChild == nullptr && target->rightChild == nullptr) { // external node
        if (target == root) {
            root = nullptr;
        } else if (target->parent->leftChild == target) {
            target->parent->leftChild = nullptr;
        } else {
            target->parent->rightChild = nullptr;
        }
        delete target;
        tsize--;
        return;
    }
    // One child
    if (target->leftChild == nullptr) {
        if (target == root) {
            root = target->rightChild;
            root->parent = nullptr;
        } else if (target->parent->leftChild == target) {
            target->parent->leftChild = target->rightChild;
            target->rightChild->parent = target->parent;
        } else {
            target->parent->rightChild = target->rightChild;
            target->rightChild->parent = target->parent;
        }
        delete target;
        tsize--;
        return;
    } else if (target->rightChild == nullptr) {
        if (target == root) {
            root = target->leftChild;
            root->parent = nullptr;
        } else if (target->parent->leftChild == target) {
            target->parent->leftChild = target->leftChild;
            target->leftChild->parent = target->parent;
        } else {
            target->parent->rightChild = target->leftChild;
            target->leftChild->parent = target->parent;
        }
        delete target;
        tsize--;
        return;
    }
    //two child
    BinaryTreeNode<K, V> *temp = target->rightChild;
    while (temp->leftChild != nullptr){
        temp = temp->leftChild;
    }
    cout << 1 << endl;
    BinaryTreeNode<K, V> *buffer = new BinaryTreeNode<K, V>(target->entry,target->parent,target->leftChild,target->rightChild);
    buffer->leftChild->parent = buffer;
    buffer->rightChild->parent = buffer;
    cout << 2 << endl;
    if (target->parent != nullptr){
        if (target->parent->leftChild == target){
        target->parent->leftChild = buffer;
        }else{
        target->parent->rightChild = buffer;
        }
    }
    cout << 3 << endl;
    delete target;
    cout << 4 << endl;
    //刪除temp
    if (temp->parent->leftChild == temp){
        temp->parent->leftChild = temp->rightChild;
    }
    else{
        temp->parent->rightChild = temp->rightChild;
    }
    cout << 5 << endl;
    if (temp->rightChild != nullptr){
        temp->rightChild->parent = temp->parent;
    }
    delete temp;
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
