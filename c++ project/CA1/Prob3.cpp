#include <iostream>
using namespace std;

bool isMultiple(long n,long m){
    int a;
    a = n % m == 0 ? 1 : 0;
    return a;
}