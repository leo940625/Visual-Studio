/**
* this code is to compute the dot product.
*
* @author ��?�� HSIEH WU-CHAO
* @ID B12505023
* @Department Engineering Science and Ocean Engineering
* @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;

bool isMultiple(long n,long m){
    int a;
    a = n % m == 0 ? 1 : 0;
    return a;
}
int main(){
    int a = isMultiple(4,3) ? 2 : 3;
    cout << a << '\n';
}