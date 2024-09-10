/**
* this code is to compute the dot product.
*
* @author аб?╔Э HSIEH WU-CHAO
* @ID B12505023
* @Department Engineering Science and Ocean Engineering
* @Affiliation National Taiwan University
*/

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int a)
{
    if (a <= 1) return false;
    for (int i = 2; i < sqrt(a); i++){
        if (a % i == 0)return false;
    }
    return true;
}
int *showPrime(int p)
{
    int *k = new int[2];
    int lower = p, upper = p;
    if (isPrime(p)){
        k[0] = p;
        k[1] = 0;
    }
    else{
        while (!isPrime(lower))lower--;
        k[0] = lower;
        while (!isPrime(upper))upper++;
        k[1] = upper;
    }
    return k;
}
int main(){
    int *a = showPrime(1);
    cout << a[0] << ',' << a[1] << '\n';
}