#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{   
    int x;
    while (cin >> x) {
     string out;
     for (int i = floor(log2(x)); i >= 0; i--)
     {  
       if(x-pow(2,i) >= 0)
       {
         out += "1";
         x -= pow(2,i);
       }
       else
       {
         out += "0";
       }       
     }   
     cout << out << endl;  
     }
    // Detect end of file
     if (cin.eof()) {
        return 0;
     } 
}
 