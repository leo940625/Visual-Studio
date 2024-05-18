#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    char value[10];
    struct node *next;
};
void sortList (struct node **first);
void printList(struct node *a);
void push(char a[],struct node **first);
void reverseList(struct node **first);
int main(){
    char b[10] = {0};
    struct node *head = NULL;
    while (strlen(b)!=4)
    {
        printf("Enter a word:");
        scanf("%s",b);
        push(b,&head);
    }
    sortList(&head);
    printList(head);
    return 0;
}
void printList(struct node *a){
    while (a != NULL)
    {
        printf("%s ",a->value);
        a = a->next;
    }
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
void sortList (struct node **first){
    struct node *bus = *first,*busnext = NULL;
    while (bus->next != NULL)
    {
        busnext = bus->next;
        if (strcmp(bus->value,busnext->value)>0)
        {
            char c[10];
            strcpy(c,bus->value);
            strcpy(bus->value,busnext->value);
            strcpy(busnext->value,c);
            bus = *first;
            continue;
        }
        bus = busnext;
    }
    
}