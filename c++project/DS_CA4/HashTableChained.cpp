/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"
#include <vector>
#include<iostream>
using namespace std;
/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate){
    Size = 0;
    capacity = nextPrime(sizeEstimate);
    buckets.resize(capacity, nullptr);
    p = nextPrime(100 * capacity);
}

/**,
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(){
    Size = 0;
    capacity = 101;
    buckets.resize(capacity, nullptr);
    p = nextPrime(100 * capacity);
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::compFunction(int code){
    return ((3 * code + 5) % p) % capacity;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::size(){
    return Size;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::isEmpty(){
    return Size == 0;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void HashTableChained<K, V>::insert(const K &key, const V &value){
    Node *new_node = new Node(key, value);
    if (buckets[compFunction(key->hashCode())] == nullptr){
        buckets[compFunction(key->hashCode())] = new_node;
        Size++;
        return;
    }
    Node *last = buckets[compFunction(key->hashCode())];
    while (last->next != nullptr){
        last = last->next;
    }
    last->next = new_node;
    Size++;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::find(const K &key){
    Node *current = buckets[compFunction(key->hashCode())];
    return current == nullptr ? false : true;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void HashTableChained<K, V>::remove(const K &key){
    if (buckets[compFunction(key->hashCode())] != nullptr){
        Node *last = buckets[compFunction(key->hashCode())];
        buckets[compFunction(key->hashCode())] = last->next;
        delete last;
        Size--;
    }
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void HashTableChained<K, V>::makeEmpty(){
    for (int i = 0; i != capacity; i++){
        while (buckets[i] != nullptr){
            Node* current = buckets[i];
            buckets[i] = nullptr;    
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
    }
    Size = 0;
}

template <typename K, typename V>
bool HashTableChained<K, V>::isPrime(int a){ // check whether a is a prime
    if (a <= 1)return false;
    for (int i = 2; i < sqrt(a); i++){
        if (a % i == 0)
            return false;
    }
    return true;
}

template <typename K, typename V>
int HashTableChained<K, V>::nextPrime(int n){
    while (!isPrime(n)){
        n++;
    }
    return n;
}

template <typename K, typename V>
void HashTableChained<K, V>::testHashCode(){
    int disturb = 0,max = 0;
    for (int i = 0; i != capacity; i++){
        int sum = 0;
        while (buckets[i] != nullptr) {
            buckets[i] = buckets[i]->next;
            sum++;
        }
        if (sum != 0){
            //cout << i << ':' << sum << endl;
            disturb++;
        }
        if (sum >= max){
            max = sum;
        }
    }
    cout << "Disturb:" << disturb << endl;
    cout << "Max:" << max << endl;
}
