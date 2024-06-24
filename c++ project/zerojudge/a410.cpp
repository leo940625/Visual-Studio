#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    double det = a * e - b * d;
    if (det == 0)
    {
        if (a * f == c * d && b * f == c * e)
        {
            cout << "Too many" << '\n';
        }
        else
        {
            cout << "No answer" << '\n';
        }
    }
    else
    {
        x = (c * e - b * f) / det;
        y = (a * f - c * d) / det;
        cout << "x=" << fixed << setprecision(2) << x << '\n';
        cout << "y=" << fixed << setprecision(2) << y << '\n';
    }
    return 0;
}