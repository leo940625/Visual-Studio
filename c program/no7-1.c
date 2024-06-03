#include <stdio.h>
int main()
{
    char a[10000],k;
    int i = 0;
    printf("Enter a message:");
    while (scanf("%c", &k) == 1 && k != '\n') {
        a[i] = k;
        i++;
    }
    printf("Reversal is:");
    for (int j = i ; j >= 0; j--)
    {
        printf("%c", a[j]);
    }
    return 0;
}