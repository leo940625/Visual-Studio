#include <stdio.h>

int main()
{
    char a;
    float i,j,g;
    i = j = 0;
    printf("Enter a sentence:");
    do
    {
        scanf("%c",&a);
        a != ' ' ? i++ : j++;
    } while (a != '.');
    g = i/(j+1);
    printf("Average word length:%.1f",g);
    return 0;
}