#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d;
    printf("enter a number between 0 and 32767:");
    scanf("%d",&a);
    printf("In octal,your number is:0");
    for (int i = 3; i >= 0; i--)
    {
        b=a/pow(8,i);
        printf("%d",b);
        a = a-b*pow(8,i);
    }
    return 0;
    
}