#include <stdio.h>

int main()
{
    char a;
    float i = 0;
    float j = 0;
    double g;
    printf("Enter a sentence:");
    do
    {
        scanf("%c",&a);
        a != ' ' ? i++ : j++;
    } while (a != '.');
    g = i/(j+1);
    printf("Average word length:%.1lf",g);
    return 0;
}