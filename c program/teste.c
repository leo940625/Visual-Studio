#include <stdio.h>
#include <string.h> // strcpy()  
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
}*a[10];
char *concat(const char *s1, const char *s2){
    char *result;
    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
int main(){
    int *p;
    p = calloc(10,sizeof(int));
    if(p == NULL){
        free(p);
    }
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("%d\n",p[5]);
    char *ptr;
    ptr = (char*)malloc(10*sizeof(char));
    scanf("%s",ptr);
    printf("%s",ptr);
}