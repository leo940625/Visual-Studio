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
void moveLeftNode(struct node **first, int x, int y);
void moveRightNode(struct node **first, int x, int y);
void switchNode (struct node **first, int x, int y);
int main(){
    struct node *head = NULL;
    int n, step;
    long long sum;
    scanf("%d", &n);
    scanf("%d", &step);
    for (int i = 1; i <= n; i++){
        push(i, &head);
    }
    reverseList(&head);
    int a, b, c;
    for (int j = 0; j < step; j++){
        scanf("%d", &a);
        switch (a){
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
            scanf("%d", &b);
            scanf("%d", &c);
            switchNode(&head,b,c);
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
void moveLeftNode(struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL,*temp;
    push(0,first);
    struct node *current = *first;
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
    temp = (*first);
    (*first) = (*first)->next;
    free(temp);
}
void moveRightNode(struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL,*temp;
    push(0,first);
    struct node *current = *first;
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
    temp = (*first);
    (*first) = (*first)->next;
    free(temp);
}
void switchNode (struct node **first, int x, int y){
    struct node *now1 = NULL, *now2 = NULL,*current = *first;
    int a,flag = 0;
    while(current != NULL && flag != 2){
        if(current->value == x){
            now1 = current;
            flag++;
        }
        else if(current->value == y){
            now2 = current;
            flag++;
        }
        current = current->next;
    }
    a = now1->value;
    now1->value = now2->value;
    now2->value = a;
}