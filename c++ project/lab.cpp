#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* next;

    // Constructor
    //��O�@�ب禡(�غc�禡)
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
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
    void reverseList(){
        Node *buffer = nullptr, *now = head, *nextnode;
        while (now != nullptr)
        {
            nextnode = now->next;
            now->next = buffer;
            buffer = now;
            now = nextnode;
        }
        head = buffer;
    }
    //class�i�N�ܼƻP��Ƥ@���ʸˡA�p�W�N�O�@���Nlinklist���Y�w�q��nullptr�B�P�ɫʸ�push�������
};
int main(){
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.reverseList();
    list.printList();  // Output: 1 2 3
    return 0;
}