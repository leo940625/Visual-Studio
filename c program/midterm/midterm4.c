#include <stdio.h>
int main()
{
    int a,flag;
    printf("Input a positive nuber:");
    scanf("%d",&a);
    for (int i = 2; i <= a; i++)
    {
        flag = 0;
        for (int j = 2; j < i ; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}