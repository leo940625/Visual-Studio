#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
        int value;
        struct node *next;
};
void printList(struct node *a);
void push(int b,struct node **first);
int main(){
    int a;
    struct node *head = NULL;
    printf("Print a list:");
    for (int i = 0; i < 5; i++){
        scanf("%d",&a);
        push(a,&head);
    }
    printf("Reversed Linked list:");
    printList(head);
    return 0;
}
void printList(struct node *a){
    while (a != NULL)
    {
        printf("%d ",a->value);
        a = a->next;
    }
}
void push(int b,struct node **first){
    struct node *new;
    new = malloc(sizeof (struct node)); // 重新取一個空間
    new->value = b;
    new -> next = *first; //原本指的next空間變成first原本指向的Null
    *first = new; // new head 指到a1
}
