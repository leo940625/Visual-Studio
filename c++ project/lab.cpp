#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int & r = a;
    string name = "sssss";
    string & c = name;
    cout << r << endl;
    cout << &name << endl;
    cout << r << endl;
    int * p; //宣告p這個指標
    p = &a; // 將p指標指向變數a所在的記憶體位址(ex:0x0000ff)
    *p = 10; //將值賦予p指標指向的記憶體空間
    cout << *p << endl;
    return 0; 
}