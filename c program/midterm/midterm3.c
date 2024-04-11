#include <stdio.h>
int main()
{
    float a, c;
    char b;
    printf("Enter an expression:");
    scanf("%f", &a);
    while (1)
    {
        scanf("%c", &b);
        if ((int)b == 10)
        {
            break;
        }
        scanf("%f", &c);
        switch (b)
        {
        case '+':
            a += c;
            break;
        case '-':
            a -= c;
            break;
        case '*':
            a *= c;
            break;
        case '/':
            a /= c;
            break;
        }
    }
    printf("Value of expression:%.1f", a);
    return 0;
}