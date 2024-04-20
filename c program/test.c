#include <stdio.h>
int main(){
    char ch;
    float a, ans;
    ans = 0.0f;
    printf("Print an expression: ");
    scanf("%f", &ans);
    scanf("%c", &ch);
    while(ch != '\n'){
        scanf("%f", &a);
        switch(ch){
            case '+': {
                ans = ans + a;
                break;
            }
            case '-': {
                ans = ans - a;
                break;
            }
            case '*': {
                ans = ans * a;
                break;
            }
            case '/':{
                ans = ans / a;
                break;
            }
        }
        scanf("%c", &ch);
    }
    printf("The answer is %.2f", ans);
    return 0;
}