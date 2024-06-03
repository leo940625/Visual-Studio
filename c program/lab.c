#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    char value[10];
    struct node *next;
};
void reverseList(struct node **first){
    struct node *buffer = NULL,*now = *first,*nextnode;
    while (now != NULL)
    {
        nextnode = now->next;
        now->next = buffer;
        buffer = now;
        now = nextnode;
    }
    *first = buffer;
}
void push(char a[],struct node **first){
    struct node *new = malloc(sizeof (struct node)); // 重新取一個空間
    if (new == NULL) {
        printf("Memory allocation failed");
        exit(1); // 退出程序
    }
    strcpy(new->value,a);
    new -> next = *first; //原本指的next空間變成first原本指向的Null
    *first = new; // new head 指到a1
}
void printList(struct node *a){
    while (a != NULL)
    {
        printf("%s ",a->value);
        a = a->next;
    }
}
int main(){
    struct node *head = NULL;
    char c[10];
    while (scanf("%s",c));
    {
        push(c,&head);
    }
    //reverseList(&head);
    printList(head);
}