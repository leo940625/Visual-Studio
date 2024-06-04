#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void push(int b, struct node **first)
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    new->value = b;
    new->next = *first;
    *first = new;
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
void printList(struct node *a)
{
    while (a != NULL)
    {
        if (a->value != -16)
        {
            printf("%d ",a->value);
        }
        a = a->next;
    }
}
int main()
{
    struct node *head = NULL;
    int k,n;
    char m,b;
    printf("If the initial linked list is:");
    while(scanf("%c",&b) && b != '\n'){
        k = (int)b-48;
        push(k,&head);
    }
    reverseList(&head);
    printf("And the sepecific value n is:");
    scanf("%d",&n);
    while (head->value == n)
    {
        head = head->next;
    }
    struct node *current = head;
    while (current->next != NULL)
    {
        if (current->next->value == n)
        {
            current->next = current->next->next;
            continue;
        }
        current = current->next;
    }
    printList(head);
}
