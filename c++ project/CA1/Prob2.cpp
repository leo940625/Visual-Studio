#include <iostream>
using namespace std;
int isPrime(int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a & i == 0)
        {
            return 1;
            break;
        }
    }
    return 2;
}
int *showPrime(int p)
{
    int *k;
    if (isPrime(p) == 2)
    {
        *k = p;
        *(k+1) = 0;
    }
    else{
        
    }
    
}