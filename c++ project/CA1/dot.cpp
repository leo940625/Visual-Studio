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
int main(){
    int a[] = {1,5,4,2};
    int b[] = {2,5,4,6};
    cout << dotProduct(a,b,4) << '\n';
}