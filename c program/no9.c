#include <stdio.h>
#include <string.h>

int main()
{
    char a[20][20];
    char max[20],min[20];
    int i = 0;
    for (;strlen(a[i-1]) != 4;i++)
    {
        printf("Enter word: ");
        scanf("%s",a[i]);
    }
    strcpy(min,a[0]);
    strcpy(max,a[0]);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(a[j],min) < 0)
        {
            strcpy(min,a[j]);
        }
        else if (strcmp(a[j],max) > 0)
        {
            strcpy(max,a[j]);
        }
    }
    printf("The smallest word:%s\n",min);
    printf("The largest word:%s",max);
    return 0;
}