#include <iostream>
using namespace std;

int main()
{ 
    int h[5];
    int n;
    float r, d;
    cin >> n;
    for (int time = 0; time< n; time++)
    {
        for (int i = 0; i < 4; i++)
        {
          cin >> h[i];
          cout << h[i] <<' '; 
        }
        if ( h[1]- h[0]==h[2]- h[1])
        {
          d = h[1]- h[0];
          h[4] =  h[3]+d;
          cout << h[4] << endl;
        }
        else if (h[1]/h[0]==h[2]/h[1])
        {
          r = h[1]/h[0];
          h[4] =  h[3]*r;
          cout << h[4] << endl;
        }
        
    }
    }