#include <stdio.h>
#define N 10

int main(){
    int a[N], sum, i;
    printf("Enter ten numbers:");
    for(i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<N;i++){
        sum += a[i];
    }
    printf("The sum of all numbers is: %d", sum);
    return 0;
}