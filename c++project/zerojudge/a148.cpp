#include <iostream>
using namespace std;
int main()
{
    int n, k, sum;
    float j;
    while (cin >> n)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            sum += k;
        }
        j = (float)sum / (float)n;
        j > 59 ? cout << "no" << '\n' : cout << "yes" << '\n';
        if (cin.eof())
        {
            return 0;
        }
    }
}