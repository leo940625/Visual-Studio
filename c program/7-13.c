#include <stdio.h>

int main()
{
    char a;
    int i = 0;
    int j = 0;
    int g;
    printf("enter a sentence:")
    scanf("%c",&a);
    while (a != '.')
    {
        if (a != ' ')
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    g = i/(j+1);
    printf("averrage word length:%d",g)
    return 0;
}