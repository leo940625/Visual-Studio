#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    float a, b, c, d, e, f,x,y;
    cin >> a >> b >> c >> d >> e >> f;
    if (a/d == b/e)
    {
        if (a/d == c/f){
            cout << "Too many" <<'\n';
        }
        else{
            cout << "No answer" <<'\n';
        }
    }
    else{
        y = (f*a/d-c)/(e*a/d-b);
        x = (f*b/e-c)/(d*b/e-a);
        cout << "x=" << fixed <<  setprecision(2) << x <<'\n';
        cout << "y=" << fixed <<  setprecision(2) << y <<'\n';
    }
    return 0;
}