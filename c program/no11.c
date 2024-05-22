#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void printList(struct node *a);
void push(int b, struct node **first);
void reverseList(struct node **first);
void insert_node(struct node **first, int insert_after_value, int value);
void moveLeftNode(struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL, *current = *first;
    while (current->next != NULL){
        if (current->next->value == x)
        {
            now1 = current;
        }
        else if (current->next->value == y)
        {
            now2 = current;
        }
        current = current->next;
    }
    struct node *node1;
    node1 = now1->next;
    now1->next = now1->next->next;
    node1->next = now2->next;
    now2->next = node1;
}
int main()
{
    int a;
    struct node *head = NULL;
    printf("Print a list:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a);
        push(a, &head);
    }
    printf("Reversed Linked list:");
    reverseList(&head);
    moveLeftNode(&head,4,2);
    printList(head);
    return 0;
}
void printList(struct node *a)
{
    while (a != NULL)
    {
        printf("%d ", a->value);
        a = a->next;
    }
}
void push(int b, struct node **first)
{
    struct node *new = malloc(sizeof(struct node)); // 重新取一個空間
    if (new == NULL)
    {
        printf("Memory allocation failed");
        exit(1); // 退出程序
    }
    new->value = b;
    new->next = *first; // 原本指的next空間變成first原本指向的Null
    *first = new;       // new head 指到a1
}
void reverseList(struct node **first)
{
    struct node *buffer = NULL, *now = *first, *nextnode;
    while (now != NULL)
    {
        nextnode = now->next;
        now->next = buffer;
        buffer = now;
        now = nextnode;
    }
    *first = buffer;
}
void insert_node(struct node **first, int insert_after_value, int value)
{
    struct node *current = *first;
    while (current != NULL)
    {
        if (insert_after_value == current->value)
        {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->value = value;
            new_node->next = current->next;
            current->next = new_node;
            break;
        }
        current = current->next;
    }
}