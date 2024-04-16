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
    printf("Reversal is:");
    for (p -= 1;p >= &a[0];p--)
    {
        printf("%c", *p);
    }
    return 0;
}