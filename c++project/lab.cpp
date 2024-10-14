#include <iostream>
#include <math.h>
using namespace std;

int hashcode(float a){
    double value = a;
    value *= ((1+sqrt(5))/2);
    return (int)value;
}

int main(){
    for (float i = 0; i <100; i++)
    {
        cout << i << ':' << ((3 * hashcode(i + 5) % 1331) % 101) << endl;
    }
    
}