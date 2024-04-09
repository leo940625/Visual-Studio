#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    int x;
    while (a != 0 && b != 0)
    {
        if (abs(a) >= abs(b))
        {
            a = a % b;
        }
        else if (abs(a) < abs(b))
        {
            b = b % a;
        }
    }
    x = a == 0 ? b : a;
    return x;
}
int main()
{
    int a, b;
    printf("enter a fraction:");
    scanf("%d/%d", &a, &b);
    printf("In lowest terms:");
    printf("%d/%d",a/gcd(a, b),b/gcd(a, b));
    return 0;
}