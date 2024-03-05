#include <stdio.h>
#include <math.h>
int main()
{
    int r;
    const float PI = 3.14;
    printf("input your radius:");
    scanf("%d",&r);
    float volume = 4*PI*pow(r,3)/3;
    printf("%5.5f",volume);
    return 0;
}