#include <stdio.h>
void sort3(int *a,int *b ,int *c){
    int temp1,temp2;
    if(*a > *b){
        temp1 = *a;
        *a = *b;
        *b = temp1;
    }
    if(*b > *c){
        temp1 = *b;
        *b = *c;
        *c = temp1;
    }
    if(*a > * b){
        temp1 = *a;
        *a = *b;
        *b = temp1;
    }
}
int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    sort3(&a,&b,&c);
    printf("%d,%d,%d",a,b,c);
}