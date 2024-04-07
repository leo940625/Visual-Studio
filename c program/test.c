#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, k;
    printf("Please enter the number:");
    scanf("%d", &i);
    for (k = i; k > 1; k = k - 1)
    {
        int flag = 1, n;
        for (n = 2; n <= k / 2; n++)
        {
            if (k % n == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d is a prime under %d \n", k, i);
        }
    }
    return 0;
}