#include <iostream>
using namespace std;

int dotProduct(int a[],int b[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i]*b[i];
    }
    return sum;
}