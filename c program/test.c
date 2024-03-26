#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter integers:");
    scanf("%d %d",&a,&b);
    while (a!=0 && b!=0)
    {
       if (a>=b)
       {
        a = a%b;
       }
       else if (a<b)
       {
        b = b%a;
       }
    }
    c = a == 0 ? b : a;
    printf("%d",c);
}
