#include <iostream>

class Node {
public:
    int value;
    Node* next;

    // Constructor
    //算是一種函式(建構函式)
    Node(int data) : value(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}
    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    // Method to append a new node at the end
    void push(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
    // Method to print the linked list
    void printList() const {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
    //class可將變數與函數一次封裝，如上就是一次將linklist標頭定義為nullptr、同時封裝push等等函數
};
int main() {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.printList();  // Output: 1 2 3

    return 0;
}