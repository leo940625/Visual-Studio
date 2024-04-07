#include <stdio.h>

int main()
{
    char a;
    float i,j;
    i = j = 0;
    printf("Enter a sentence:");
    do
    {
        scanf("%c",&a);
        a != ' ' ? i++ : j++;
    } while (a != '.');
    printf("Average word length:%.1f",i/(j+1));
    return 0;
}