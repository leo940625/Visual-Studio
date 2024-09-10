#include <iostream>
using namespace std;
bool isPrime(int a)
{
    if (a <= 1) return false;
    for (int i = 2; i < a; i++){
        if (a % i == 0){
            return 0;
            break;
        }
    }
    return 1;
}
int *showPrime(int p)
{
    int *k = new int[2];
    int a = p, b = p;
    if (isPrime(p)){
        *k = p;
        *(k + 1) = 0;
    }
    else{
        while (!isPrime(a)){
            a--;
        }
        *k = a;
        while (!isPrime(b)){
            b++;
        }
        *(k + 1) = b;
    }
    return k;
}