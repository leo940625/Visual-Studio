#include <stdio.h>
int main()
{
    char a[10000];
    int i = 0;
    printf("Enter:");
    while (scanf("%c", &a[i]))
    {
        if (a[i] == '\n') {
            break;
        }    
        i++;
    }
    for (int j = i-1; j >= 0; j--)
    {
        printf("%c", a[j]);
    }
    return 0;
}