#include <stdio.h>
int is_prime(int a){
    for (int i = 2; i < a ; i++)
    {
        if (a % i == 0)
        {
            return 1;
        }
    }
    return 2;
}
int main()
{
    int i;
    printf("Please enter the number:");
    scanf("%d", &i);
    for (int k = 2; k <= i; k++)
    {   
        if (is_prime(k) == 2)
        {
            printf("%d is a prime under %d \n", k, i);
        }
    }
    return 0;
}