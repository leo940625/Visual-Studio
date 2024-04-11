#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    a % 2 == 0 ? printf("number is even") : printf("number is odd");
    /*if (a % 2 == 0)
    {
        printf("number is even");
    }
    else
    {
        printf("number is odd");
    }*/
    return 0;
}