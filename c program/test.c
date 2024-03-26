#include <stdio.h>

int main() {
    printf("Enter integers:");
    int a,b;
    a = 0;
    b = 0;
    do
    {
        scanf("%d",&a);
        b += a;
    } while (a!=0);
    printf("the sum is %d",b);
}
