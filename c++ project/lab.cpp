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
        exit(1); // 退出程序
    }
    other->value = a;
    other->next = *first; // 原本指的next空間變成first原本指向的Null
    *first = other;       // new head 指到a1
}