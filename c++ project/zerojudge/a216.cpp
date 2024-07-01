#include <iostream>
using namespace std;

int main()
{
    long f, g, n;
    while (cin >> n)
    {
        g = 1;
        f = 1;
        for (int i = 2; i <= n; i++)
        {
            f += i;
            g += f;
        }
        cout << f << ' ' << g << '\n';
    }
    if (cin.eof())
    {
        return 0;
    }
}