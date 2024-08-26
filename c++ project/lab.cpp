#include <iostream>

class Node {
public:
    int value;
    Node* next;

    // Constructor
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
    void append(int value) {
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
    //class盢跑计籔ㄧ计Ω杆碞琌Ω盢linklist夹繷﹚竡nullptr杆push单单ㄧ计
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.printList();  // Output: 1 2 3

    return 0;
}