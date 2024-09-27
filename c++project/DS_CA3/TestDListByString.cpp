#include <cassert>
#include <iostream>
#include <string>
#include "DList.h"
#include "DListNode.h"

#include "LockDList.h"
#include "LockDList.cpp"
#include "LockDListNode.h"

using namespace std;

int main() {
    cout << "====================" << endl;
    cout << "Part 1 Testing DList" << endl;
    cout << "====================" << endl;
    
    class DList<string> d1;
    class DList<string> dempty;

    cout << "Insert 3 items(\"apple\", \"banana\", \"cherry\") at the front of this DList.";
    d1.insertFront("apple");
    d1.insertFront("banana");
    d1.insertFront("cherry");
    assert((d1.length() == 3) && (!d1.isEmpty()));
    cout << "->OK" << endl;

    cout << "Insert 2 items(\"date\", \"elderberry\") at the back of this DList.";
    d1.insertBack("date"); 
    d1.insertBack("elderberry");
    assert(d1.length() == 5);
    cout << "->OK" << endl;
    
    cout << "\"cherry\" is at the front of this DList.";
    assert(d1.front()->item == "cherry");
    cout << "->OK" << endl;
    
    cout << "If the DList is empty, front() returns null."; 
    assert(!dempty.front());
    cout << "->OK" << endl;
    
    cout << "\"elderberry\" is at the back of this DList.";
    assert(d1.back()->item == "elderberry"); 
    cout << "->OK" << endl;
    
    cout << "If the DList is empty, back() returns null."; 
    assert(!dempty.back());
    cout << "->OK" << endl;

    cout << "The node following \"cherry\" is \"banana\"";
    assert(d1.next(d1.front())->item == "banana");
    cout << ", and the node following \"banana\" is \"apple\".";
    assert(d1.next(d1.next(d1.front()))->item == "apple");
    cout << "->OK" << endl;
    
    cout << "\"elderberry\" is the last node in this DList, return null.";
    assert(!(d1.next(d1.back())));
    cout << "->OK" << endl;
    
    cout << "If input is null, return null.";
    assert(!(d1.next(NULL)));
    cout << "->OK" << endl;

    cout << "The node prior to \"elderberry\" is \"date\"";
    assert(d1.prev(d1.back())->item == "date");
    cout << ", and the node prior to \"date\" is \"apple\".";
    assert(d1.prev(d1.prev(d1.back()))->item == "apple");
    cout << "->OK" << endl;
    
    cout << "\"cherry\" is the first node in this DList, return null.";
    assert(!(d1.prev(d1.front())));
    cout << "->OK" << endl;
    
    cout << "If input is null, return null.";
    assert(!(d1.prev(NULL)));
    cout << "->OK" << endl;
    
    cout << endl;
    cout << "insertAfter() Test:" << endl;
    cout << "[cherry, banana, apple, date, elderberry] -> [cherry, banana, fig, apple, date, elderberry, grape]" << endl;
    d1.toString();
    
    d1.insertAfter("fig", d1.next(d1.front()));
    assert(d1.next(d1.next(d1.front()))->item == "fig");
    
    d1.insertAfter("grape", d1.back());
    assert(d1.back()->item == "grape");
    
    d1.toString();
    cout << endl;
    
    cout << "insertAfter(item, NULL) does nothing.";
    d1.insertAfter("honeydew", NULL);
    cout << "->OK" << endl;

    cout << endl;
    cout << "insertBefore() Test:" << endl;
    cout << "[cherry, banana, fig, apple, date, elderberry, grape] -> [kiwi, cherry, banana, fig, apple, date, elderberry, mango, grape]" << endl;
    
    d1.insertBefore("kiwi", d1.front());
    assert(d1.front()->item == "kiwi");
    
    d1.insertBefore("mango", d1.back());
    assert(d1.prev(d1.back())->item == "mango");
    
    d1.toString();
    cout << endl;
    
    cout << "insertBefore(item, NULL) does nothing.";
    d1.insertBefore("nectarine", NULL);
    cout << "->OK" << endl;
    
    cout << endl;
    cout << "remove() Test ";
    
    d1.remove(NULL); // 不執行任何操作
    d1.remove(d1.next(d1.next(d1.front()))); // 移除 "banana"
    d1.remove(d1.front()); // 移除 "kiwi"
    d1.remove(d1.front()); // 移除 "cherry"
    d1.remove(d1.back()); // 移除 "grape"
    d1.remove(d1.back()); // 移除 "elderberry"
    d1.remove(d1.back()); // 移除 "date"
    d1.remove(d1.back()); // 移除 "apple"
    
    // 最後應該剩下 "fig" 和 "mango"
    assert(d1.front()->item == "fig" && d1.back()->item == "apple");
    cout << "->OK" << endl;
    
    cout << endl;
    cout << "========================" << endl;
    cout << "Part 2 Testing LockDList" << endl;
    cout << "========================" << endl;
    
    LockDList<string> ld1;
    ld1.insertFront("alpha");
    ld1.insertBack("beta");
    ld1.insertAfter("gamma", ld1.next(ld1.front()));
    ld1.insertBefore("delta", ld1.back());
    ld1.insertFront("epsilon");
    ld1.toString();
    
    cout << "Lock the node \"epsilon\" and the node \"gamma\"." << endl;
    ld1.lockNode(ld1.back()); // 假設 "gamma" 是最後一個節點
    ld1.lockNode(ld1.front()); // "epsilon"
    
    cout << "Remove all nodes." << endl;
    DListNode<string>* ld1backNode = ld1.back();
    int ld1length = ld1.length();
    for(int i = 0; i < ld1length; i++) {
        DListNode<string>* temp = ld1.prev(ld1backNode);
        ld1.remove(temp);
        temp = ld1backNode;
    }
    
    // 應保留被鎖定的節點 "epsilon" 和 "gamma"
    assert(ld1.front()->item == "epsilon" && ld1.back()->item == "gamma");
    ld1.toString();

    return 0;
}