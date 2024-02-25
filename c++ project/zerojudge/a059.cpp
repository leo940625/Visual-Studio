#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    int time, star, finish, out;
    cin >> time;
    for (int i = 1; i <= time; i++)
    {
        out = 0;
        cin >> star >> finish;
        for (int j = 1; j <= sqrt(finish); j++)
        {
           if (pow(j,2)>=star && pow(j,2)<=finish )
           {
             out += pow(j,2);
           }
        }
        cout << "Case " << i << ": " << out <<'\n';
    }
    return 0;
}