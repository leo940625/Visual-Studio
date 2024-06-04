#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void find_two_largest(int *a,int n,int *largest,int *second){
    
    *largest = *second = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= *largest)
        {
            *largest = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < *largest && a[i] > *second)
        {
            *second = a[i];
        }
    }
}
int main()
{
    int a[]= {-5,-6,0,-1};
    int max,sec;
    int b = sizeof(a)/sizeof(int);
    find_two_largest(a,b,&max,&sec);
    printf("Largest is:");
    printf("%d\n",max);
    printf("Second Largest is:");
    printf("%d\n",sec);
    return 0;
}