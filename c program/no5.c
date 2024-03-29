#include <stdio.h>
#include <math.h>
int a,b;
int hcf(int a,int b){
    int x;
    while (a!=0 && b!=0)
    {
       if (abs(a)>=abs(b))
       {
        a = a%b;
       }
       else if (abs(a)<abs(b))
       {
        b = b%a;
       } 
    } 
    x = a==0 ? b : a;
    return x;
}
int main(){
    int e,f,g;
    printf("enter a fraction:");
    scanf("%d/%d",&a,&b);
    g = hcf(a,b);
    e = a/g;
    f = b/g;
    printf("In lowest terms:");
    printf("%d/%d",e,f);
}