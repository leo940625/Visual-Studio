/**
* this code is to compute the dot product.
*
* @author 謝?兆 HSIEH WU-CHAO
* @ID B12505023
* @Department Engineering Science and Ocean Engineering
* @Affiliation National Taiwan University
*/
#include <iostream>
using namespace std;

int dotProduct(int a[],int b[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i]*b[i];//將各項相乘並加總
    }
    return sum;
}