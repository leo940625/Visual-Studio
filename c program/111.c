#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter number counter:");
    scanf("%d", &n);
    int a[n];
    printf("Enter number:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < n-1; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(&a[j],&a[j+1]);
            j = 0;
        }
    }
    /*
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    */
    printf("Sorted number:");
    for (int k = 0; k < n; k++)
    {
        printf("%d ",a[k]);
    }
    return 0;
}
