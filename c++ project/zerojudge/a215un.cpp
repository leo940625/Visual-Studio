#include <iostream>
using namespace std;

int main()
{
    long n,r,sum;
    while (cin >> n >> r)
    {
      for (int i = 1; sum < r; i++)
      {
        sum = i*n + ((0+i-1)*i)/2;
        if (sum > r)
        {
          cout << i <<'\n';
        }
      }
    }
    if (cin.eof())
    {
       return 0;
    }
}