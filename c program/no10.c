#include <stdio.h>
struct play
{
    int hour, minute, sec;
} x[2],last;
int main()
{
    for (int i = 0 ; i < 2; i++)
    {
        printf("Enter time%d:",i+1);
        scanf("%d:%d:%d", &x[i].hour, &x[i].minute, &x[i].sec);
    }
    if (x[0].sec > x[1].sec)
    {
        x[1].sec += 60;
        x[1].minute -= 1;
    }
    last.sec = x[1].sec - x[0].sec;
    if (x[0].minute > x[1].minute)
    {
        x[1].minute += 60;
        x[1].hour -= 1;
    }
    last.minute = x[1].minute - x[0].minute;
    if (x[0].hour > x[1].hour)
    {
        x[1].hour += 24;
    }
    last.hour = x[1].hour - x[0].hour;
    printf("%d:%d:%d",last.hour,last.minute,last.sec);
}