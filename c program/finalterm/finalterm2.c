#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* addSpace(char*s,int space[],int spaceSize){
    int i = 0;
    int j = 0;
    for (int i = 0; i < strlen(s);i++)
    {
        if (i == space[j]){
            printf(" ");
            j++;
        }
        printf("%c",s[i]);
    }
}
int main()
{
    char s[]="computerscience";
    int space[]={2,3,6};
    int size = sizeof(space)/sizeof(int);
    addSpace(s,space,size);
    return 0;
}