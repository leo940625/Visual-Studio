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
    return (n % m == 0 ? true : false);// if n%m == 0 return true else false
}
int main(){
    int a = isMultiple(4,3) ? 2 : 3;
    cout << a << '\n';
}