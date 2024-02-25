#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char x[10];
    const int ID[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    cin >> x;
    int letter ,sum , digit ,o;
    sum = 0;
    letter = ID[int(x[0])-65];
    digit = letter%10;
    letter -= digit;
    letter /= 10;
    sum = letter + digit*9;
    for (int i = 1; i < 10; i++)
    {
      o = 0;
      o = (int(x[i]) - 48)*(9-i);
      sum += o;
    }
    sum += int(x[9]) - 48;
    sum%10 == 0 ? cout << "real" <<'\n' : cout << "fake" <<'\n';
    return 0;
}