#include <stdio.h>
int main()
{
    char a[10000];
    char *p = &a[0];
    printf("Enter a message:");
    while (scanf("%c",p)){
        if (*p == '\n'){
            break;
        }
        p++;
    }
    p = p-1;
    printf("Reversal is:");
    for (int i = 0; p >= &a[0];p--)
    {
        printf("%c", *p);
    }
    return 0;
}