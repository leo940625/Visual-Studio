#include <stdio.h>
struct node
{
    int value;
    struct node *next;
};
struct node* middleNode(struct ListNode* head) {
    struct node *current=head;
    int i;
    float j;
    for(i = 1;current != NULL;i++){
        current=current->next;
    }
    current = head;
    j = i % 2 == 0 ? (i/2)+1 : (i/2)+0.5;
    for(int k = 1;k != j;k++){
        current = current->next;
    }
    head = current;
    return head;
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
    int a;
    struct node *head = NULL;
    printf("Print a list:");
    for (int i = 1; i < 6; i++)
    {
        push(i, &head);
    }
    reverseList(&head);
    head = middleNode(head);
    printList(head);
    return 0;
}