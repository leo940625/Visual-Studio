#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int b,j;
    char a[100],c[100],k;
    printf("Enter a sentence:");
    while (scanf("%c", &k) == 1 && k != '\n') {
        a[j] = k;
        j++;
    }
    scanf("%d",&b);
    for (int i = 0; i <= j ; i++)
    {
        if ((int)a[i]>= 65 && (int)a[i]<= 90)
        {
            c[i] = (char)((((int)a[i]-65)+b)%26 + 65);
        }
        else if((int)a[i]>= 97 && (int)a[i]<= 122){
            c[i] = (char)((((int)a[i]-97)+b)%26 + 97);
        }
        else{
            c[i] = a[i];
        }
    }
    printf("%s",c);
}