#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d,e,f,g;
    printf("enter a fraction:");
    scanf("%d/%d",&a,&b);
    c = a;
    d = b;
    while (a!=0 && b!=0)
    {
       if (abs(a)>=abs(b))
       {
        a = a%b;
       }
       else if (abs(a)<abs(b))
       {
        b = b%a;
       }
    }
    g = a==0 ? b : a;
    e = c/g;
    f = d/g;
    printf("In lowest terms:");
    printf("%d/%d",e,f);
}