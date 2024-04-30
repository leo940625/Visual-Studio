#include <stdio.h>
#include <string.h>

int main()
{
    char a[100],c[100];
    scanf("%s",a);
    int b = strlen(a);
    printf("%d",b);
    strcpy(c,a);
    printf("%s",c);
}