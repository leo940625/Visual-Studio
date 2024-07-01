#include <iostream>
using namespace std;

int main()
{
    string target;
    cin >> target;
    int lenght = target.length();
    for (int i = 0; i < lenght/2; i++)
    {
        if (target[i] != target[lenght-i-1])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}                       