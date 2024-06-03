#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int time,len;
    scanf("%d",&time);
    for (int i = 0; i < time; i++)
    {
        char *a,*b,*c,*temp;
        a = malloc(100000*sizeof(char));
        scanf("%s",a);
        temp = realloc(a,(strlen(a)+1)*sizeof(char));
        a = temp; 
        scanf("%d",&len);
        b = malloc((len+1)*sizeof(char));
        strncpy(b,a,len);
        b[len] = '\0';
        c = malloc((strlen(a)+1)*sizeof(char));
        strcpy(c,a+(len));
        strcat(c,b);
        printf("%s\n",c); /* code */
    }
}