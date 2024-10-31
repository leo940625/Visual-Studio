#include <iostream>
#include <math.h>
using namespace std;
int square(int a){
    if (a == 1){
        return 1;
    }
    else{
        return a*a + square(a-1);
    }
}
int main(){
    cout << square(2) << endl;
}