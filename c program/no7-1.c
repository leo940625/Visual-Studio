#include <stdio.h>
#include <string.h>
int main()
{
    char a[10000];
    int i = 0;
    printf("Enter a message:");
    while (scanf("%c", &a[i]) != '\n'){
        i++;
    }
    i -= 1;
    printf("Reversal is:");
    for (int j = i ; j >= 0; j--)
    {
        printf("%c", a[j]);
    }
    return 0;
}