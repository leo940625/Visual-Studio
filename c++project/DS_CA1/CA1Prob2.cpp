/**
 *
 *
 * @author 謝珷兆 HSIEH WU-CHAO
 * @ID B12505023
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int a) // check whether a is a prime
{
    if (a <= 1)return false;
    for (int i = 2; i < sqrt(a); i++)
    {
        if (a % i == 0)return false;
    }
    return true;
}
int *showPrime(int p)
{
    int *k = new int[2];
    int lower = p, upper = p;
    if (isPrime(p))
    { // if p is prime let k = {p,0}
        k[0] = p;
        k[1] = 0;
    }
    else
    { // if p is not prime let k = {lower,upper}
        while (!isPrime(lower))
            lower--;
        k[0] = lower;
        while (!isPrime(upper))
            upper++;
        k[1] = upper;
    }
    return k;
}

