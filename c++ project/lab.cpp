#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int value;
    struct node *next;
};
int main()
{
    node *head = NULL;
    return 0;
}
void push(int a, struct node **first)
{
    node *other = new node();
    if (other == NULL)
    {
        printf("Memory allocation failed");
        exit(1); // �h�X�{��
    }
    other->value = a;
    other->next = *first; // �쥻����next�Ŷ��ܦ�first�쥻���V��Null
    *first = other;       // new head ����a1
}