#include <stdio.h>
int main()
{
    float principal,rate,day;
    double sum;
    printf("Enter loan principal:");
    scanf("%f",&principal);
    printf("Enter interest rate:");
    scanf("%f",&rate);
    printf("Enter term of the loan in days:");
    scanf("%f",&day);
    sum = principal*rate*day/365;
    printf("The interset charge is $%.2lf",sum);
    return 0;
}