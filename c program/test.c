#include <stdio.h>

int main()
{
    char a[100];
    scanf("%s",a);
    printf("%s",a);
    size_t n = sizeof(a) / sizeof(a[0]);
    printf("%d",n);
    return 0;
}