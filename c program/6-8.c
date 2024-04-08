#include <stdio.h>

int main()
{
    int day,week,flag;
    flag = 0;
    printf("Enter number of days in month:");
    scanf("%d",&day);
    printf("Enter starting day of the week (l=Sun, 7=Sat):");
    scanf("\n%d",&week);
    for (int j = 1; j < week; j++)
    {
        printf("   ");
        flag++;
    }
    for (int i = 1; i <= day; i++)
    {
        i < 10 ?  printf(" %d ",i):printf("%d ",i);
        flag++;
        /*if (i < 10)
        {
            printf(" %d ",i);
            flag++;
        }
        else
        {
            printf("%d ",i);    
            flag++;
        }*/
        if (flag % 7 == 0)
        {
           printf("\n");
        }
    }
    return 0;
}