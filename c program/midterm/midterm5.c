#include <stdio.h>
#include <math.h> 
int main()
{
    char a[100];
    int i = 0;
    long int sum,g,m;
    sum = 0;
    printf("Input a binary code:");
    while (1)
    {
        scanf("%c",&a[i]);
        if (a[i] == '\n')
        {
            break;
        }
        i++;
    }
    m = g = i - 1;
    for (int j = 0; j <= m; j++)
    {
        sum += ((int)a[j]-48)*pow(2,g);
        g--;
    }
    printf("The Equivalent decimal number:%ld",sum);
    return 0;
    //01234
    //43210
}