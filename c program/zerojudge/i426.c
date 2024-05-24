#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
long long printList(struct node *a);
void push(int b, struct node **first);
void reverseList(struct node **first);
void insert_node(struct node **first, int insert_after_value, int value);
void moveLeftNode(struct node **first, int x, int y);
void moveRightNode(struct node **first, int x, int y);
int main()
{
    struct node *head = NULL;
    int n, step;
    long long sum;
    scanf("%d", &n);
    scanf("%d", &step);
    for (int i = 1; i <= n; i++)
    {
        push(i, &head);
    }
    reverseList(&head);
    int a, b, c;
    for (int j = 0; j < step; j++)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            scanf("%d", &b);
            scanf("%d", &c);
            moveLeftNode(&head,b,c);
            break;
        case 2:
            scanf("%d", &b);
            scanf("%d", &c);
            moveRightNode(&head,b,c);
            break;
        case 3:
            /* code */
            break;
        case 4:
            reverseList(&head);
            break;
        }
    }
    sum = printList(head);
    printf("%lld",sum);
    return 0;
}
long long printList(struct node *a)
{
    long long sum = 0;
    int i = 1;
    while (a != NULL)
    {
        if (i % 2 != 0)
        {
            sum += a->value;
        }
        i++;
        a = a->next;
    }
    return sum;
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
void moveLeftNode(struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL, *current = *first;
    if (current->value == x)
    {
        now1 = current;
        *first = current->next;
        while (current->next != NULL){
            if (current->next->value == y)
            {
                now2 = current;
                break;
            }
            current = current->next;
        }
        now1->next = now2->next;
        now2->next = now1;
    }
    else if (current->value == y)
    {
        now1 = current;
        while (current->next != NULL){
            if (current->next->value == x)
            {
                now2 = current;
                break;
            }
            current = current->next;
        }
        *first = now2->next;
        now2->next = now2->next->next;
        (*first)->next = now1;

    }
    else{
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
    
}
void moveRightNode(struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL, *current = *first;
    if (current->value == x)
    {
        now1 = current;
        *first = current->next;
        while (current->next != NULL){
            if (current->next->value == y)
            {
                now2 = current;
                break;
            }
            current = current->next;
        }
        now1->next = now2->next->next;
        now2->next->next = now1;
    }
    else if (current->value == y)
    {
        now1 = current;
        while (current->next != NULL){
            if (current->next->value == x)
            {
                now2 = current;
                break;
            }
            current = current->next;
        }
        struct node *node2 = now2->next; 
        now2->next = now2->next->next;
        node2->next = now1->next;
        now1->next = node2;
    }
    else{
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
        node1->next = now2->next->next;
        now2->next->next = node1;
    }
}
void switchNode (struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL, *current = *first;
    if (current->value == x || current->value == y )
    {
        now1 = current;
        while (current->next != NULL){
            if (current->value == x || current->value == y)
            {
                now2 = current;
                break;
            }
            current = current->next;
        }
    }
    else{
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
        struct node *node1 = now1->next,*node2 = now2->next,*node3 = node2->next;
        now1->next = node2;
        node2->next = node1->next;
        now2->next = node1;
        node1->next = node3;
    }
}