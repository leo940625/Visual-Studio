#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a[]= {-2,10,-12,6};
    int temp,b = sizeof(a)/sizeof(int);
    int c[b];
    for (int i = 0; i < b; i++)
    {
        c[i] = pow(a[i],2);
    }
    for (int j = 0; j < b-1; j++)
    {
        if (c[j] > c[j+1]){
            temp = c[j];
            c[j] = c[j+1];
            c[j+1] = temp;
            j = -1;
        }
    }
    printf("Sorted squares:");
    for (int k = 0; k < b; k++)
    {
        printf("%d ",c[k]);
    }
    return 0;
}