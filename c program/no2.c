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
    int a, b, c, d, e, f;
    printf("first input:");
    scanf("%d/%d", &a, &b);
    printf("second input:");
    scanf("%d/%d", &c, &d);
    e = c * b + a * d;
    f = d * b;
    printf("%d/%d", e/gcd(e,f), f/gcd(e,f));
    return 0;
}