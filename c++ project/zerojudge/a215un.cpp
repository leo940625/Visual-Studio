#include <iostream>
using namespace std;

int main()
{
  long long i,n,r,sum;
  while (!cin.eof())
  {
    cin >> n >> r;
    sum = 0;
    for ( i = 1; sum < r; i++){
      sum += n+i-1;
    }
    cout << i-1 <<'\n';
  }
  return 0;
}