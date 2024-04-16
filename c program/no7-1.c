#include <stdio.h>
int main()
{
    char a[10000];
    int i = 0;
    printf("Enter a message:");
    while (scanf("%c", &a[i])){
        if (a[i] == '\n'){
            i -= 1;
            break;
        }
        i++;
    }
    printf("Reversal is:");
    for (int j = i ; j >= 0; j--)
    {
        printf("%c", a[j]);
    }
    return 0;
}