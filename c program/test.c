#include <stdio.h>
void max_min(int a[], int n, int *max, int *min){
    *max = *min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > *max)
        {
            *max = a[i];
        }
        if (a[i] < *min)
        {
            *min = a[i];
        }
    }
}
int main()
{
    int big,small;
    int a[10];
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    max_min(a,n,&big,&small);
    printf("Largest:%d\n",big);
    printf("Smallest:%d\n",small);
    return 0;
}