#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b){
    return a+b;
}
int main(){
    int int_a = 7022,int_b = 100;
    double d_a = 0.1, d_b = 7.022;
    cout << add(int_a, int_b) << '\n';// 7122
    cout << add(d_a, d_b) << '\n';// 7.122
}