#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char a[20][100],b,ch;
    int i = 0,j = 0;
    printf("Enter a sentence:");
    while (scanf("%c", &ch) == 1 && ch != '\n') {
        if (ch == ' ') {
            a[i][j] = '\0';
            i++;
            j = 0;
        } 
        else {
            a[i][j] = ch;
            j++;
        }
    }
    a[i][j] = '\0';
    for (; i >= 0; i--)
    {
        j = 0;
        while (a[i][j] != '\0')
        {
            printf("%c",a[i][j]);
            j++;
        }
        if(i > 0){
            printf(" ");
        }
    }
}