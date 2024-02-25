#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{   
    int x[3];// 0=a 1=b 2=N
    long double a ,q ,r;
    while (cin >> x[0]) {
       for (int i = 1; i < 3; i++)
       {
         cin >> x[i]; 
       }
       a = (long double)x[0]/(long double)x[1];
       r = floor(a);
       if (x[2] == 0)
       {
         cout << r << '\n';
       }
       else
       {
         cout << r << '.';
         a = (a-r)*10;
         for (int i = 0; i < x[2]; i++)
         {
           q = floor(a);
           a = (long double)(a-q)*10;
           cout << q;
         }
       }
       cout << '\n';
    }
    if (cin.eof()) {
        return 0;
    } 
}
    