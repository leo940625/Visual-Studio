#include <stdio.h>
#include <string.h>

int main()
{
    char a[20];
    char max[20],min[20];
    int i = 0;
    printf("Enter word: ");
    scanf("%s",a);
    strcpy(min,a);
    strcpy(max,a);
    while (1)
    {
        printf("Enter word: ");
        scanf("%s",a);
        if (strlen(a) == 4)
        {
            break;
        }
        if (strcmp(a,min) < 0)
        {
            strcpy(min,a);
        }
        if (strcmp(a,max) > 0)
        {
            strcpy(max,a);
        }
    }
    printf("The smallest word:%s\n",min);
    printf("The largest word:%s",max);
    return 0;
}