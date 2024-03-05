#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d,e,f;
    printf("first input:");
    scanf("%d/%d",&a,&b);
    printf("second input:");
    scanf("%d/%d",&c,&d);
    e = c*b+a*d;
    f = d*b;
    printf("%d/%d",e,f);
    return 0;
}