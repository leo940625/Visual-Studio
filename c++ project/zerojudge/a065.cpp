#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char x[7];
    cin >> x;
    int y;
    for (int i = 0; i < 6; i++)
    {
        y = abs(int(x[i]) - int(x[i+1]));
        cout << y;
    }
    cout << '\n';
    return 0;
}