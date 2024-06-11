#include <iostream>
using namespace std;

int main()
{
  long long i,n,r,sum;
  while ( cin >> n >> r)
  {
    sum = 0;
    for ( i = 1;; i++){
      sum += n+i-1;
      if(sum>r){
        break;
      }
    }
    cout << i <<'\n';
  }
  if (cin.eof()) {
    return 0;
  } 
  return 0;
}