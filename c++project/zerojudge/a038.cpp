#include <iostream>
using namespace std;

int main()
{
    string x, y;
    cin >> x;
    int n = x.length();
    for (int i = n - 1; i >= 0; i--)
    {
        y += x[i];
    }
    while (true)
    {
        if (y[0] == '0')
        {
            if (y.length() == 1)
            {
                cout << '0' << endl;
                return 0;
            }
            else
            {
                y.erase(0, 1);
            }
        }
        else
        {
            cout << y << endl;
            return 0;
        }
    }
}