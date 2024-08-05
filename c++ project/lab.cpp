#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int value;
    struct node *next;
};
void push(int a, struct node **first)
{
    node *other = new node();
    if (other == NULL)
    {
        printf("Memory allocation failed");
        exit(1); // �h�X�{��
    }
    other->value = a;
    other->next = *first;//�쥻����next�Ŷ��ܦ�first�쥻���V��Null
    *first = other;// new head ���� a
}
void reverseList(struct node **first){
    node *current = *first,*nextNode,*buffer = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = buffer;
        buffer = current;
        current = nextNode;
    }
    *first = buffer;
}
void printList(struct node *first){
    while (first != NULL)
    {
        cout << first->value << ' ';
        first = first->next;
    }
}
int main()
{
    node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        push(i,&head);
    }
    //reverseList(&head);
    printList(head);
    return 0;
}