#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float x = 20;
    for (int i = 0; i < 100000; i++)
    {
        x = (x+20)*20/(x+40);
    }
    cout << x << endl;
}