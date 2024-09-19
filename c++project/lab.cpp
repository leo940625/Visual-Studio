#include <iostream>
using namespace std;

template<typename T, typename G>
G add(T a, T b){
	G res = a+b;// G到底是甚麼型態?
    return res;
}
int main(){
    double d_a = 0.1, d_b = 7.022;
    cout << add<double, double>(d_a, d_b) << '\n';
    cout << add<double, int>(d_a, d_b) << '\n';
    cout << add<int, double>(d_a, d_b) << '\n';
}