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
int main()
{
    return 0;
}