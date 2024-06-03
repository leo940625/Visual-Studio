#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void middleNode(struct node **head)
{
    struct node *current = *head;
    int count = 0, middle;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    current = *head;
    middle = count / 2;
    for (int i = 0; i < middle; i++)
    {
        current = current->next;
    }
    *head = current;
}
void push(int b, struct node **first)
{
    struct node *new = malloc(sizeof(struct node)); // 重新取一個空間
    new->value = b;
    new->next = *first; // 原本指的next空間變成first原本指向的Null
    *first = new;       // new head 指到a1
}
void printList(struct node *a)
{
    while (a != NULL)
    {
        printf("%d ", a->value);
        a = a->next;
    }
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
int main()
{
    struct node *head = NULL;
    for (int i = 1; i < 6; i++)
    {
        push(i, &head);
    }
    reverseList(&head);
    middleNode(&head);
    printf("Print a list:");
    printList(head);
    return 0;
}