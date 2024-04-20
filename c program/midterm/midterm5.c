#include <stdio.h>
#include <math.h> 
int main()
{
    char a[100],*p = &a[0];
    long int sum = 0,i = 0;
    printf("Input a binary code:");
    while (scanf("%c",p)){
        if (*p == '\n'){
            break;
        }
        p++;
    }
    for (p -= 1; p >= &a[0]; p--){
        sum += ((int)*p-48)*pow(2,i);
        i++;
    }
    printf("The Equivalent decimal number:%ld",sum);
    return 0;
}