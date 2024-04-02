#include <stdio.h>

int main() {
   char a;
   printf("enter phone number:");
   do
   {
     scanf("%c",&a);
     if ((int)a >= 65 && (int)a <= 90 && (int)a != 90 && (int)a != 81)
     {
        for (int i = 0; i < 5; i++)
        {
            if ((int)a >= 65+3*i && (int)a <= 67+3*i)
            {
                printf("%d",i+2);
            }
        }
        for (int j = 0; j < 2; j++)
        {
            if ((int)a >= 84+3*j && (int)a <= 86+3*j)
            {
                printf("%d",j+8);
            }
        }
        if ((int)a == 80 || (int)a == 82 || (int)a == 83)
        {
          printf("7");
        }
     }
     else{
       printf("%c",a);
     }
   } while (a != '\n');
   return 0;
}