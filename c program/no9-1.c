#include <stdio.h>
#include <string.h>

int main()
{
    char a[20],max[20],min[20];
    printf("Enter word: ");
    scanf("%s",a);
    strcpy(min,a);
    strcpy(max,a);
    while (strlen(a) != 4)
    {
        printf("Enter word: ");
        scanf("%s",a);
        if (strcmp(a,min) < 0)
        {
            strcpy(min,a);
        }
        else if (strcmp(a,max) > 0)
        {
            strcpy(max,a);
        }
    }
    printf("The smallest word:%s\n",min);
    printf("The largest word:%s",max);
    return 0;
}