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
    int * p; //�ŧip�o�ӫ���
    p = &a; // �Np���Ы��V�ܼ�a�Ҧb���O�����}(ex:0x0000ff)
    *p = 10; //�N�Ƚᤩp���Ы��V���O����Ŷ�
    cout << *p << endl;
    return 0; 
}