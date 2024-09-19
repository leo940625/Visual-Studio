#include <iostream>
using namespace std;

int main()
{
    int x, i, q, r; // q┏计rΩよ
    cin >> x;
    r = 0;
    q = 0;
    i = 2;
    while (i <= x)
    {
        if (x % i == 0)
        {
            x /= i;
            q = i;
            r++;
        }
        else if (q != 0)
        {
            r < 2 ? cout << q << " * " : cout << q << "^" << r << " * ";
            q = 0;
            r = 0;
            i++;
        }
        else
        {
            i++;
        }
    }
    r < 2 ? cout << q : cout << q << "^" << r; // x程穦单1┮程块Ω
    return 0;
}