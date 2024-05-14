#include <stdio.h>
#include <string.h> // strcpy()  
#include <stdlib.h>
struct Node{
    int value;
    struct Node *next;
}*a[4];
int main(){
    struct Node *first = NULL;
    for (int i = 0; i < 4; i++) {
        a[i] = (struct Node *)malloc(sizeof(struct Node));
    }
    a[0]->value = 1;
    a[1]->value = 21;
    a[2]->value = 15;
    a[3]->value = 71;
    first = a[0];
    for (int i = 0; i < 3; i++)
    {
        a[i]->next = a[i+1];
    }
    a[3]->next =  NULL;
    struct Node *buffer = NULL,*now = first,*nextnode;
    while (now != NULL)
    {
        nextnode = now->next;
        now->next = buffer;
        buffer = now;
        now = nextnode;    
    }
    first = buffer;
    struct Node *temp = first;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}
