#include <stdio.h>

int main() {
    printf("Enter integers:");
    int a,b;
    b = 0;
    scanf("%d",&a);
    while (a!=0)
    {
        b += a;
        scanf("%d",&a);
    }
    printf("the sum is %d",b);
   
}
