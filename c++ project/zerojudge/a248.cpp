#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{   
  long long a,b,n;
  int k,q;
  while (cin >> a >> b >> n){
    k = a/b;
    if (n == 0)
    {
      cout << k << '\n';
      continue;
    }
    cout << k << '.';
    a-=(k*b);
    for (int i = 0; i < n; i++)
    {
      a *= 10;
      q = a/b;
      a -= (q*b);
      cout << q;
    }
    cout << '\n';
  }
  if (cin.eof()){
    return 0;
  } 
}
    