#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
int main(){
    double sum = 0;
    for(int i = 0 ; i < 100000 ; i++){
        sum += i*pow(1-0.00807,i-1)*0.00807;
    }
    cout << sum << endl;
}